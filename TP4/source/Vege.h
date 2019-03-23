/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef VEGE_H
#define VEGE_H
#include <iostream>
#include <string_view>
#include <string>
#include"Taxable.h"
using namespace std;
class Vege
{
public:
	Vege(string nom, double vitamines, double proteines, double mineraux);
	virtual double getVitamines() const = 0;
	virtual double getProteines() const = 0;
	virtual double getMineraux() const = 0;
	virtual void setVitamines(double vitamines) = 0;
	virtual void setProteines(double proteines) = 0;
	virtual void setMineraux(double mineraux) = 0;
    void afficherVege(ostream & os) const; // TODO

protected: 
	double vitamines_;
	double proteines_;
	double mineraux_;
    
    string nom_;
};
#endif
