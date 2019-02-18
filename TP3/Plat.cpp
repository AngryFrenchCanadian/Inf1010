/*
* Titre : Plat.cpp - Travail Pratique #3
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin	#1960929
*/

#include "Plat.h"

/**
* Ce constructeur par param�tres initialise les attributs du plat aux valeurs correspondantes.
*
* @param Le nom du plat.
* @param Le prix du plat.
* @param Le co�t du plat pour le restaurant.
*/
Plat::Plat(string nom , double prix , double cout){
	nom_ = nom;
	prix_ = prix; 
	cout_ = cout; 
	type_ = Regulier;
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
* Cette m�thode acc�de au prix du plat.
*
* @return Le prix du plat.
*/
double Plat::getPrix() const {
	return prix_; 
}

/**
* Cette m�thode acc�de au co�t du plat pour le restaurant.
*
* @return Le co�t du plat pour le restaurant.
*/
double Plat::getCout() const {
	return cout_; 
}

/**
* Cette m�thode acc�de au type du plat.
*
* @return Le type du plat.
*/
TypePlat Plat::getType() const
{
	return type_;
}

/**
* Cette m�thode permet de d�finir le nom du plat.
*
* @param Le nom du plat.
*/
void Plat::setNom(string nom) {
	nom_ = nom; 
}

/**
* Cette m�thode permet de d�finir le prix du plat.
*
* @param Le prix du plat.
*/
void Plat::setPrix(double prix) {
	prix_ = prix; 
}

/**
* Cette m�thode permet de comparer le prix d'un plat.
*
* @return Si le plat est moins cher qu'un prix d�fini.
*/
bool Plat::operator<(const Plat& plat) const 
{
	return this->prix_ < plat.prix_;
}

/**
* Cette m�thode permet d'afficher le nom, le prix et le co�t pour le restaurant d'un plat.
*
* @param Le param�tre en sortie.
* @param Le plat � afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, const Plat& plat)
{
	os << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return os;
}