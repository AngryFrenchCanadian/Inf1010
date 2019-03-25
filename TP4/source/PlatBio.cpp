/*
* Titre : PlatBio.cpp - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
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
PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}

/*
* Ce destructeur par defaut detruit le plat bio.
*/
PlatBio::~ PlatBio(){}

/**
* Cette méthode accède à l'écotaxe du plat.
*
* @return L'écotaxe du plat.
*/
double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

/**
* Cette méthode permet de définir l'écotaxe du plat.
*
* @param L'écotaxe du plat.
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
* Cette méthode permet d'obtenir le revenu du restaurant pour un plat bio.
*
* @return Le revenu du restaurant.
*/
double PlatBio:: getPrixDeRevient()
{
	return (prix_ - cout_ + ecoTaxe_);
}

/**
* Cette méthode permet d'afficher le plat bio.
*
* @param Le paramètre en sortie.
*/
void PlatBio::afficherPlat(ostream& os) const
{
	Plat::afficherPlat(os);
	os << "Plat Bio	  comprend une Taxe ecologique de :" << ecoTaxe_ << "$" << endl;
}
