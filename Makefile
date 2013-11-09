CC     = gcc
CFLAGS = -Wall -I./include
CPPFLAGS = -g 
LDFLAGS = 
TARGET  = practice
SOURCES = $(shell echo ./src/*.cpp)
HEADERS = $(shell echo ./include/*.h)
OBJECTS = $(SOURCES:.cpp=.o)
LIBS = -lstdc++

all: $(TARGET)

%.o : %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(TARGET)

clean:
	rm -f ./src/*.o $(TARGET)

