#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <string>

//Programmer: Andrew Morgan
//Date: November 2020
//Purpose: A collection of constants used by an event-driven simulation of
//cars flowing through an intersection managed by a traffic light.

//Event type constants
const int EVENT_UNKNOWN = -1;
const int EVENT_ARRIVE_EAST = 0;
const int EVENT_ARRIVE_WEST = 1;
const int EVENT_ARRIVE_NORTH = 2;
const int EVENT_ARRIVE_SOUTH = 3;
const int EVENT_CHANGE_GREEN_EW = 4;
const int EVENT_CHANGE_YELLOW_EW = 5;
const int EVENT_CHANGE_GREEN_NS = 6;
const int EVENT_CHANGE_YELLOW_NS = 7;

//Car-related constants
const int CAR_ID_NOT_SET = -1;

//Direction-related constants
const std::string EAST_DIRECTION = "East";
const std::string WEST_DIRECTION = "West";
const std::string NORTH_DIRECTION = "North";
const std::string SOUTH_DIRECTION = "South";

//Traffic light state constants
const int LIGHT_GREEN_EW = 1;
const int LIGHT_YELLOW_EW = 2;
const int LIGHT_GREEN_NS = 3;
const int LIGHT_YELLOW_NS = 4;


const int START_TIME = 0;

const int UNIFORM_MIN = 1;
const int UNIFORM_MAX = 100;


#endif //_CONSTANTS_H_
