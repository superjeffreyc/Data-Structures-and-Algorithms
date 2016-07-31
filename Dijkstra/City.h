#ifndef CITY_H
#define CITY_H

#include <list>
#include <string>

class City {

private:
	int xCoor;
	int yCoor;
	std::list<City*> adjList;

public:
	std::string cityName;
	City(std::string cityName, int xCoor, int yCoor);
	std::string getName();
	int getXCoor();
	int getYCoor();
	std::list<City*> getAdjacent();
	bool operator<(City &c);
	void addAdjacent(City * city);
};

#endif
