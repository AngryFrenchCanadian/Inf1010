/*
* Titre : PlatBio.cpp - Travail Pratique #4
* Date : 25 f�vrier 2019
* Auteur : AbdeB
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin #1960929
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
PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}

/*
* Ce destructeur par defaut detruit le plat bio.
*/
PlatBio::~ PlatBio(){}

/**
* Cette m�thode acc�de � l'�cotaxe du plat.
*
* @return L'�cotaxe du plat.
*/
double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

/**
* Cette m�thode permet de d�finir l'�cotaxe du plat.
*
* @param L'�cotaxe du plat.
*/
void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

/*
* Cette methode retourne un objet alloue dynamiquement qui est une copie d'un objet courant.
*
* @return le plat bio copie.
*/
Plat* PlatBio:: clone() const
{
	return (new PlatBio(nom_, prix_, cout_, ecoTaxe_));
}

/**
* Cette m�thode permet d'obtenir le revenu du restaurant pour un plat bio.
*
* @return Le revenu du restaurant.
*/
double PlatBio:: getPrixDeRevient()
{
	return (prix_ - cout_ + ecoTaxe_);
}

/**
* Cette m�thode permet d'afficher le plat bio.
*
* @param Le param�tre en sortie.
*/
void PlatBio::afficherPlat(ostream& os) const
{
	Plat::afficherPlat(os);
	os << "Plat Bio	  comprend une Taxe ecologique de :" << ecoTaxe_ << "$" << endl;
}
