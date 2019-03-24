//
//  Boisson.h
//
//  Created by Martine Bellaiche on 2019-03-05.
//  Copyright © 2019 Martine Bellaiche. All rights reserved.
//
// Modifié par : Étienne Bourgoin #1955553
// Modifié par : Manuel Pellerin #1960929

#ifndef BOISSON_h
#define BOISSON_h
#include "Taxable.h"
#include <string>
#include <string_view>
using namespace std;
class Boisson : public Taxable
{
 public:
    Boisson (string_view nom, double prix);
    string_view getNom() const;
    double getPrix () const;
	virtual void setTaxe();
	virtual double getTaxe() const;
protected:
    string nom_;
    double prix_;
    double taxe_;
};


#endif /* Boisson_h */
