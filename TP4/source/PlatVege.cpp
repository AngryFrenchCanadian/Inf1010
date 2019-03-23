/*
* Titre : PlatVege.cpp - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*/
#include "PlatVege.h"


/**
* Ce constructeur par paramètres initialise les attributs du plat vege aux valeurs correspondantes.
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
	//TODO
}

/**
* Cette méthode permet d'afficher le plat vege.
*
* @param Le paramètre en sortie.
*/
void PlatVege::afficherPlat(ostream & os) const
{   
	Plat plat;
	os << "PLAT VEGE " << plat.getNom() << "	" << "vitamines " << vitamines_ << "proteines " << proteines_ 
	<< "mineraux " << mineraux_ << endl << "(apport nutritif " << calculerApportNutritif() << "mg)" << endl;
}

/**
* Cette méthode permet de calculer l'apport nutritif du plat.
*
* @return L'apport nutritif du plat.
*/
double PlatVege::calculerApportNutritif() const
{
	return ((vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTRITIF);
}
