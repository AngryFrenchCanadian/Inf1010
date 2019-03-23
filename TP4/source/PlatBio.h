/*
* Titre : PlatBio.h - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio: public Plat {
public:
	// constructeurs
        PlatBio(string nom = "inconnu", double prix = 0,
                double cout = 0, double ecotaxe = 0);//TODO
        ~ PlatBio();
	//getters 
	double getEcoTaxe() const;
	//setters 
	void setEcoTaxe(double ecoTaxe);
        void afficherPlat(ostream& os) const; // TODO
        double getPrixDeRevient(); //TODO
        Plat* clone() const; // TODO
protected:
	double ecoTaxe_;

};

#endif // !PLAT_VERT_H
