/*
This file contains the implementation of the PointSet class 

Date: 11/08/2013
*/

#include <base/PointData/pointdata.h>

template< typename T >
PointSet<T>::PointSet()
{
	type = 0; //XYZ is the default coordinate system
}

template< typename T >
void PointSet<T>::coordinateTransform(COORDINATE_CONVERSION conversion_type)
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

template< typename T >
void PointSet<T>::coordinateTransform(PointSet<T>& dst, COORDINATE_CONVERSION conversion_type)
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

template< typename T >
void PointSet<T>::performTransform(vector< Point<T> > src, vector< Point<T> > &dst, COORDINATE_CONVERSION conversion_type)
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

template< typename T >
int PointSet<T>::size()
{
	return points.size();
}

template< typename T >
POINT_COORDINATE_TYPE PointSet<T>::getType()
{
	return type;
}
