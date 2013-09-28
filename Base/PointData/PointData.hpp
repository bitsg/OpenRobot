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

	/*
	Perform actual coordinate transform
	*/
	void performTransform(vector<Point<T> > src, vector<Point<T> >& dst, COORDINATE_CONVERSION conversion_type)
	{

		Point<T> temp;
		switch(conversion_type)
		{
			//Conversion from XYZ to RAE
			case 0:

				for(int i = 0; i < src.size() ; i++)
				{
					temp.data[0] = sqrt(pow(src[i].data[0],2),pow(src[i].data[1],2),pow(src[i].data[2],2));
					temp.data[1] = acos(src[i].data[2]/temp.data[0]);
					temp.data[2] = atan(src[i].data[1] / src[i].data[0]);
					dst.push_back(temp);
				}
				break;

			//Conversion from RAE to XYZ
			case 1:

				for(int i = 0; i < src.size() ; i++)
				{
					temp.data[0] = src[i].data[0] * sin(src[i].data[1]) * cos(src[i].data[2]);
					temp.data[1] = src[i].data[0] * sin(src[i].data[1]) * sin(src[i].data[2]);
					temp.data[2] = src[i].data[0] * cos(src[i].data[1]);
					dst.push_back(temp);
				}
				break;
				
			default :
				cerr <<"Conversion Type Not Supported" << endl;
		}
	}

public:


	PointSet()
	{
		type = XYZ; //XYZ is the default coordinate system
	}
	

	/*
	To transform coordinates of a PointSet and store the result in a new PointSet
	*/
	void coordinateTransform(PointSet<T>& dst, COORDINATE_CONVERSION conversion_type)
	{
		//Check the src and dst types before converting
		if(conversion_type == 0 && this.type != 0)
		{	
			cerr << "Source PointSet is not XYZ." << endl;
			return;
		}
		else if(conversion_type == 1 && this.type != 1)
		{
			cerr << "Source PointSet is not REA." << endl;
			return;
		}

		performTransform(this.points, dst.points, conversion_type);
	}


	/*
	To transform coordinates of the PointSet and store it in the same PointSet
	*/
	void coordinateTransform(COORDINATE_CONVERSION conversion_type)
	{
		//Check destination System
		if(conversion_type == 0 && this.type == 1)
			return; //No conversion
		if(conversion_type == 1 && this.type == 0)
			return; //No Conversion

		if(conversion_type == 0 && this.type != 0)
		{
			cerr << "Source PointSet is not XYZ." << endl;
			return;
		}

		else if(conversion_type == 1 && this.type != 1)
		{
			cerr << "Source PointSet is not RAE." << endl;
			return;
		}

		performTransform(this.points, &this.points, conversion_type);
	}

	/*
	Return the size of the PointSet
	*/
	int size()
	{
		return points.size();
	}
	/*
	Returns the type of coordinate system
	*/
	POINT_COORDINATE_TYPE getType()
	{
		return type;
	}

};

#endif
