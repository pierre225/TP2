#ifndef PIXEL_H
#define PIXEL_H


#include <iostream>

using namespace std;

class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	unsigned int obtenirTauxRouge() const;
	unsigned int obtenirTauxVert() const;
	unsigned int obtenirTauxBleu() const;
		
	
     //  Remplacer cette méthode par char retournerCouleur() const;
	void afficherPixel() const;
	// fonction pour retourner la couleur du pixel sous forme de caractere
	char retournerCouleur() const;

	//surcharge de l'opérateur "<<" pour afficher le pixel
	friend ostream& operator<<(ostream& o, const Pixel& pixel);

	//surcharge de l'opérateur "==" pour comparer deux pixels
	bool operator==(const Pixel& pixel2) const;

	//surcharge de l'opérateur "==" pour comparer un pixel et une couleur (char)
	bool operator==(const char& charToCompare) const;

	//surcharge permettant d'inverser les termes
	friend bool operator==(const char& charToCompare, const Pixel& pixel) ;


private:
	unsigned int tauxRouge_;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};



#endif