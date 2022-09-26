/**
* @file Cube3D.h
* Definition de la classe Cube tout en utilisant la classe point3d pour avoir les coordonnees des sommets du cube
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/
#ifndef CUBE3D_H_
#define CUBE3D_H_
#include <iostream>
#include <SDL.h> 
#include "point3d.h"
#include "Sdl.h"
#include <cmath>
#pragma once
/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */
namespace ensiie{

/*!
 * @class Cube3D
 * @brief La classe permet d'implementer un cube d'espace 3D
 *
 * Definition de la classe Cube tout en utilisant la classe point3d pour avoir les coordonnees des sommets du cube
 */

class Cube3D {
	
    public:
    	//! donnee membre indiquant le degre de rotation
        unsigned int degturnt;
    	//! creation d'un pointeur points qui va stocker les differents coordonnees des sommets du cube.
        point3d* points;
        //! creation des 8 points qui correspondent aux sommets du cube 
        point3d newpoints[8];
        //! creation d'un pointeur de type SDL point 
        SDL_Point* p2d;
        //! definition des facteurs d'echelle
        unsigned int scalefactorx, scalefactory;
        
        //! constructeur de la classe prenant 3 arguments de type point3d et unsigned int 
        Cube3D(point3d ps[8], unsigned int sfx, unsigned int sfy);
        //! pointeur qui fait la correspendance et la conversion d'un plan 3d au 2d sur la cmd 
        SDL_Point* convertTo2D(unsigned int scalefactorx, unsigned int scalefactory);
        //! fonction void qui permet le tracage des aretes ainsi les diagonales du cube
        void renderCube(Sdl);
        //! fonction void permet de definir une couleur pour le cube 
        void renderCube_color_1(Sdl);
         //! fonction void permet de definir une couleur pour le cube 
        void renderCube_color_2(Sdl);
         //! fonction void permet de definir une couleur pour le cube 
        void renderCube_color_3(Sdl);
         //! fonction void qui fait la rotation du cube suivant l'axe XZ
        void rotateXZ();
         //! fonction void qui fait la rotation du cube suivant l'axe XZ opposee
        void rotateXZ_oppo();
         //! fonction void qui fait la rotation du cube suivant l'axe YZ
        void rotateYZ();
        
};
}

#endif
