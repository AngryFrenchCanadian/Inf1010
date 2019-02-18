/*
* Titre : PlatBio.cpp - Travail Pratique #3
* Date : 15 f�vrier 2019
* Auteur : �tienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "PlatBio.h"

/**
* Ce constructeur par param�tres initialise les attributs du plat bio aux valeurs correspondantes.
*
* @param Le nom du plat.
* @param Le prix du plat.
* @param Le co�t du plat pour le restaurant.
* @param Le montant d'�cotaxe.
*/
PlatBio::PlatBio(string nom, double prix, double cout, double ecoTaxe) 
: Plat(nom, prix, cout), ecoTaxe_(ecoTaxe) 
{
	type_ = Bio;
}

/**
* Cette m�thode acc�de � l'�cotaxe du plat.
*
* @return L'�cotaxe du plat.
*/
double PlatBio::getEcoTaxe() const {
	return ecoTaxe_;
}

/**
* Cette m�thode permet de d�finir l'�cotaxe du plat.
*
* @param L'�cotaxe du plat.
*/
void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

/**
* Cette m�thode permet d'afficher l'�cotaxe du plat.
*
* @param Le param�tre en sortie.
* @param Le plat � afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, const PlatBio& plat)
{
	os << "\t\t" << "comprend une Taxe ecologique de :" << plat.ecoTaxe_ << "$" << endl;
	return os;
}