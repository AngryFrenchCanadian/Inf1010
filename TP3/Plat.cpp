/*
* Titre : Plat.cpp - Travail Pratique #3
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin	#1960929
*/

#include "Plat.h"

/**
* Ce constructeur par paramètres initialise les attributs du plat aux valeurs correspondantes.
*
* @param Le nom du plat.
* @param Le prix du plat.
* @param Le coût du plat pour le restaurant.
*/
Plat::Plat(string nom , double prix , double cout){
	nom_ = nom;
	prix_ = prix; 
	cout_ = cout; 
	type_ = Regulier;
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
* Cette méthode accède au prix du plat.
*
* @return Le prix du plat.
*/
double Plat::getPrix() const {
	return prix_; 
}

/**
* Cette méthode accède au coût du plat pour le restaurant.
*
* @return Le coût du plat pour le restaurant.
*/
double Plat::getCout() const {
	return cout_; 
}

/**
* Cette méthode accède au type du plat.
*
* @return Le type du plat.
*/
TypePlat Plat::getType() const
{
	return type_;
}

/**
* Cette méthode permet de définir le nom du plat.
*
* @param Le nom du plat.
*/
void Plat::setNom(string nom) {
	nom_ = nom; 
}

/**
* Cette méthode permet de définir le prix du plat.
*
* @param Le prix du plat.
*/
void Plat::setPrix(double prix) {
	prix_ = prix; 
}

/**
* Cette méthode permet de comparer le prix d'un plat.
*
* @return Si le plat est moins cher qu'un prix défini.
*/
bool Plat::operator<(const Plat& plat) const 
{
	return this->prix_ < plat.prix_;
}

/**
* Cette méthode permet d'afficher le nom, le prix et le coût pour le restaurant d'un plat.
*
* @param Le paramètre en sortie.
* @param Le plat à afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, const Plat& plat)
{
	os << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return os;
}