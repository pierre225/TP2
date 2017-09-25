
#include "GroupImage.h"
#include <iostream>

using namespace std;

GroupImage::GroupImage():nombreImages_(1),capaciteImages_(1) {
	images_ = new Image[1];
}

GroupImage::~GroupImage() {
	delete[] images_;
	capaciteImages_ = 0;
	nombreImages_ = 0;

}

GroupImage::GroupImage(const string & type,unsigned int capaciteImages): type_(type), capaciteImages_(capaciteImages) {

	images_ = new Image[capaciteImages_];
	nombreImages_ = 0;
}

void GroupImage::modifierType(const string & type) {
	type_ = type;
}

string GroupImage::obtenirType() const{
	return type_;
}

unsigned int GroupImage::obtenirNombreImages() const {
	return nombreImages_;
}

void GroupImage::ajouterImage(const Image& image) {
	if (nombreImages_ < capaciteImages_) {
		images_[nombreImages_++] = image;
	}
}

void GroupImage::afficherImages() const {

	cout << "*********************************************" << endl;
	cout << "Affichage des images du groupe :  ";
	cout << obtenirType().c_str() << endl;
	cout << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i < nombreImages_; i++) {

		images_[i].afficherImage();
		cout << "---------------------------------------------" << endl;

	}
	cout << endl;
}

Image GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnHauteur();
}
 