/**
* @file Cube3D.cpp
* Implementation de la classe Cube tout en utilisant la classe point3d pour avoir les coordonnees des sommets du cube
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*/

#include <iostream>
#include <SDL.h> 
#include "Cube3D.h"
#include <cmath>
/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */


using namespace ensiie ;

// constructeur de la classe 
Cube3D::Cube3D(point3d ps[8], unsigned int sfx, unsigned int sfy) {
    points = ps;
    for (unsigned int i = 0; i < 8; i++) newpoints[i] = points[i];
    degturnt = 0;
}

// conversion du 3d en 2d
SDL_Point* Cube3D::convertTo2D(unsigned int scalefactorx, unsigned int scalefactory) {
    p2d = new SDL_Point[8];
    for (unsigned int i = 0; i < 8; i++) {
        p2d[i] = {
            (int) round((1 + (newpoints[i].x / newpoints[i].z))/2 * scalefactorx), 
            (int) round((1 + (newpoints[i].y / newpoints[i].z))/2 * scalefactory)
        };
    }
    return p2d;
}

    void Cube3D::renderCube_color_1(Sdl renderer) {
         SDL_SetRenderDrawColor(renderer.renderer,255,255,0,0);
		 }
    void Cube3D::renderCube_color_2(Sdl renderer) {
         SDL_SetRenderDrawColor(renderer.renderer,0,255,255, 0);
		 }
    
	void Cube3D::renderCube_color_3(Sdl renderer) {
         SDL_SetRenderDrawColor(renderer.renderer,0,250,0,0);
		 }
    
    void Cube3D::renderCube(Sdl renderer){
	   // dessiner les aretes
    for (unsigned int i = 0; i < 4; i++) {
		renderer.drawLine(p2d[i], p2d[(i+3) % 6]);
        renderer.drawLine(p2d[i+4], p2d[(i+1) % 4 + 4]);
        renderer.drawLine(p2d[i], p2d[i+4]);
        renderer.drawLine(p2d[i], p2d[(i+1) % 4]); 
       }
       
       // dessiner les aretes
       for (unsigned int i = 0; i < 4; i++){
       	renderer.drawLine(p2d[i], p2d[(i+1) % 6]);	
       	renderer.drawLine(p2d[i+4], p2d[(i+1) % 6]); 
       }
       
       // dessiner les diagonales
       for (unsigned int i = 0; i < 2; i++)
         renderer.drawLine(p2d[i+1], p2d[(i+3)%2]);
       
       // dessiner les dessiner les diagonales
       for (unsigned int i = 0; i < 1; i++) 
       	renderer.drawLine(p2d[i+6], p2d[(i)%6 + 4]);      
}

// fonction de rotation pour le cube suivant XZ
void Cube3D::rotateXZ() {
    double orgin[2] = {(points[0].x + points[6].x)/2, (points[0].z + points[6].z)/2};
    degturnt++;
    for (unsigned int i = 0; i < 8; i++) {
        newpoints[i].x = ((points[i].x-orgin[0])*cos(degturnt*M_PI/180)) - ((points[i].z-orgin[1])*sin(degturnt*M_PI/180))+orgin[0];
        newpoints[i].z = ((points[i].x-orgin[0])*sin(degturnt*M_PI/180)) + ((points[i].z-orgin[1])*cos(degturnt*M_PI/180))+orgin[1];
        if (degturnt == 360) degturnt = 0;
    }
}
// fonction de rotation pour le cube suivant XZ opposee

void Cube3D::rotateXZ_oppo() {
    double orgin[2] = {(points[0].x + points[6].x)/2, (points[0].z + points[6].z)/2};
    degturnt++;
    for (unsigned int i = 0; i < 8; i++) {
        newpoints[i].x = ((points[i].x-orgin[0])*cos(degturnt*M_PI/(-180))) - ((points[i].z-orgin[1])*sin(degturnt*M_PI/(-180)))+orgin[0];
        newpoints[i].z = ((points[i].x-orgin[0])*sin(degturnt*M_PI/(-180))) + ((points[i].z-orgin[1])*cos(degturnt*M_PI/(-180)))+orgin[1];
        if (degturnt == 360) degturnt = 0;
    }
}
// fonction de rotation pour le cube suivant YZ

void Cube3D::rotateYZ() {
    double orgin[2] = {(points[0].y + points[6].y)/2, (points[0].z + points[6].z)/2};
    degturnt++;
    for (unsigned int i = 0; i < 8; i++) {
        newpoints[i].y = ((points[i].y-orgin[0])*cos(degturnt*M_PI/(-180))) + ((points[i].z-orgin[1])*sin(degturnt*M_PI/(-180)))+orgin[0];
        newpoints[i].z = -((points[i].y-orgin[0])*sin(degturnt*M_PI/(-180))) + ((points[i].z-orgin[1])*cos(degturnt*M_PI/(-180)))+orgin[1];
        if (degturnt == 360) degturnt = 0;
    }
}



