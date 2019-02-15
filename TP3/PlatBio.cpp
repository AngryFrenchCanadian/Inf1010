#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecoTaxe) 
: Plat(nom, prix, cout), ecoTaxe_(ecoTaxe) {}

double PlatBio::getEcoTaxe() const {
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

ostream& operator<<(ostream& os, const PlatBio& plat)
{
	os << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl << 
	"\t\t" << "comprend une Taxe ecologique de :" << plat.ecoTaxe_ << "$" << endl;
	return os;
}