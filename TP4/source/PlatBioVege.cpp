/*
* Titre : PlatBioVege.cpp - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*/
#include "PlatBioVege.h"

/**
* Ce constructeur par paramètres initialise les attributs du plat bio vege aux valeurs correspondantes.
*
* @param Le nom du plat.
* @param Le prix du plat.
* @param Le coût du plat pour le restaurant.
* @param Le montant d'écotaxe.
* @param Le nombre de vitamines.
* @param Le nombre de proteines.
* @param Le nombre de mineraux.
*/
PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
: PlatBio(nom, prix, cout, ecotaxe), Vege(nom, vitamines, proteines, mineraux)
{
}

/*
* Ce destructeur par defaut detruit le plat bio vege.
*/
PlatBioVege:: ~PlatBioVege(){}

/**
* Cette méthode permet d'afficher le plat bio vege.
*
* @param Le paramètre en sortie.
*/
void PlatBioVege::afficherPlat(ostream & os) const
{
	PlatBio platbio;
	os << "Plat Bio	  comprend une Taxe ecologique de :" << ecoTaxe_ << "$" << endl <<
		"ET PLAT VEGE " << platbio.getNom() << "	" << "vitamines " << vitamines_ << "proteines " << proteines_
		<< "mineraux " << mineraux_ << endl;
}

/*
* Cette methode retourne un objet alloue dynamiquement qui est une copie d'un objet courant.
*
* @return le plat bio vege copie.
*/
Plat * PlatBioVege::clone() const
{ 
	//TODO
}

double PlatBioVege::calculerApportNutritif() const
{
	return ((vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTRITIF_BIO * AVANTAGE_SANS_PESTICIDE);
}
