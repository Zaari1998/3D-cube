/**
* @file point2D.h
* Classe qui definit point 2d definit par x et y et immplementation des constructeurs, operateurs.
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/

#ifndef POINT2D_H_
#define POINT2D_H_
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
 * @class point2d
 * @brief La classe permet d'implementer un point 2d
 *
 * definir le point 2d par 2 coordonnes geometriques x, y ainsi les constructeurs et les operateurs adjacents
 */
class point2d{

	public:	
	/*! Coordonnees du point 2d */
	int x, y; 
	//! constructeur par d�faut de la classe
	point2d(); 
	//! constructeur de la classe contenant 2 arguments qui sont les coordonn�es du point 2d
	point2d(int, int);
	//! destructeur de la classe	
	~point2d();
	//! op�rateur = affectation des coordonn�es d'un point � un autre point 
	point2d & operator=(const point2d & ); 

};
	// surcharge des op�rateurs
	/*!
	 * @brief Surcharge de l'operateur +
	 *
	 * addition de deux points 2d
	 */
    point2d operator+ (const point2d & , const point2d &); 
    /*!
	 * @brief Surcharge de l'operateur -
	 *
	 * soustraction de deux points 2d
	 */
	point2d  operator- (const point2d & , const point2d &); 
	/*!
	 * @brief Surcharge de l'operateur *
	 *
	 * multiplication de deux points 2d
	 */
	
    point2d operator* (double, const point2d &); 
    /*!
	 * @brief Fonction d'affichage
	 *
	 * Affichage x, y d'un point 
	 */
    std::ostream& operator<< (std::ostream&, const point2d &); 

}


#endif

