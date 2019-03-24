/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "Vege.h"

/**
* Ce constructeur par paramètres initialise les attributs de vege aux valeurs correspondantes.
*
* @param Son nom.
* @param Le nombre de vitamines.
* @param Le nombre de proteines.
* @param Le nombre de mineraux.
*/
Vege::Vege(string nom, double vitamines, double proteines, double mineraux): nom_(nom),vitamines_(vitamines), proteines_(proteines), mineraux_(mineraux)
{
}

/**
* Cette méthode accède au nombre de vitamines d'un plat.
*
* @return Le nombre de vitamines d'un plat.
*/
double Vege::getVitamines() const
{
	return vitamines_;
}

/**
* Cette méthode accède au nombre de proteines d'un plat.
*
* @return Le nombre de proteines d'un plat.
*/
double Vege::getProteines() const
{
	return proteines_;
}

/**
* Cette méthode accède au nombre de mineraux d'un plat.
*
* @return Le nombre de mineraux d'un plat.
*/
double Vege::getMineraux() const
{
	return mineraux_;
}

/**
* Cette méthode permet de modifier le nombre de vitamines d'un plat.
*
* @param Le nombre de vitamines.
*/
void Vege::setVitamines(double vitamines)
{
	vitamines_ = vitamines;
}

/**
* Cette méthode permet de modifier le nombre de proteines d'un plat.
*
* @param Le nombre de proteines.
*/
void Vege::setProteines(double proteines)
{
	proteines_ = proteines;
}

/**
* Cette méthode permet de modifier le nombre de mineraux d'un plat.
*
* @param Le nombre de mineraux.
*/
void Vege::setMineraux(double mineraux)
{
	mineraux_ = mineraux;
}

/**
* Cette méthode permet d'afficher le nombre de vitamines, de proteines et de mineraux d'un plat.
*
* @param Le paramètre en sortie.
*/
void Vege::afficherVege(ostream & os) const
{   
	os << "ET PLAT VEGE " <<nom_<< "/t vitamines"<< vitamines_ << " Proteines " << proteines_ << " Mineraux " << mineraux_ << endl;
}


