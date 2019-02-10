/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifi� par : �tienne Bourgoin #1955553 et Manuel Pellerin #1960929 
* Date : 08 f�vrier 2019
*/

#include "Plat.h"

/**
* Ce constructeur par d�faut initialise les attributs d'un plat aux valeurs par d�faut.
*/
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

/**
* Ce constructeur par param�tres initialise les attributs d'un plat aux valeurs correspondantes.
*/
Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

/**
* Cette m�thode acc�de au nom du plat.
*
* @return Le nom du plat.
*/
string Plat::getNom() const {
	return nom_;
}

/**
* Cette m�thode acc�de au prix du plat pour le client.
*
* @return Le prix du plat.
*/
double Plat::getPrix() const {
	return prix_;
}

/**
* Cette m�thode acc�de au co�t du plat pour le restaurant.
*
* @return Le co�t du plat.
*/
double Plat::getCout() const {
	return cout_;
}

/**
* Cette m�thode permet de modifier le nom du plat.
*/
void Plat::setNom(string nom) {
	nom_ = nom;
}

/**
* Cette m�thode permet de modifier le prix du plat pour le client.
*/
void Plat::setPrix(double prix) {
	prix_ = prix;
}


/**
* Cette m�thode permet d'afficher le nom du plat, son prix pour le client
* et le co�t pour le restaurant.
* 
* @param Le param�tre en sortie. 
* @param Le plat � afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream& o, const Plat& plat) {
	o << plat.getNom() << " - " << plat.getPrix()
		<< " $ (" << plat.getCout() << "$ pour le restaurant )";
		
	return o;
}
/**
* Cette m�thode permet de comparer le prix de vente de deux plats.
*
* @ param Le plat du menu � comparer.
*
* @return Le bool�en qui permet de savoir quel plat est le plus cher.
*/
bool operator<(const Plat& plat1, const Plat& plat2) {
	if (plat1.getPrix() < plat2.getPrix())
		return true;
	else
		return false;
}
