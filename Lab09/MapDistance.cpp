#include "MapDistance.h"
#include <iostream>

std::string global_id = "NY-POR";

void MapDistance::print() const 
{
	std::cout<<"Distance "<<id_name<<" ("<<lat_distance<<", "<<lon_distance<<")"<<std::endl;

}

MapDistance::MapDistance()
{
	lat_distance = 0.0;
	lon_distance = 0.0;
	id_name = "None";
}

double MapDistance::get_lat()
{
	return lat_distance;
}

double MapDistance::get_lon()
{
	return lon_distance;
}

MapDistance::MapDistance (double new_lat ,double new_lon, std::string new_id)
{
	lat_distance = new_lat;
	lon_distance = new_lon;
	id_name = new_id;
}