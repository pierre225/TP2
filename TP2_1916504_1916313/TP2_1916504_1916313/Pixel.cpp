
#include "Pixel.h"
#include <iostream>
#include "Const.h"

using namespace std;

Pixel::Pixel() : tauxRouge_(0),tauxVert_(0),tauxBleu_(0)
{
}


Pixel::~Pixel()
{
}

Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) :
	tauxRouge_(tauxRouge), tauxVert_(tauxVert), tauxBleu_(tauxBleu)
{
}


unsigned int Pixel::obtenirTauxRouge() const {
	return tauxRouge_;
}
unsigned int Pixel::obtenirTauxVert() const {
	return tauxVert_;
}
unsigned int Pixel::obtenirTauxBleu() const {
	return tauxBleu_;
}

void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (incrementRouge < 0) {
		if (abs(incrementRouge) >= tauxRouge_) {
		    tauxRouge_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ -= incrementRouge;
		}
	}
	else {
		unsigned int temp = tauxRouge_ + incrementRouge;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxRouge_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ = temp;
		}
	}
}

void Pixel::modifierTeinteVert( int incrementVert) {
	if (incrementVert < 0) {
		if (abs(incrementVert) >= tauxVert_) {
		    tauxVert_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ -= incrementVert;
		}
	}
	else {
		unsigned int temp = tauxVert_ + incrementVert;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxVert_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ = temp;
		}
	}
}

void Pixel::modifierTeinteBleu( int incrementBleu) {
	if (incrementBleu < 0) {
		if (abs(incrementBleu) >= tauxBleu_) {
		    tauxBleu_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ -= incrementBleu;
		}
	}
	else {
		unsigned int temp = tauxBleu_ + incrementBleu;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxBleu_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ = temp;
		}
	}
}




void Pixel::afficherPixel() const
{
	if (tauxVert_ == 0 && tauxBleu_ == 0 &&  tauxRouge_!=0) {
		cout << 'R';

	}
	else if (tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		cout << 'G';

	}
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ != 0) {
		cout << 'B';

	}
	// Optionnel, si on veut distinguer colore et completement noir
	/*
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ == 0){
		cout <<'O';
	}
	*/
	else {
		cout << 'Q';
	}
}

//Fonction qui retourne le caractère correspondant à la couleur du pixel
char Pixel::retournerCouleur() const {
	if (tauxVert_ == 0 && tauxBleu_ == 0 && tauxRouge_ != 0) {
		return 'R';
	}
	else if (tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		return 'G';

	}
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ != 0) {
		return 'B';
	}
	else
	{
		return 'Q';
	}
}

//surcharge de l'opérateur "<<" pour afficher le pixel
//qu1
ostream& Pixel::operator<<(ostream &os){
	this->afficherPixel();
}

//surcharge de l'opérateur "==" pour comparer 2 pixels
bool Pixel::operator==(const Pixel& pixel2) const {
	//on considère deux pixels égaux si ils ont les meme taux pour les couleurs Rouges Vertes et Bleues
	if (tauxRouge_ == pixel2.tauxRouge_ && tauxVert_ == pixel2.tauxVert_ && tauxBleu_ == pixel2.tauxBleu_){ // attributs de pixels2 dispo car même classe
		return true;
	}
	return false;
}

//surcharge de l'opérateur "==" pour comparer 2 pixels
bool Pixel::operator==(const char& charToCompare) const {
	//on utilise la fonction définie précédemment pour obtenir le char correspondant a la couleur et le comparer
	if (retournerCouleur() == charToCompare)
		return true;
	return false;
}

//surcharge similaire à celui d'au dessus mais permet d'inverser les termes
//qu2
bool Pixel::operator==(const char& charToCompare, const Pixel& pixel) {
	if (retournerCouleur() == charToCompare)
		return true;
	return false;
}


