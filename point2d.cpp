/**
* @file point2D.cpp
* Classe qui definit point 2d definit par x et y et immplementation des constructeurs, operateurs.
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/

#include "point2d.h"
#include <iostream>
#include <cmath>
/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */
using namespace ensiie ;

// constructeur par défaut
point2d::point2d()
{
	x = 0;
	y = 0;
}

// constructeur contient 2 arguments
point2d::point2d(int ix, int iy)
{
	x = ix;
	y = iy;

}

// destructeur de la classe
point2d::~point2d()
{
}

// surcharge de l'operateur
point2d & point2d::operator= (const point2d & p){
		x = p.x;
		y = p.y;
		return *this;
	}

// surcharge de l'operateur
point2d operator+ (const point2d & p , const point2d & pp) 	{return point2d(p.x + pp.x, p.y + pp.y); }
point2d operator- (const point2d & p , const point2d & pp) 	{return point2d(p.x - pp.x, p.y - pp.y); }
point2d operator* (int s , const point2d & p) 	{return point2d(p.x * s , p.y * s);}

// surcharge de l'operateur
std::ostream& operator<< (std::ostream& os, const point2d &p){
	    os << "Les coordonnées du point :";
		os << "(" << p.x << "," << p.y << ")";
		return os;
	}





