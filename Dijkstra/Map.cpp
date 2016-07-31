#include "Map.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

Map::Map(string filename){

	/*
	 * Get input for the Map, which is formatted as follows
	 * 
	 * city-name x-coordinate y-coordinate
	 *
	 * Example:
	 * city1 1 1
	 * city2 1 5
	 * city3 3 2
	 */
	fstream file(filename);
	while (file.good()){
		string line;
		getline(file, line);
		stringstream ss(line);

		string name;
		string x;
		string y;

		ss >> name >> x >> y;
		int xCoor = atoi(x.c_str());
		int yCoor = atoi(y.c_str());

		City * city = new City(name, xCoor, yCoor);
		cities.push_back(city);
	}
	file.close();

    /* 
	 * Create adjacency list
	 */
	for (int i = 0; i < cities.size(); i++){
	
		/*
	     * Cannot add multiple cities in the same direction away from a city
		 * Keep track of the closest one in each direction
		 */
		City * up = NULL;
		City * down = NULL;	
		City * left = NULL;
		City * right = NULL;

		/*
		 * Loop through each city and check if there is a path connecting the two cities
		 * If a path exists, determine which direction it is in, and only update the closest city for that direction if
		 * the stored city in that direction is further than the current city being examined or NULL
		 */
	        for (int j = 0; j < cities.size(); j++){
        		if (i != j && cities[i]->getXCoor() == cities[j]->getXCoor()){
				if (cities[i]->getYCoor() < cities[j]->getYCoor()){
					if (up == NULL) up = cities[j];
					else if (cities[j]->getYCoor() < up->getYCoor()) up = cities[j];
				}
				else if(cities[i]->getYCoor() > cities[j]->getYCoor()) {
					if (down == NULL) down = cities[j];
					else if (cities[j]->getYCoor() > down->getYCoor()) down = cities[j];
				}
	        	}
			else if (i != j && cities[i]->getYCoor() == cities[j]->getYCoor()){
				if (cities[i]->getXCoor() < cities[j]->getXCoor()){
                                        if (right == NULL) right = cities[j];
					else if (cities[j]->getXCoor() < right->getXCoor()) right = cities[j];
                                }
                                else if (cities[i]->getXCoor() > cities[j]->getXCoor()) {
                                        if (left == NULL)  left = cities[j];
					else if (cities[j]->getXCoor() > left->getXCoor()) left = cities[j];
                                }

			}
		}

		/*
		 * If the closest city was found in a particular direction, add to the adjacency list for that city
		 */
		if (up) cities[i]->addAdjacent(up);
                if (down) cities[i]->addAdjacent(down);
                if (left) cities[i]->addAdjacent(left);
                if (right) cities[i]->addAdjacent(right);

        }

}

/*
 * Searches for a city and returns a pointer to the city
 * Returns NULL if the city does not exist in the map
 */
City * Map::findByName(string cityName){
	for (int i = 0; i < cities.size(); i++){
		if (cities[i]->cityName == cityName) return cities[i];
	}
	return NULL;
}

/*
 * Dijkstra's Shortest Path Algorithm
 */
vector<City*> Map::shortestPath(City * start, City * dest) {

	// Create the final path vector of the shortest path
	vector<City*> path;

	// Check that the start and dest are on the map, return empty vector of cities if one does not exist on the map 
	if (findByName(start->getName()) == NULL || findByName(dest->getName()) == NULL) return path;

	// Create 3 vectors: Unvisited nodes, Distance values, previous nodes
	vector<int> notVisited;
	vector<unsigned int> values;
	vector<City*> previous;

	// Start exploring at the start
	City * current = start;

	// Fill each node with "Infinity", set each previous to NULL, and mark each as not visited
	for (int i = 0; i < cities.size(); i++){
		values.push_back(-1);
		previous.push_back(NULL);
		notVisited.push_back(1);
	}

	// Update the start city's distance value to 0
	for (int i = 0; i < cities.size(); i++){
		if (cities[i]->getName() == current->getName()){
			values[i] = 0;
			break;
		}
	}

	
	// Loop until dest is found or return if no path exists
	while (current != dest){

		// Go through all adjacents and update the distance values and previous cities
		for (auto adj : current->getAdjacent()){
			int adjIndex = -1;	// Index of adjacent city in vector
			int currentIndex = -1;	// Index of current city in vector

			for (int k = 0; k < cities.size(); k++){
				if (notVisited[k] && cities[k]->getName() == adj->getName()) {
					adjIndex = k;
				}
				else if (notVisited[k] && cities[k]->getName() == current->getName()){
					currentIndex = k;
				}
			}	
		
			// Only update the distance values and previous values if the adjacent city hasn't been visited yet	
			if (adjIndex != -1 || currentIndex != -1){	
				if (values[currentIndex] + directDistance(current, adj) < values[adjIndex]){
					values[adjIndex] = values[currentIndex] + directDistance(current, adj);
					previous[adjIndex] = current;
				}
			}
		}
	
		// Update the city as visited in the notVisited vector	
		for (int i = 0; i < cities.size(); i++){
			if (cities[i]->getName() == current->getName()){
				notVisited[i] = 0;
				break;
			}	
		}
		
		// Find index of the lowest distance value
		unsigned int lowest = -1;
		int index = -1;
		for (int i = 0; i < values.size(); i++) {
			if (values[i] < lowest && notVisited[i]) {
				lowest = values[i];
				index = i;
			}
		}	

		// If there is a non-infinity distance value that hasn't been visited yet, explore it, otherwise return (no path exists between start and dest)
		if (index != -1) current = cities[index];
		else return path;
	}
	
	// Build shortest path starting with the last city (pointed to by current since it was the last city visited in the while loop above)
	City * last = current;
	while (last){
		path.push_back(last);
		for (int i = 0; i < cities.size(); i++){
			if (cities[i]->getName() == last->getName()) {
				last = previous[i];
				break;
			}
		}	
	}

	// Reverse the path list
	for (int i = 0; i < path.size()/2; i++){
		swap(path[i], path[path.size()-1-i]);
	}
	
	return path;
}

/*
 * Calculates the path distance by calling shortestPath and returning the sum of distances along the path
 * Returns 0 if start or dest is not on the map OR if the start city is the destination city
 */
unsigned int Map::pathDistance(City * start, City * dest){

	if (findByName(start->getName()) == NULL || findByName(dest->getName()) == NULL) return 0;
	else if (start->getName() == dest->getName()) return 0;

	int dist = 0;
	
	vector<City*> path = shortestPath(start, dest);
	if (path.size() == 0) return -1;

	for (int i = 0; i < path.size()-1; i++){
		dist += directDistance(path[i], path[i+1]);
	}
	return dist;
}

/*
 * Helper method for shortestPath
 * Assumes there is a direct path between start and dest and calculates the distance
 */
unsigned int Map::directDistance(City * start, City * dest){
	if (start->getXCoor() == dest->getXCoor()){
        	return abs(start->getYCoor() - dest->getYCoor());
        }
        else {
                return abs(start->getXCoor() - dest->getXCoor());
        }
}

Map::~Map(){
	for (int i = 0; i < cities.size(); i++){
		delete cities[i];
	}
}

