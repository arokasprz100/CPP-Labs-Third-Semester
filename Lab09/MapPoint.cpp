#include "MapPoint.h"
#include <iostream>
#include <cmath>


void MapPoint::set_latitude(double new_latitude)
{
	latitude = new_latitude;
}

void MapPoint::set_longitude(double new_longitude)
{
	longitude = new_longitude;
}

double MapPoint::get_latitude()
{
	return latitude;
}

double MapPoint::get_longitude ()
{
	return longitude;
}

void MapPoint::print() const
{
	//Point: (19.9383, 50.0614)
	std::cout<<"Point: ("<<latitude<<", "<<longitude<<")"<<std::endl;
}

void MapPoint::set_coordinates (double new_lat, double new_long)
{
	latitude = new_lat;
	longitude = new_long;
}

MapDistance MapPoint::distance(const MapPoint& otherPoint)
{
	MapDistance newDistance(fabs(this->latitude - otherPoint.latitude) , fabs(this->longitude  - otherPoint.longitude), global_id);

	return newDistance;
}

const MapPoint& MapPoint::farthest(const MapPoint& one, const MapPoint& other)
{
	MapDistance distance1 = distance(one);
	MapDistance distance2 = distance(other);
	double dist1 = sqrt(pow(distance1.get_lat(),2) + pow(distance1.get_lon(), 2));
	double dist2 = sqrt(pow(distance2.get_lat(),2) + pow(distance2.get_lon(), 2));

	if (dist1>dist2)
		return one;
	else
		return other;
}

MapPoint MapPoint::half_way_to (const MapPoint& onePoint)
{
	MapPoint newPoint;
	newPoint.set_latitude ( (latitude + onePoint.latitude)/2 );
	newPoint.set_longitude ( (longitude + onePoint.longitude)/2 );
	return newPoint;


}