/**
* @file Sdl.h
* Le fichier contient une classe qui gere tout le rendu, Il garde egalement une trace des parametres lies au rendu
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/


#ifndef SDL_H_
#define SDL_H_
#include <iostream>
#include <SDL.h> 
#include <cmath>
#include "point3d.h"
#pragma once
/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */
namespace ensiie {
	
/*!
 * @class Sdl
 * @brief La classe permet de realiser le rendu du cube 3D
 *
 * Tous type de tracage, la couleur, la rotation faite a l'objet Cube 3D en utilisant la bibliotheque SDL
 */
class Sdl {
    public:
    	//! creer une fenetre avec la position, les dimensions et les indicateurs specifies
        SDL_Window* window;
        //! creer un pointeur renderer d'un type structure qui contient un etat de rendu
        SDL_Renderer* renderer;
        //! constructeur par defaut de la classe
        Sdl();
        //! constructeur de la classe prenant 3 arguments de type string ainsi unsigned int
        Sdl(std::string name, unsigned int width, unsigned int height);
        //! fonction qui permette de definir une couleur de la fenetre 
        void clearScreen();
        //! fonction qui permette de tracage des lignes dans le fenetre deja definit
        void drawLine(SDL_Point p1, SDL_Point p2);
        //! fonction qui permette de realiser l'actualisation de la fenetre
        void updateScreen();
        //! fonction qui permette de detruire et sortir de la fenetre
        void quit();
};

}

#endif
