#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"
#include <vector>
#include <iostream>


using namespace std;


class GroupImage
{
public:
	GroupImage(); // A modifier l'implementation
	~GroupImage(); // A modifier l'implementation

	void modifierType(const string &type);

	// pour obtenir l'image à l'indice voulu
	Image* obtenirImage(unsigned int indiceImage) const;

	
    // Méthode à supprimer pour TP2
	unsigned int obtenirNombreImages() const;

	// Méthode à modifier avec void ajouterImage(Image* &image);
	void ajouterImage(Image* image);
	
	//  ajouter la methode pour retirer une image en donnant
	//son nom en paramètre
	void retirerImage(string & nomImage);

	// Méthode à modifier avec void afficherImages(ostream& os)
	void afficherImages(ostream& os) const;  
	

	void doublerTailleImageEnLargeur(unsigned int indiceImage);

	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	
     
    // Ajout de l'operateur += pour ajouter une image a un vecteur
	GroupImage operator+=(Image* Image);

	// Ajout de l'operateur -= pour retirer une image a un vecteur
	GroupImage operator-=(Image* Image);

	// Ajout de l'operateur << pour afficher les images
	friend ostream& operator<<(ostream& o, const GroupImage& group);

	//getter of the type
	string obtenirType() const;

private:

	string type_;

	// Attributs à mdifier 
	unsigned int nombreImages_;
	unsigned int capaciteImages_;
	vector<Image*> images_;

};

#endif