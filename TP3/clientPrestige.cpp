/*
* Titre : ClientPrestige.cpp - Travail Pratique #3
* Date : 15 f�vrier 2019
* Auteur : �tienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "ClientPrestige.h"

/**
* Ce constructeur par d�faut initialise les attributs du client prestige aux valeurs par d�faut.
*/
ClientPrestige::ClientPrestige():ClientRegulier(), adresse_(Zone3)
{
	statut_ = Prestige;
}

/**
* Ce constructeur par param�tres initialise les attributs du client prestige aux valeurs correspondantes.
*
* @param Son nom.
* @param Son pr�nom.
* @param La taille de son groupe.
* @param L'adresse du client.
*/
ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AdressCode adresse) 
: ClientRegulier(nom, prenom, tailleGroupe, nbPoints), adresse_(adresse)
{
	statut_ = Prestige;
}

/**
* Cette m�thode acc�de � l'adresse du client prestige.
*
* @return L'adresse du client prestige.
*/
AdressCode ClientPrestige::getAdresseCode() const 
{
	return adresse_;
}

/**
* Cette m�thode permet de convertir la valeur �num�r�e de adresse_ en string.
*/
string ClientPrestige::getAdressCodeString() const 
{
	string adresses[3] = { "Zone 1", "Zone 2", "Zone 3" };
	return adresses[adresse_];
	
}

/**
* Cette m�thode permet d'afficher l'adresse du client prestige.
*
* @param Le param�tre en sortie.
* @param Le client � afficher.
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
