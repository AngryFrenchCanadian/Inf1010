/*
* Titre : PlatBio.cpp - Travail Pratique #3
* Date : 15 février 2019
* Auteur : Étienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "PlatBio.h"

/**
* Ce constructeur par paramètres initialise les attributs du plat bio aux valeurs correspondantes.
*
* @param Le nom du plat.
* @param Le prix du plat.
* @param Le coût du plat pour le restaurant.
* @param Le montant d'écotaxe.
*/
PlatBio::PlatBio(string nom, double prix, double cout, double ecoTaxe) 
: Plat(nom, prix, cout), ecoTaxe_(ecoTaxe) 
{
	type_ = Bio;
}

/**
* Cette méthode accède à l'écotaxe du plat.
*
* @return L'écotaxe du plat.
*/
double PlatBio::getEcoTaxe() const {
	return ecoTaxe_;
}

/**
* Cette méthode permet de définir l'écotaxe du plat.
*
* @param L'écotaxe du plat.
*/
void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

/**
* Cette méthode permet d'afficher l'écotaxe du plat.
*
* @param Le paramètre en sortie.
* @param Le plat à afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, const PlatBio& plat)
{
	os << "\t\t" << "comprend une Taxe ecologique de :" << plat.ecoTaxe_ << "$" << endl;
	return os;
}