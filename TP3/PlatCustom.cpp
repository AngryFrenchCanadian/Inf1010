/*
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date : 15 f�vrier 2019
* Auteur : �tienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "platCustom.h"

/**
* Ce constructeur par param�tres initialise les attributs du plat custom aux valeurs correspondantes.
*
* @param Le nom du plat.
* @param Le prix du plat.
* @param Le co�t du plat pour le restaurant.
* @param Le nombre d'ingr�dients suppl�mentaires.
*/
PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients)
	: Plat(nom,prix,cout),nbIngredients_(nbIngredients)
{
	supplement_ = calculerSupplement();
	type_ = Custom;
}

/**
* Cette m�thode acc�de au nombre d'ingr�dients suppl�mentaires.
*
* @return Le nombre d'ingr�dients suppl�mentaires.
*/
int PlatCustom::getNbIngredients() const
{
	return nbIngredients_;
}

/**
* Cette m�thode acc�de au suppl�ment � ajouter au prix du plat.
*
* @return Le nom du plat.
*/
double PlatCustom::getSupplement()const
{
	return supplement_;
}

/**
* Cette m�thode permet de d�finir le nombre d'ingr�dients suppl�mentaires.
*
* @param Le nombre d'ingr�dients suppl�mentaires.
*/
void PlatCustom::setNbIngredients(int nIngredients)
{
	nbIngredients_ = nIngredients;
}

/**
* Cette m�thode permet d'afficher le nombre d'ingr�dients suppl�mentaires dans le plat et le suppl�ment � ajouter au prix du plat.
*
* @param Le param�tre en sortie.
* @param Le plat � afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, const PlatCustom& plat)
{
	os << static_cast<Plat>(plat)  << "\t\t contient " << plat.nbIngredients_
		<< " elements modifies pour un supplement total de: "
		<< plat.supplement_ << '$' << endl;
	return os;
}

/**
* Cette m�thode permet de calculer le suppl�ment � ajouter au prix du plat.
*
* @return Le suppl�ment � ajouter au prix du plat.
*/
double PlatCustom::calculerSupplement()const
{
	return(nbIngredients_ * FRAIS_CUSTOMISATION);
}