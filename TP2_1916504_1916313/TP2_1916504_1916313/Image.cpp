
#include "Image.h"
#include <iostream>
#include "Const.h"

using namespace std;

Image::Image():nomImage_("Image Vide"),nombrePixelEnHauteur_(1),nombrePixelEnLargeur_(1)
{
	pixels_ = new Pixel*[1];
	pixels_[0] = new Pixel[1];
}


Image::~Image()
{
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	for(unsigned int i = 0; i < nombrePixelEnHauteur_; i++){
		delete[] pixels_[i];
	}
	pixels_ = 0;
}

Image::Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) :nomImage_(nomImage),
	nombrePixelEnHauteur_(nombrePixelHauteur), nombrePixelEnLargeur_(nombrePixelLargeur)
{
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_;i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}

//constructeur deep copy
Image::Image(const Image& imageCopiee): nomImage_(imageCopiee.nomImage_), nombrePixelEnHauteur_(imageCopiee.nombrePixelEnHauteur_), nombrePixelEnLargeur_(imageCopiee.nombrePixelEnLargeur_), pixels_(nullptr){
	//qu 3
	//initialiser Pixels
}

//surcharge de l'opérateur "="
Image& Image::operator=(const Image& otherImage){
	//on vérifie que l'on affecte pas l'objet à lui meme
	if (this != &otherImage){

		//delete pixels pour eviter la fuite mémoire
		for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
			delete[] pixels_[i];
		}
		pixels_ = 0;

		nomImage_ = otherImage.nomImage_;
		nombrePixelEnHauteur_ = otherImage.nombrePixelEnHauteur_;
		nombrePixelEnLargeur_ = otherImage.nombrePixelEnLargeur_;
		//on associe les pixels de l'autre image
		for (int i = 0; i < nombrePixelEnHauteur_; i++){
			for (int i1 = 0; i1 < nombrePixelEnLargeur_; i1++){
				pixels_[i][i1] = otherImage.pixels_[i][i1];
			}
		}
	}
}

//surcharge de l'opérator "<<" pour afficher l'image
ostream& operator<<(ostream& o, const Image& image) {
	return o << image.afficherImage();
}

//surcharge de l'opérateur "==" pour comparer deux images
bool Image::operator==(const Image& otherImage) const {
	//check d'abord si les noms matchent
	if (nomImage_ != otherImage.nomImage_) {
		return false;
	}
	// check si les tableaux ont la meme taille
	else if (nombrePixelEnHauteur_ != otherImage.nombrePixelEnHauteur_ || nombrePixelEnLargeur_ != otherImage.nombrePixelEnLargeur_)
		return false;
	else {
		//check de chaque pixel
		for (int i = 0; i < nombrePixelEnHauteur_; i++) {
			for (int i1 = 0; i1 < nombrePixelEnLargeur_; i1++) {
				if ((pixels_[i][i1] == otherImage.pixels_[i][i1]) == false)
					return false;
			}
		}
	}
	//si tous les check sont passé on return true
	return true;
}

//surcharge de l'opérateur "==" pour comparer une string et le nom d'une image
bool Image::operator==(const string& otherName) const {
	if (nomImage_ == otherName)
		return true;
	return false;
}

//surcharge de l'opérateur "==" pour comparer un nom et le nom d'une image dans l'autre sens
bool operator==(const string& otherName, const Image& image) {
	if (image.nomImage_ == otherName)
		return true;
	return false;
}




void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}


unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}


unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}

string Image::obtenirNomImage() const{
	return nomImage_;
}

bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if (positionLargeur >= nombrePixelEnLargeur_ || positionHauteur >= nombrePixelEnHauteur_) {
		return false;
	}
	else {
		pixels_[positionHauteur][positionLargeur] = pixel;
		return true;
	}
}




void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ *= 2;

	Pixel** imageTemp = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0;i < nombrePixelEnHauteur_ / 2;i++) {
		
		imageTemp[i] = pixels_[i];
	}
	for (unsigned int i = nombrePixelEnHauteur_ / 2;i < nombrePixelEnHauteur_;i++) {
		imageTemp[i] = new Pixel[nombrePixelEnLargeur_];

		for (unsigned int j = 0; j < nombrePixelEnLargeur_;j++) {
			imageTemp[i][j] = Pixel(0, 0, 0);
		}
	}	

	pixels_ = imageTemp;
	imageTemp = 0;

}


void Image::doublerTailleEnLargeur() {
	nombrePixelEnLargeur_ *= 2;

	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		Pixel* colonneImage = new Pixel[nombrePixelEnLargeur_];
		for (unsigned int j = 0;j < nombrePixelEnLargeur_ / 2; j++) {
			colonneImage[j] = pixels_[i][j];
		}
		pixels_[i] = colonneImage;

	}

	
}


void Image::afficherImage() const {

	cout << "Affichage de l'image :  " << obtenirNomImage().c_str()<< endl;
	
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		cout << "    ";
			for (unsigned int j = 0; j < nombrePixelEnLargeur_;j++) {
					pixels_[i][j].afficherPixel();
		    }
		cout << endl;
	}
}

Pixel Image::obtenirPixel(unsigned int positionLargeur,unsigned int positionHauteur) const {
 
	return pixels_[positionHauteur][positionLargeur];

}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {

	if (couleur == 'R') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	}
	if (couleur == 'G') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	}
	if (couleur == 'B') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
	}

}