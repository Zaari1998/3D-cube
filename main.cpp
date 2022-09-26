/**
* @file main.cpp
* Le fichier main du projet qui nous aide a l'execution du projet
*
* Pour la compilation du projet on a utilise la commande suivante sous Windows
*
*    g++ *.cpp -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
*
*    bin\prog.exe
* @author ZAARI Abdelouahab
* @author BOULIF Ikram
*
* La logique qu'on a suivi a l'interieur de la fonction main:
*
* 1- Tout d'abord on fait une instanciation des objets de la classe Cube3D
*
* 2- Utilisation de l'objet SDL pour la crÃ©ation de la fenÃªtre et l'affectation de sa couleur\\
*
* 3- CÃ©ation des variables event, done vont Ãªtre  utile dans notre boucle d'affichage\\
*
* 4- Instanciation des objets de la classe Cube3D\\
*
* 5- Affecter la rotation automatique aux diffÃ©rents cubes avec chacun d'eux a un sens de rotation different\\
*
* 6- Affecter chaque cube avec une couleur diffÃ©rente\\
*
* 7- ImplÃ©mentation d'une rotation automatique ainsi commandÃ©e par clavier en utilisant la fleche gauche, droite est haut du clavier\\
*
* 8- Finalement sortir et dÃ©truire la fenÃªtre SDL\\
*
*/
#define SCALEFACTORX WIDTH
#define SCALEFACTORY HEIGHT
#define WIDTH  1024
#define HEIGHT 512
#include <iostream>
#include <cmath>
#include <SDL.h> 
#include "Sdl.h"
#include "Cube3D.h"
#include "point3d.h"

/*Pour la compilation du projet on a utilisé la commande suivante sous Windows
    g++ *.cpp -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    bin\prog.exe  /*

/*!
 * @namespace ensiie
 *
 *	Espace de nommage utiliser pour notre projet
 */
using namespace ensiie ;


int main(int argc, char* args[]) {
    Sdl renderer("PAP projet ZAARI - BOULIF", WIDTH, HEIGHT);

    
    // Les points doivent être triés de telle sorte que les points adjacents les uns aux autres soient les suivants
    // Séparez également la face avant et la face arrière
    point3d points[8] = {
         {1, -1, 3}, { 1,  1, 3}, {-1,  1, 3}, {-1, -1, 3}, 
         {1, -1, 5}, { 1,  1, 5}, {-1,  1, 5}, {-1, -1, 5}
    }; 
    
    point3d points_[8] = {
         {1, -1, 5}, { 1,  1, 5}, {-1,  1, 5}, {-1, -1, 5}, 
         {1, -1, 7}, { 1,  1, 7}, {-1,  1, 7}, {-1, -1, 7}
    };
    
     point3d points_1[8] = {
        {1, -1, 3}, { 1,  1, 3}, {-1,  1, 3}, {-1, -1, 3}, 
         {1, -1, 5}, { 1,  1, 5}, {-1,  1, 5}, {-1, -1, 5}
    };


    Cube3D cube(points, SCALEFACTORX , SCALEFACTORY);
    /*
     instancier un deuxième objet de la classe Cube3D
    */
    Cube3D cube1(points_, SCALEFACTORX, SCALEFACTORY);
    /*
     instancier un troisième objet de la classe Cube3D
    */
    Cube3D cube2(points_1, SCALEFACTORX, SCALEFACTORY);
    
    renderer.clearScreen();
    SDL_Event event;
    bool done = false;
   
	/*Maintenir la touche r du clavier pour changer le sens de rotation du cube et la touche s pour changer la position de l'oeil
	de rotation du cube	*/
	
    while (!done) {
    	//Instanciation des objets de la classe Cube3D
        cube.convertTo2D(SCALEFACTORX+100, SCALEFACTORY+200);  
		cube1.convertTo2D(SCALEFACTORX-500, SCALEFACTORY-100);  
		cube2.convertTo2D(SCALEFACTORX+100, SCALEFACTORY-300);  
		
        // Rotation automatique du cube suivant l'axe XZ
        cube.renderCube_color_1(renderer);
        cube.renderCube(renderer);
        cube.rotateXZ();
        
        // Rotation automatique du cube1 suivant l'axe XZ oppo
        cube1.renderCube_color_2(renderer);
        cube1.renderCube(renderer);
        cube1.rotateXZ_oppo();
        
        // Rotation automatique du cube2 suivant l'axe YZ
        cube2.renderCube_color_3(renderer);
        cube2.renderCube(renderer);
        cube2.rotateYZ();
        
        /**
		* @fn SDL_Delay(20) 
		* @brief Cette fonction attend un nombre spécifié de millisecondes avant de revenir
		* Il attend au moins le temps spécifié, mais peut-être plus longtemps en raison de la planification du système d'exploitation.
		*
		*/
		SDL_Delay(20);                                    
	          
		   while (SDL_PollEvent(&event))
		      {
			   switch(event.type)
			   {
				    case SDL_QUIT:
				         done = true;
					     break;
					
				    case SDL_KEYDOWN:
					    switch(event.key.keysym.sym)
					       {	
				              case SDLK_RIGHT:
				              	  // Rotation commandee par le clavier la touche fleche droite suivant le sens de l'axe XZ
					              cube.rotateXZ(); 
					              cube1.rotateXZ();
					              cube2.rotateXZ();
					              SDL_Delay(20);
					               break;
							
					          case SDLK_LEFT:
					          	  // Rotation commandee par le clavier la touche fleche gauche suivant le sens inverse de l'axe XZ
					              cube.rotateXZ_oppo(); 
					              cube1.rotateXZ_oppo(); 
					              cube2.rotateXZ_oppo(); 
					              SDL_Delay(20);
						          break;
						          
						      case SDLK_UP:
					          	  // Rotation commandee par le clavier la touche fleche haut suivant l'axe YZ
					              cube.rotateYZ(); 
					              cube1.rotateYZ();
					              cube2.rotateYZ();
					              SDL_Delay(20);
						          break;   
							
				              default:
					              break;
		     	}
		     	   default:
					     break;
		     	}
       }
       
	// fonction qui permette de realiser l'actualisation de la fenetre	
	renderer.updateScreen();
	// fonction qui permette de definir une couleur de la fenetre 
	renderer.clearScreen();
     
    }
   // fonction qui permette de detruire et sortir de la fenetre
    renderer.quit();
    return 0;
}


