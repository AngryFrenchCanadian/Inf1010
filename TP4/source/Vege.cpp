/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "Vege.h"

/**
* Ce constructeur par param�tres initialise les attributs de vege aux valeurs correspondantes.
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
* Cette m�thode acc�de au nombre de vitamines d'un plat.
*
* @return Le nombre de vitamines d'un plat.
*/
double Vege::getVitamines() const
{
	return vitamines_;
}

/**
* Cette m�thode acc�de au nombre de proteines d'un plat.
*
* @return Le nombre de proteines d'un plat.
*/
double Vege::getProteines() const
{
	return proteines_;
}

/**
* Cette m�thode acc�de au nombre de mineraux d'un plat.
*
* @return Le nombre de mineraux d'un plat.
*/
double Vege::getMineraux() const
{
	return mineraux_;
}

/**
* Cette m�thode permet de modifier le nombre de vitamines d'un plat.
*
* @param Le nombre de vitamines.
*/
void Vege::setVitamines(double vitamines)
{
	vitamines_ = vitamines;
}

/**
* Cette m�thode permet de modifier le nombre de proteines d'un plat.
*
* @param Le nombre de proteines.
*/
void Vege::setProteines(double proteines)
{
	proteines_ = proteines;
}

/**
* Cette m�thode permet de modifier le nombre de mineraux d'un plat.
*
* @param Le nombre de mineraux.
*/
void Vege::setMineraux(double mineraux)
{
	mineraux_ = mineraux;
}

/**
* Cette m�thode permet d'afficher le nombre de vitamines, de proteines et de mineraux d'un plat.
*
* @param Le param�tre en sortie.
*/
void Vege::afficherVege(ostream & os) const
{   
	os << "ET PLAT VEGE " <<nom_<< "/t vitamines"<< vitamines_ << " Proteines " << proteines_ << " Mineraux " << mineraux_ << endl;
}


