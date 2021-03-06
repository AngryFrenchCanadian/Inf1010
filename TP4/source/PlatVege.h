/*
* Titre : PlatVege.h - Travail Pratique #4
* Date : 25 f�vrier 2019
* Auteur : AbdeB
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin #1960929
*/
#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege :
        public Vege, public Plat, public Taxable
{
public:
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
             double proteines = 0, double mineraux = 0);//TODO
    virtual ~PlatVege();
    virtual Plat* clone()const; // TODO
    virtual void afficherPlat(ostream & os) const;//TODO
    double calculerApportNutritif() const; // TODO
	virtual void setTaxe();
	virtual double getTaxe() const;

protected:
	double taxe_;
};
#endif
