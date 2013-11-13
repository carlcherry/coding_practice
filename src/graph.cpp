/*
 * graph.cpp
 *
 *  Created on: 2013-01-23
 *      Author: carl
 */
#include "graph.h"
#include "ccutilities.h"

#include <set>
#include <iostream>
#include <deque>

namespace cc {

edge::~edge()
{

}

void ccvertex::add_edge(std::string vertexName)
{
    // First ensure this edge does not already exist
    for( std::list<cc::edge*>::iterator i = _edges.begin(); i != _edges.end(); i++)
    {
        if ((*i)->_edgeLabel == vertexName)
            return; // just return now and don't re-add
    }
    _edges.push_back(new cc::edge(vertexName));
}

ccvertex::~ccvertex()
{
    for (std::list<cc::edge*>::iterator i = _edges.begin(); i != _edges.end(); i++)
    {
        delete *i;
    }
}

int ccvertex::edge_count()
{
    int count = 0;
    for (std::list<cc::edge*>::iterator i = _edges.begin(); i != _edges.end(); i++)
    {
        count++;
    }
    return count;
}

ccgraph::ccgraph()
{

}
ccgraph::~ccgraph()
{

}
int ccgraph::num_vertices()
{
    return _vertices.size();
}
int ccgraph::num_edges()
{
    int count = 0;
    for( std::map<std::string, ccvertex*>::iterator iter = _vertices.begin(); iter != _vertices.end(); iter++)
    {
        count += iter->second->edge_count();
    }
    return count;
}

void ccgraph::insert_edge(const char* pVertex1, const char* pVertex2, bool directed)
{
    // Since we are adding an edge between vertex 1 and 2 make sure that
    // both vertices are in our graph
    // 1. Loodk for vertex 1
    std::map<std::string, ccvertex*>::iterator iter = _vertices.find(pVertex1);
    ccvertex *v1 = NULL;
    ccvertex *v2 = NULL;
    if (iter == _vertices.end())
    {
        // Add this vertex
        v1 = new ccvertex(pVertex1);
        _vertices[pVertex1] = v1;
    }
    else
        v1 = iter->second;

    // 2. Look for vertex 2
    iter = _vertices.find(pVertex2);
    if (iter == _vertices.end())
    {
        // Add this vertex
        v2 = new ccvertex(pVertex2);
        _vertices[pVertex2] = v2;
    }
    else
        v2 = iter->second;

    // Now add the edge - perhas 2 edges if undirected
    v1->add_edge(pVertex2);
    if (!directed)
        v2->add_edge(pVertex1);
}

std::map<std::string,std::string> ccgraph::bfsloop(std::string start, std::string end)
{
    if (num_vertices() == 0)
        throw("no vertices");

    // We need to keep track of nodes discovered processed and also parent nodes to back track
    std::set<std::string> processed;
    std::set<std::string> discovered;
    std::map<std::string, std::string> parent;

    // Let's locate the start node - it we can't find it then quit now
    std::map<std::string, ccvertex*>::iterator iter = _vertices.find(start);
    if (iter == _vertices.end())
        return parent;

    // Lets also find the end node, if it can't be found then quite,
    // otherwise keep a pointer to it so we can know when we are done
    ccvertex *vEnd = 0;
    iter = _vertices.find(end);
    if (iter == _vertices.end())
        return parent;
    else
        vEnd = iter->second;

    // Since this is a breadth first search we will use a queue so
    // we properly work through all the children of one node before
    // going down to the grandchildren
    std::deque<std::string> _q;

    // Start by pushing the start node on the queue
    _q.push_back(start);

    // Until we run out of nodes, or find the end pop the next item
    // from the queue
    while (!_q.empty())
    {
        std::string vName = _q.front();
        _q.pop_front();

        // Find this vertex in our graph
        iter = _vertices.find(vName);
        if (iter == _vertices.end())
            throw("Could not find vertex in graph");
        ccvertex *v = iter->second;

        // Did we find the vertex?
        if (v == vEnd)
        {
            // We are done - return the parent mapping
            return parent;
        }

        // Get all the edges associated with this vertex and add any
        // adjacent vertices to the queue
#ifdef CPP_11
        for( cc::edge *pEdge : v->_edges)
        {
#else
            std::list<cc::edge*>::iterator i;
            for (i = v->_edges.begin(); i != v->_edges.end(); i++)
            {
                cc::edge *pEdge = *i;
#endif
                std::string adjVertex = pEdge->_edgeLabel;

                std::set<std::string>::iterator processedIter = processed.find(pEdge->_edgeLabel);
                std::set<std::string>::iterator discoveredIter = discovered.find(pEdge->_edgeLabel);

                if (discoveredIter == discovered.end())
                {
                    // This is our first visit to this vertex, add it to the queue,
                    // mark it as discovered, and set its parent
                    _q.push_back(pEdge->_edgeLabel);
                    discovered.insert(pEdge->_edgeLabel);
                    parent[pEdge->_edgeLabel] = vName;
                }
                else if (processedIter == processed.end())
                {
                    // We have not processed this vertex yet, so maybe
                    // do some processing on the vertex?  At the very least
                    // mark it as processed
                    processed.insert(pEdge->_edgeLabel);
                    // In our case the only thing we will do is quick if this vertex
                    // is the one we are looking for - the parent should already be set
                    if (pEdge->_edgeLabel == vEnd->_label)
                    {
                        std::cout << "Found end" << std::endl;
                        return parent;
                    }
                }
            }
        }

        return parent;
    }

    void print_path(std::map<std::string,std::string>& parent, std::string start, std::string end)
    {
        // We have to work backwards from the end and trace back through each parent
        std::map<std::string,std::string>::iterator i = parent.find(end);
        if (i == parent.end())
        {
            std::cout << "Unable to find node in path: " << end << std::endl;
            return;
        }
        while( i->second != start)
        {
            std::cout << "Child=" << i->first << ", parent=" << i->second << std::endl;
            i = parent.find(i->second);
        }
    }

    void testMaze()
    {
        int m[10][10] =
        {   {0,    1,    1,    0,    1,    1,    1,    1,    0,    1 },
                {0,    1,    0,    0,    0,    0,    1,    1,    1,    1 },
                {0,    1,    0,    0,    1,    0,    1,    1,    1,    1 },
                {0,    0,    0,    1,    1,    0,    1,    1,    1,    1 },
                {0,    1,    1,    1,    0,    0,    1,    0,    0,    1 },
                {1,    1,    1,    1,    0,    1,    1,    0,    0,    1 },
                {1,    1,    0,    1,    0,    0,    0,    0,    0,    1 },
                {1,    1,    0,    0,    1,    1,    1,    1,    0,    1 },
                {0,    1,    1,    0,    1,    1,    1,    1,    0,    1 },
                {0,    1,    1,    1,    1,    1,    1,    1,    0,    0 }
        };

        // Create a graph out of the maze
        cc::ccgraph _graph;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                // Check to see if this location is one that is valid
                if (m[i][j] == 0)
                {
                    // Create a label name for this location
                    char currentLocation[6];
                    char neighbor[6];
                    sprintf(currentLocation, "(%d,%d)", i, j);

                    // We found a valid location - now see which direction is valid from here
                    // 1. Check left
                    if (i > 0 && m[i-1][j] == 0)
                    {
                        // Create a label for this location
                        sprintf(neighbor, "(%d,%d)", i - 1, j);;
                        _graph.insert_edge(currentLocation, neighbor, false);
                    }
                    // 2. Check right
                    if (i < 9 && m[i+1][j] == 0)
                    {
                        // Create a label for this location
                        sprintf(neighbor, "(%d,%d)", i + 1, j);;
                        _graph.insert_edge(currentLocation, neighbor, false);
                    }
                    // 3. Check up
                    if (j > 0 && m[i][j-1] == 0)
                    {
                        // Create a label for this location
                        sprintf(neighbor, "(%d,%d)", i, j - 1);;
                        _graph.insert_edge(currentLocation, neighbor, false);
                    }
                    // 4. Check down
                    if (j < 9 && m[i][j+1] == 0)
                    {
                        // Create a label for this location
                        sprintf(neighbor, "(%d,%d)", i, j + 1);
                        _graph.insert_edge(currentLocation, neighbor, false);
                    }
                }
            }
        }
        std::cout << "Maze vertices=" << _graph.num_vertices() << ", edges=" << _graph.num_edges() << std::endl;
        std::map<std::string,std::string> parent = _graph.bfsloop("(0,0)", "(9,9)");
        print_path(parent, "(0,0)","(9,9)");
    }

} // end namespace cc



