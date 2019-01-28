#include "Plat.h"
using namespace std;

	Plat::Plat() {
	} //constructeur par defaut

	Plat::Plat(string nom, double prix, double cout) { //constructeur par parametres
		nom_ = nom;
		prix_ = prix;
		cout_ = cout;
	}

	string Plat::getNom() {
		return nom_;
	}

	double Plat::getPrix() {
		return prix_;
	}

	double Plat::getCout() {
		return cout_;
	}

	void Plat::setNom(string nom) {
		nom_ = nom;
	}

	void Plat::setPrix(double prix) {
		prix_ = prix;
	}

	void Plat::afficher() {
		cout << getNom() << endl;
		cout << getPrix() << endl;
		cout << getCout() << endl;
	}