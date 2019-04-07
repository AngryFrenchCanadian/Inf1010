/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;

/**
* Ce foncteur prédicat binaire permet de comparer les plats deux à deux du conteneur map.
*
* @return Le booleen qui dit si le plat de gauche de la map est moins cher que celui de droite.
*/
class FoncteurPlatMoinsCher
{ // TODO
public:
	bool operator()(const pair<string, Plat*>& platGauche, const pair<string, Plat*>& platDroite) const {
		return (*platGauche.second < *platDroite.second);
	}
    
};

/**
* Ce foncteur prédicat unaire verifie si le prix d'un plat du conteneur map se situe entre les bornes.
*
* @param La borne inferieure.
* @param La borne superieure.
*
* @return Le booleen qui dit si le prix d'un plat se situe entre les bornes.
*/
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double min, double max) :min_(min), max_(max) {};

	bool operator()(const pair<string,Plat*>& pair)const {
		double prixPlat = pair.second->getPrix();
		return (prixPlat >= min_ && prixPlat <= max_);
	}
private:
	double min_;
	double max_;
};

