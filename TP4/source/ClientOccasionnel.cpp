/*
* Titre : ClientOccasionnel.cpp - Travail Pratique #4
* Date : 25 f�vrier 2019
* Auteur : AbdeB
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin #1960929
*/
#include "ClientOccasionnel.h"

/**
* Ce constructeur par param�tres initialise les attributs du client occasionnel aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prenom.
* @param La taille de son groupe.
*/
ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe) : Client(nom, prenom, tailleGroupe)
{ 
}

/**
* Ce destructeur d�truit un client occasionnel.
*/
ClientOccasionnel::~ClientOccasionnel(){}

/**
* Cette m�thode acc�de au nombre de points du client occasionnel.
*
* @return Le nombre de points.
*/
int ClientOccasionnel::getNbPoints() const
{
	return 0;
}

/**
* Cette m�thode acc�de a la reduction du client occasionnel.
*
* @param Le nom du restaurant. 
* @param Le montant de la facture.
* @param Si le client se fait livrer.
*
* @return La reduction.
*/
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison) const
{
	return 0.0;
}

/**
* Cette m�thode permet d'afficher le nom, le pr�nom et le la table du client.
*
* @param Le param�tre en sortie.
*/
void ClientOccasionnel::afficherClient(ostream & os) const
{
	if (tableOccupee_ != nullptr) {
		os << "La table numero " << tableOccupee_ << " est occupee. Le client principal est: " << endl <<
			prenom_ << nom_ << endl;
	}
}


