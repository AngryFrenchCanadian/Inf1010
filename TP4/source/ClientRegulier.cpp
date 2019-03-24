/*
* Titre : ClientRegulier.cpp - Travail Pratique #4
* Date : 25 f�vrier 2019
* Auteur : AbdeB
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin #1960929
*/
#include "ClientRegulier.h"

/**
* Ce constructeur par d�faut initialise les attributs du client regulier aux valeurs par d�faut.
*/
ClientRegulier::ClientRegulier()
{
	nbPoints_ = 0;
}

/**
* Ce constructeur par param�tres initialise les attributs du client regulier aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prenom.
* @param La taille de son groupe.
* @param Son nombre de points.
*/
ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int npoints)
: Client(nom, prenom, tailleGroupe), nbPoints_(npoints)
{ 
}

/**
* Ce destructeur d�truit un client regulier.
*/
ClientRegulier::~ClientRegulier() {}

/**
* Cette m�thode acc�de au nombre de points du client regulier.
*
* @return Le nombre de points.
*/
int ClientRegulier::getNbPoints() const
{
	return nbPoints_;
}

/**
* Cette m�thode permet d'augmenter le nombre de points du client regulier.
*
* @param Le bonus a ajouter.
*/
void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}

/**
* Cette m�thode permet d'afficher le nom, le pr�nom et le la table du client.
*
* @param Le param�tre en sortie.
*/
void ClientRegulier::afficherClient(ostream & os) const
{
	Client::afficherClient(os);
	os << "Points: " << nbPoints_ << endl;
}

/**
* Cette m�thode acc�de a la reduction du client regulier.
*
* @param Le nom du restaurant.
* @param Le montant de la facture.
* @param Si le client se fait livrer.
*
* @return La reduction.
*/
double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison) const
{
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		return (-montant * TAUX_REDUC_REGULIER);
	}
}
