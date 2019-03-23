/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#include "Plat.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"
//#include "debogageMemoire.hpp"
using namespace std;

/**
* Ce constructeur par param�tres initialise les attributs du plat aux valeurs correspondantes.
*
* @param Son nom.
* @param Le prix du plat.
* @param Le cout du plat pour le restaurant.
*/
Plat::Plat(string_view nom, double prix, double cout) : nom_(nom), prix_(prix), cout_(cout) {
}

/*
* Ce destructeur par defaut detruit le plat.
*/
Plat::~Plat()
{
}

/**
* Cette m�thode acc�de au nom d'un plat.
*
* @return Le nom d'un plat.
*/
string Plat::getNom() const {
	return nom_;
}

/**
* Cette m�thode acc�de au prix d'un plat.
*
* @return Le prix d'un plat.
*/
double Plat::getPrix() const {
	return prix_;
}

/**
* Cette m�thode acc�de au cout pour le restaurant d'un plat.
*
* @return Le cout pour le restaurant d'un plat.
*/
double Plat::getCout() const {
	return cout_;
}

/**
* Cette m�thode permet de modifier le nombre de vitamines d'un plat.
*
* @param Le nom du plat.
*/
void Plat::setNom(string nom) {
	nom_ = nom;
}

/**
* Cette m�thode permet de modifier le prix d'un plat.
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
bool Plat::operator < (const Plat& plat) const
{
	return prix_ < plat.prix_;
}

/**
* Cette m�thode permet d'afficher le plat.
*
* @param Le param�tre en sortie.
*/
void Plat::afficherPlat(ostream & os) const
{
	os << "PLAT ----" << nom_ << " - " << prix_ << " $ (" << cout_ << "$ pour le restaurant)" << endl;
}

/**
* Cette m�thode permet d'obtenir le revenu du restaurant pour un plat.
*
* @return Le revenu du restaurant.
*/
double Plat::getPrixRevient()
{  return (prix_ - cout_);
    
}

/*
* Cette methode retourne un objet alloue dynamiquement qui est une copie d'un objet courant.
*
* @return le plat copie.
*/
 Plat* Plat:: clone () const
{ //TODO
}
