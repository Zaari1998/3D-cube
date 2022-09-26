/**
* @file Sdl.cpp
* Le fichier contient une classe qui fait l'implementation et gere tout le rendu, Il garde egalement une trace des parametres lies au rendu
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/

#include <iostream>
#include <SDL.h> 
#include "Sdl.h"
#include <cmath>

/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */
using namespace std;
using namespace ensiie ;

Sdl::Sdl(string name, unsigned int width, unsigned int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
            
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        cout << "Problem creating window: " << SDL_GetError() << endl;
    }
    if (renderer == NULL) {
        cout << "Problem creating renderer: " << SDL_GetError() << endl;
    }
}

void Sdl::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
    SDL_RenderClear(renderer);
}

void Sdl::drawLine(SDL_Point p1, SDL_Point p2) {
    SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
}

void Sdl::updateScreen() {
    SDL_RenderPresent(renderer);
}

void Sdl::quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}



