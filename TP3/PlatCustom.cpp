/*
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date : 15 février 2019
* Auteur : Étienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "platCustom.h"

/**
* Ce constructeur par paramètres initialise les attributs du plat custom aux valeurs correspondantes.
*
* @param Le nom du plat.
* @param Le prix du plat.
* @param Le coût du plat pour le restaurant.
* @param Le nombre d'ingrédients supplémentaires.
*/
PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients)
	: Plat(nom,prix,cout),nbIngredients_(nbIngredients)
{
	supplement_ = calculerSupplement();
	type_ = Custom;
}

/**
* Cette méthode accède au nombre d'ingrédients supplémentaires.
*
* @return Le nombre d'ingrédients supplémentaires.
*/
int PlatCustom::getNbIngredients() const
{
	return nbIngredients_;
}

/**
* Cette méthode accède au supplément à ajouter au prix du plat.
*
* @return Le nom du plat.
*/
double PlatCustom::getSupplement()const
{
	return supplement_;
}

/**
* Cette méthode permet de définir le nombre d'ingrédients supplémentaires.
*
* @param Le nombre d'ingrédients supplémentaires.
*/
void PlatCustom::setNbIngredients(int nIngredients)
{
	nbIngredients_ = nIngredients;
}

/**
* Cette méthode permet d'afficher le nombre d'ingrédients supplémentaires dans le plat et le supplément à ajouter au prix du plat.
*
* @param Le paramètre en sortie.
* @param Le plat à afficher.
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
* Cette méthode permet de calculer le supplément à ajouter au prix du plat.
*
* @return Le supplément à ajouter au prix du plat.
*/
double PlatCustom::calculerSupplement()const
{
	return(nbIngredients_ * FRAIS_CUSTOMISATION);
}