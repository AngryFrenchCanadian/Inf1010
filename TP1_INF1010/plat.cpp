#ifndef PLAT_H
#define PLAT_H
#endif

#include <string>
#include <iostream>
#include "Plat.h"
using namespace std;

int main() {
	Plat::Plat() {} //constructeur par defaut

	Plat::Plat(string nom, double prix, double cout) { //constructeur par parametres
		nom_ = nom;
		prix_ = prix;
		cout_ = cout;
	}

	string Plat::getNom() {
		return name_;
	}

	double Plat::getPrix() {
		return prix_;
	}

	double Plat::getCout() {
		return cout_;
	}

	Plat::setNom(string nom) {
		nom_ = nom;
	}

	Plat::setPrix(double prix) {
		prix_ = prix;
	}

	Plat::afficher() {
		cout << getNom() << endl;
		cout << getPrix() << endl;
		cout << getCout() << endl;
	}
}