#ifndef IMAGE_H
#define IMAGE_H
#include "Pixel.h"

#include<iostream>

using namespace std;

class Image
{
public:
	Image();
	~Image();

	Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur);

	// SI c'est nécessaire ajouter un constructeur par copie
	// il nous faut faire un constructeur deep copy car c'est une composition par pointeur
	Image(const Image& copie);

	//surcharge de l'operateur "="
	Image& operator=(const Image& otherImage);

	//surcharge de l'opérateur "<<" pour afficher
	friend ostream& operator<<(ostream& o, const Image& image);

	//surcharge de l'opérateur "==" pour comparer deux images
	bool operator==(const Image& otherImage) const;

	//surcharge de l'opérateur "==" pour comparer un nom et le nom d'une image
	bool operator==(const string& otherName) const;

	//surcharge de l'opérateur "==" pour comparer un nom et le nom d'une image dans l'autre sens
	friend bool operator==(const string& otherName, const Image& image);

	
	void doublerTailleEnLargeur();
	void doublerTailleEnHauteur();

	unsigned int obtenirNombrePixelHauteur() const;
	unsigned int obtenirNombrePixelLargeur() const;
	string obtenirNomImage() const;

	
	void modifierNomImage(const string & nomImage);

	// Methode à ignorer pour le TP2
	void afficherImage() const;

	bool ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur);
	Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const ;
	void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur);

    // Ajouter les opérateurs
private :
	string nomImage_;
	unsigned int nombrePixelEnHauteur_;
	unsigned int nombrePixelEnLargeur_;
	Pixel** pixels_;

};

#endif