/*
* Titre : ClientRegulier.cpp - Travail Pratique #3
* Date : 15 f�vrier 2019
* Auteur : �tienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "ClientRegulier.h"

/**
* Ce constructeur par d�faut initialise les attributs du client r�gulier aux valeurs par d�faut.
*/
ClientRegulier::ClientRegulier():Client(),nbPoints_(0)
{
	statut_ = Fidele;
	
}

/**
* Ce constructeur par param�tres initialise les attributs du client r�gulier aux valeurs correspondantes.
*
* @param Son nom.
* @param Son pr�nom.
* @param La taille de son groupe.
* @param Son nombre de points accumul�s.
*/
ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints) 
: Client(nom, prenom, tailleGroupe), nbPoints_(nbPoints)
{
	statut_ = Fidele;
}

/**
* Cette m�thode acc�de au nombre de points du client r�gulier.
*
* @return Le nombre de points du client r�gulier.
*/
int ClientRegulier::getNbPoints() const 
{
	return nbPoints_;
}

/**
* Cette m�thode permet d'augmenter le nombre de points du client r�gulier.
*
* @param Le nombre de points � ajouter (bonus).
*/
void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}

/**
* Cette m�thode permet d'afficher le nombre de points du client r�gulier.
*
* @param Le param�tre en sortie.
* @param Le client � afficher.
*
* @return La sortie.
*/
ostream& operator<<(ostream & os, const ClientRegulier& client)
{
	os << static_cast<Client>(client) << " Possede " << client.nbPoints_ << "points." << endl;
	return os;
}

