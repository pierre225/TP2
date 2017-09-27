
#include "GroupImage.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

GroupImage::GroupImage():nombreImages_(0),capaciteImages_(0) {
	
}

GroupImage::~GroupImage() {
	capaciteImages_ = 0;
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

// ajouter une image au groupe
void GroupImage::ajouterImage(Image* image) {
	for (int i = 0; i < images_.size() ; i++){
		if (images_[i] == image){
			cout << "Une image du même nom est déjà dans le groupe" << endl;
			return;
		}
	}
	images_.push_back(image);
	nombreImages_++;
}

//fonction pour retirer une image selon son nom
void GroupImage::retirerImage(string & nomImage) {
	for (int i = 0; i < images_.size(); i++){
		if ((*images_[i]) == nomImage){
			//copie du dernier element à la place de l'element supprimé
			images_[i] = images_[nombreImages_ - 1];
			nombreImages_--;
			// supression du dernier element
			images_.pop_back();
		}
	}
}

//surcharge de l'opérateur += pour ajouter une image au groupe
GroupImage GroupImage::operator+=(Image* image) {
	ajouterImage(image);
	//retourn lui meme
	return *this;
}

//surcharge de l'opérateur -= pour retirer une image au groupe
GroupImage GroupImage::operator-=(Image* image) {
	retirerImage(image->obtenirNomImage());
	//retourn lui meme
	return *this;
}

//surcharge de << pour afficher les images du groupe
ostream& operator<<(ostream& o, const GroupImage& group) {
	o << "*********************************************" << endl;
	o << "Affichage des images du groupe :  ";
	o << group.obtenirType() << endl;
	o << "*********************************************" << endl;
	for (unsigned int i = 0; i < group.nombreImages_; i++) {
		(*group.images_[i]).afficherImage();
		o << "---------------------------------------------" << endl;
	}
	o << endl;
	return o;
}


void GroupImage::afficherImages(ostream& os) const {

	os << "*********************************************" << endl;
	os << "Affichage des images du groupe :  ";
	os << obtenirType().c_str() << endl;
	os << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i < nombreImages_; i++) {
		images_[i]->afficherImage();
		cout << "---------------------------------------------" << endl;

	}
	cout << endl;
}


Image* GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

/*
void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnHauteur();
}

*/

 