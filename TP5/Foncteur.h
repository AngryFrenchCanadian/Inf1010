/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher
{ // TODO
public:
	bool operator()(const pair<string, Plat*>& platGauche, const pair<string, Plat*>& platDroite) const {
		return (*platGauche.second < *platDroite.second);
	}
    
};

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double min, double max) :min_(min), max_(max) {};

	bool operator()(Plat* plat) {
		double prixPlat = plat->getPrix();
		return (prixPlat >= min_ && prixPlat <= max_);
	}
private:
	double min_;
	double max_;
};

