#ifndef MAP_H
#define MAP_H

#include "Node.h"
#include <string>
#include <vector>

class Map {

private:
	std::vector<Node*> cities;
	std::vector<std::list<Node*>> adjList;
	unsigned int directDistance(Node * start, Node * dest);

public:
	Map(std::string filename);
	~Map();
	Node * findByName(std::string NodeName);
	std::vector<Node*> shortestPath(Node * start, Node * dest);
	unsigned int pathDistance(Node * start, Node * dest);
};

#endif
