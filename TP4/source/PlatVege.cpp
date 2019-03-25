/*
* Titre : PlatVege.cpp - Travail Pratique #4
* Date : 25 f�vrier 2019
* Auteur : AbdeB
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin #1960929
*/
#include "PlatVege.h"


/**
* Ce constructeur par param�tres initialise les attributs du plat vege aux valeurs correspondantes.
*
* @param Son nom.
* @param Le prix du plat.
* @param Le cout du plat pour le restaurant.
* @param Le nombre de vitamines.
* @param Le nombre de proteines.
* @param Le nombre de mineraux.
*/
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux) : Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux)
{
	setTaxe();
}

/*
* Ce destructeur par defaut detruit le plat vege.
*/
PlatVege::~ PlatVege(){}

/*
* Cette methode retourne un objet alloue dynamiquement qui est une copie d'un objet courant.
*
* @return le plat vege copie.
*/
Plat* PlatVege::clone() const
{ 
	return (new PlatVege(Vege::nom_, prix_, cout_, vitamines_, proteines_, mineraux_));
}

/**
* Cette m�thode permet d'afficher le plat vege.
*
* @param Le param�tre en sortie.
*/
void PlatVege::afficherPlat(ostream & os) const
{   
	Plat::afficherPlat(os);
	Vege::afficherVege(os);
	os << "(Apport nutritif " << calculerApportNutritif() << "mg )" << endl;
}


/**
* Cette m�thode permet de calculer l'apport nutritif du plat.
*
* @return L'apport nutritif du plat.
*/
double PlatVege::calculerApportNutritif() const
{
	return ((vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTRITIF);
}

/**
* Cette m�thode permet de modifier les taxes pour le plat vege.
*/
void PlatVege::setTaxe()
{
	taxe_ = 0.07;
}

/**
* Cette m�thode acc�de aux taxes pour le plat vege.
*
* @return Les taxes pour le plat vege.
*/
double PlatVege::getTaxe() const
{
	return taxe_;
}
