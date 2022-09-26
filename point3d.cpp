/**
* @file point3D.cpp
* Classe qui definit point 3d definit par x, y et z et immplementation des constructeurs, operateurs.
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/


#include "point3d.h"
#include <iostream>
#include <cmath>
/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */

using namespace ensiie ;

// constructeur par défaut

point3d::point3d()
{
	x = 0;
	y = 0;
	z = 0;
}

// constructeur contient 3 arguments

point3d::point3d(double ix, double iy, double iz)
{
	x = ix;
	y = iy;
	z = iz;
}

// destructeur de la classe

point3d::~point3d()
{
}
// surcharge de l'operateur

point3d & point3d::operator= (const point3d & p){
		x = p.x;
		y = p.y;
		z = p.z;
		return *this;
	}
// surcharge de l'operateur

point3d operator+ (const point3d & p , const point3d & pp) 	{return point3d(p.x + pp.x, p.y + pp.y, p.z + pp.z); }
point3d operator- (const point3d & p , const point3d & pp) 	{return point3d(p.x - pp.x, p.y - pp.y, p.z - pp.z); }
point3d operator* (double s , const point3d & p) 	{return point3d(p.x * s , p.y * s, p.z * s);}
// surcharge de l'operateur

std::ostream& operator<< (std::ostream& os, const point3d &p){
	    os << "Les coordonnées du point :";
		os << "(" << p.x << "," << p.y << "," << p.z << ")";
		return os;
	}





