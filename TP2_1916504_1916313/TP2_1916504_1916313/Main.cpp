/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteur: 
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

/*
TODO : Veuillez répondre aux question ici
1)
2)
3)
*/

int main()
{

	//1- Creez 9 pixels rouge  (255,0,0)
	Pixel* tabPixelRouges = new Pixel[9];
	for (int i = 0; i < 9; i++)
		tabPixelRouges[i] = Pixel(255, 0, 0);

	//2-Creez 9 pixels verts (0,255,0)
	Pixel* tabPixelVerts = new Pixel[9];
	for (int i = 0; i < 9; i++)
		tabPixelVerts[i] = Pixel(0, 255, 0);

	//3- Creez une image de taille 3*3 
	Image* imageRouge = new Image("image rouge", 3, 3);
	
	//4- Ajouter à l'image créées à l'étape 3 les pixels rouges
	int i = 0;
	for (int i1 = 0; i1 < 3; i1++) {
		for (int i2 = 0; i2 < 3; i2++) {
			imageRouge->ajouterPixel(tabPixelRouges[i], i1, i2);
			i++;
		}
	}


	//5- Creez une deuxième image de taille 3*3 
	Image* imageVerte = new Image("image verte", 3, 3);

	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	i = 0;
	for (int i1 = 0; i1 < 3; i1++) {
		for (int i2 = 0; i2 < 3; i2++) {
			imageVerte->ajouterPixel(tabPixelVerts[i], i1, i2);
			i++;
		}
	}

	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupeImage1 = GroupImage();

	//8- Ajoutez les deux images crées precédament au groupe
	groupeImage1 += imageRouge;
	groupeImage1 += imageVerte;

	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	groupeImage1.obtenirImage(0)->augmenterTeintePixel(1, 1, 50, 'B');
	 
	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	groupeImage1.obtenirImage(0)->augmenterTeintePixel(1, 1, -255, 'R');

	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	groupeImage1.obtenirImage(1)->augmenterTeintePixel(2, 1, 100, 'B');

	//12- Afficher le groupe d'image
	cout << groupeImage1;

	//13- Supprimer la premiere image du groupe d'image
	groupeImage1 -= groupeImage1.obtenirImage(0);

	//14- Afficher le groupe d'image
	cout << groupeImage1;

	system("pause");

	return 0;
}