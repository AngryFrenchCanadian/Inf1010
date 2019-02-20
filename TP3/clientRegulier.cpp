/*
* Titre : ClientRegulier.cpp - Travail Pratique #3
* Date : 15 février 2019
* Auteur : Étienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "ClientRegulier.h"

/**
* Ce constructeur par défaut initialise les attributs du client régulier aux valeurs par défaut.
*/
ClientRegulier::ClientRegulier():Client(),nbPoints_(0)
{
	statut_ = Fidele;
	
}

/**
* Ce constructeur par paramètres initialise les attributs du client régulier aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prénom.
* @param La taille de son groupe.
* @param Son nombre de points accumulés.
*/
ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints) 
: Client(nom, prenom, tailleGroupe), nbPoints_(nbPoints)
{
	statut_ = Fidele;
}

/**
* Cette méthode accède au nombre de points du client régulier.
*
* @return Le nombre de points du client régulier.
*/
int ClientRegulier::getNbPoints() const 
{
	return nbPoints_;
}

/**
* Cette méthode permet d'augmenter le nombre de points du client régulier.
*
* @param Le nombre de points à ajouter (bonus).
*/
void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}

/**
* Cette méthode permet d'afficher le nombre de points du client régulier.
*
* @param Le paramètre en sortie.
* @param Le client à afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream & os, const ClientRegulier& client)
{
	os << static_cast<Client>(client) << " Possede " << client.nbPoints_ << "points." << endl;
	return os;
}

