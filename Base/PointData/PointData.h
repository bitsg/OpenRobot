/*

This file contains all the basic data structures required for storing data such as PointSets, Paths, Clusters etc..

Date: 11/08/2013

*/

#ifndef _POINTDATA_H_
#define _POINTDATA_H_

#include "OpenRobot/Base/Base.h"

using namespace std;


//Store the type of Co-ordinate System
enum POINT_COORDINATE_TYPE
{
	XYZ, //XYZ Co-ordinate System
	REA //Range, Azimuth, Elevation Co-ordinate System
};

enum COORDINATE_CONVERSION
{
	XYZ2REA,
	REA2XYZ
};

//Basic structure to store a Point
template< typename T >
struct Point
{
	T data[3];
};


//Class to store a collection Points
template< typename T >
class PointSet
{

private:
	
	vector< Point<T> > points;
	POINT_COORDINATE_TYPE type;

	void performTransform(vector<Point<T> >, vector<Point<T> >&, COORDINATE_CONVERSION);

public:

	PointSet<T>();

	/*
	Static function for performing coordinate transformations on any two PointSets
	Function can be used without any instance of the class
	*/

	void coordinateTransform(PointSet<T>&, COORDINATE_CONVERSION);

	/*
	To transform coordinates of the PointSet
	*/
	void coordinateTransform(COORDINATE_CONVERSION);

	int size();
	POINT_COORDINATE_TYPE getType();

};

#endif
