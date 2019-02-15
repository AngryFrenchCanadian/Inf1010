#include "platCustom.h"

// constructeur
PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients)
	: Plat(nom,prix,cout),nbIngredients_(nbIngredients)
{
	supplement_ = nbIngredients_ * FRAIS_CUSTOMISATION;
}

//getters 
int PlatCustom::getNbIngredients() const
{
	return nbIngredients_;
}
double PlatCustom::getSupplement()const
{
	return supplement_;
}

//setters 
void PlatCustom::setNbIngredients(int nIngredients)
{
	nbIngredients_ = nIngredients;
}




//methodes en plus 

ostream& operator<<(ostream& os, const PlatCustom& plat)
{
	os << plat << endl << "\t\t contient " << plat.nbIngredients_
		<< " elements modifies pour un supplement total de: "
		<< plat.supplement_ << '$' << endl;
}