/*
* Titre : Plat.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;
const int MAXPLAT = 5;
class Plat {
public:
	/// constructeurs
	Plat();
	Plat(string nom, double prix, double cout);

	///getters
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	///setters
	void setNom(string nom);
	void setPrix(double prix);

	///methodes en plus
	friend ostream& operator<<(ostream& o, const Plat& plat);
	friend bool operator<(const Plat& plat1,const Plat& plat2);

private:
	string nom_;
	double prix_;
	double cout_;

};

ostream& operator<<(ostream& o, const Plat& plat);
bool operator<(const Plat& plat1, const Plat& plat2);


#endif // !PLAT_H
