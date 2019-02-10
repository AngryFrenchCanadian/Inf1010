/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifié par : Étienne Bourgoin #1955553 et Manuel Pellerin #1960929 
* Date : 08 février 2019
*/

#include "Plat.h"

/**
* Ce constructeur par défaut initialise les attributs d'un plat aux valeurs par défaut.
*/
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

/**
* Ce constructeur par paramètres initialise les attributs d'un plat aux valeurs correspondantes.
*/
Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

/**
* Cette méthode accède au nom du plat.
*
* @return Le nom du plat.
*/
string Plat::getNom() const {
	return nom_;
}

/**
* Cette méthode accède au prix du plat pour le client.
*
* @return Le prix du plat.
*/
double Plat::getPrix() const {
	return prix_;
}

/**
* Cette méthode accède au coût du plat pour le restaurant.
*
* @return Le coût du plat.
*/
double Plat::getCout() const {
	return cout_;
}

/**
* Cette méthode permet de modifier le nom du plat.
*/
void Plat::setNom(string nom) {
	nom_ = nom;
}

/**
* Cette méthode permet de modifier le prix du plat pour le client.
*/
void Plat::setPrix(double prix) {
	prix_ = prix;
}


/**
* Cette méthode permet d'afficher le nom du plat, son prix pour le client
* et le coût pour le restaurant.
* 
* @param Le paramètre en sortie. 
* @param Le plat à afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream& o, const Plat& plat) {
	o << plat.getNom() << " - " << plat.getPrix()
		<< " $ (" << plat.getCout() << "$ pour le restaurant )";
		
	return o;
}
/**
* Cette méthode permet de comparer le prix de vente de deux plats.
*
* @ param Le plat du menu à comparer.
*
* @return Le booléen qui permet de savoir quel plat est le plus cher.
*/
bool operator<(const Plat& plat1, const Plat& plat2) {
	if (plat1.getPrix() < plat2.getPrix())
		return true;
	else
		return false;
}
