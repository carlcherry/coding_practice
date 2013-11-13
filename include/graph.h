/*
 * graph.h
 *
 *  Created on: 2013-01-23
 *      Author: carl
 */

#ifndef __CC_GRAPH_H_
#define __CC_GRAPH_H_

#include <string>
#include <list>
#include <map>

namespace cc {

void testMaze();

class edge
{
   std::string _edgeLabel;
   friend class ccgraph;
   friend class ccvertex;
public:
   edge(std::string edgeName) : _edgeLabel(edgeName) {}
   virtual ~edge();
};

class ccvertex
{
   friend class ccgraph;
public:
   std::string _label;
   std::list<cc::edge*> _edges;
   ccvertex(std::string name) : _label(name) {}
   void add_edge(std::string vertexName);
   virtual ~ccvertex();
   int edge_count();
};

class ccgraph
{
public:
   ccgraph();
   virtual ~ccgraph();

   void insert_edge(const char* pVertex1, const char* pVertex2, bool directed = true);
   int  num_vertices();
   int  num_edges();
   std::map<std::string,std::string> bfsloop(std::string start, std::string end);

private:
   std::map<std::string, ccvertex*> _vertices;
};

} // end namespace cc
#endif /* __CC_GRAPH_H_ */
