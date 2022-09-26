/**
* @file point3D.h
* Classe qui definit point 3d definit par x, y et z et immplementation des constructeurs, operateurs.
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/


#ifndef POINT3D_H_
#define POINT3D_H_
#include <iostream>
#include <cmath>
#pragma once

/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */
namespace ensiie{

/*!
 * @class point3d
 * @brief La classe permet d'implementer un point 3d
 *
 * definir le point 3d par 3 coordonnes geometriques x, y et z ainsi les constructeurs et les operateurs adjacents
 */
class point3d{

	public:	
	//! coordonnées du point 3d
	double x, y, z;	
	//! constructeur par défaut de la classe
	point3d(); 
	//! constructeur de la classe contenant 3 arguments qui sont les coordonnées du point 3d
	point3d(double, double, double); 
	//! destructeur de la classe	
	~point3d(); 
	//! opérateur = affectation des coordonnées d'un point à un autre point
	point3d & operator=(const point3d & ); 

};
	// surcharge des opérateurs
	/*!
	 * @brief Surcharge de l'operateur +
	 *
	 * addition de deux points 3d
	 */
    point3d operator+ (const point3d & , const point3d &); 
    /*!
	 * @brief Surcharge de l'operateur -
	 *
	 * soustraction de deux points 3d
	 */
	point3d  operator- (const point3d & , const point3d &); 
	/*!
	 * @brief Surcharge de l'operateur *
	 *
	 * multiplication de deux points 3d
	 */
    point3d operator* (double, const point3d &); 
      /*!
	 * @brief Fonction d'affichage
	 *
	 * Affichage x, y et z d'un point 
	 */
    std::ostream& operator<< (std::ostream&, const point3d &); 

}


#endif
