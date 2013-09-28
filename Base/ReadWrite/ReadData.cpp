/*
This file contains the implementations of functions for reading data

*/

#include "OpenRobot/Base/ReadWrite/ReadData.h"

template< typename T >
void readFromText(char *filename, PointSet<T>& dst)
{
	FILE *f = fopen(filename,"r");
	
}