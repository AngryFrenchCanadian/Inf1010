//
//  Boisson.cpp
//  intra
//
//  Created by Martine Bellaiche on 2019-03-10.
//  Copyright © 2019 Martine Bellaiche. All rights reserved.
//
// Modifié par : Étienne Bourgoin #1955553
// Modifié par : Manuel Pellerin #1960929

#include "Boisson.h"

/**
* Ce constructeur par paramètres initialise les attributs de la boisson aux valeurs correspondantes.
*
* @param Le nom de la boisson.
* @param Le prix de la boisson.
*/
Boisson::Boisson (string_view nom, double prix): nom_(nom), prix_(prix)
{
}

/**
* Cette méthode accède au nom de la boisson.
*
* @return Le nom de la boisson.
*/
string_view Boisson::getNom() const
{ 
	return nom_;
}

/**
* Cette méthode accède au prix de la boisson.
*
* @return Le prix de la boisson.
*/
double Boisson::getPrix()  const
{
	return prix_;
}

/**
* Cette méthode permet de modifier les taxes pour la boisson.
*/
void Boisson::setTaxe()
{
	taxe_ = 0.12;
}

/**
* Cette méthode accède aux taxes pour la boisson.
*
* @return Les taxes pour la boisson.
*/
double Boisson::getTaxe() const
{
	return taxe_;
}
