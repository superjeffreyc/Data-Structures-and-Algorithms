#include "City.h"

using namespace std;

City::City(string cityName, int xCoor, int yCoor) {
	this->cityName = cityName;
	this->xCoor = xCoor;
	this->yCoor = yCoor;
}

string City::getName(){
	return cityName;
}

int City::getXCoor(){
	return xCoor;
}

int City::getYCoor(){
	return yCoor;
}

list<City*> City::getAdjacent(){
	return adjList;	
}

bool City::operator<(City &c){
	return (this->cityName < c.cityName);
}

void City::addAdjacent(City * city){
	adjList.push_back(city);
}
