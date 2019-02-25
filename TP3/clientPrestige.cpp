/*
* Titre : ClientPrestige.cpp - Travail Pratique #3
* Date : 15 février 2019
* Auteur : Étienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "ClientPrestige.h"

/**
* Ce constructeur par défaut initialise les attributs du client prestige aux valeurs par défaut.
*/
ClientPrestige::ClientPrestige():ClientRegulier(), adresse_(Zone3)
{
	statut_ = Prestige;
}

/**
* Ce constructeur par paramètres initialise les attributs du client prestige aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prénom.
* @param La taille de son groupe.
* @param L'adresse du client.
*/
ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AdressCode adresse) 
: ClientRegulier(nom, prenom, tailleGroupe, nbPoints), adresse_(adresse)
{
	statut_ = Prestige;
}

/**
* Cette méthode accède à l'adresse du client prestige.
*
* @return L'adresse du client prestige.
*/
AdressCode ClientPrestige::getAdresseCode() const 
{
	return adresse_;
}

/**
* Cette méthode permet de convertir la valeur énumérée de adresse_ en string.
*/
string ClientPrestige::getAdressCodeString() const 
{
	string adresses[3] = { "Zone 1", "Zone 2", "Zone 3" };
	return adresses[adresse_];
	
}

/**
* Cette méthode permet d'afficher l'adresse du client prestige.
*
* @param Le paramètre en sortie.
* @param Le client à afficher.
*
* @return La sortie.
*/
ostream & operator<<(ostream & os, ClientPrestige& client)
{
	ClientRegulier clientReg = static_cast<ClientRegulier>(client);
	os << clientReg << endl << "\t Habite dans la "
		<< client.getAdressCodeString() << endl << endl;
	return os;
}
