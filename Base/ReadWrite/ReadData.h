/*

This file contains all the functions for reading data from a file.

TODO : Add support for PCD and PLY formats

*/

#ifndef _READDATA_H_
#define _READDATA_H_

#include "OpenRobot/Base/Base.h"
#include "OpenRobot/Base/PointData/PointData.h"

using namespace std;

/*
Read data from a text file

HEADER:
points <number_of_points>
*/

template< typename T>
void readFromText(PointSet<T>&);

#endif