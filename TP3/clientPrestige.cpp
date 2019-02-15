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
ClientPrestige::ClientPrestige()
{
	adresse_ = Zone3;
	nom_ = "inconnu";
	prenom_ = "inconnu";
	statut_ = Prestige;
	tailleGroupe_ = 0;
	nbPoints_ = 0;
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
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	nbPoints_ = nbPoints;
	adresse_ = adresse;
	statut_ = Prestige;
}

/**
* Cette méthode accède à l'adresse du client prestige.
*
* @return L'adresse du client prestige.
*/
AdressCode ClientPrestige::getAdresseCode()
{
	return adresse_;
}

/**
* Cette méthode permet de convertir la valeur énumérée de adresse_ en string.
*/
string ClientPrestige::getAdressCodeString()
{
	switch (adresse_) {
	case Zone1: return"Zone 1";
		break;
	case Zone2: return"Zone 2";
		break;
	case Zone3: return"Zone3";
		break;
	}
}

/**
* Cette méthode permet d'afficher l'adresse du client prestige.
*
* @param Le paramètre en sortie.
* @param Le client à afficher.
*
* @return La sortie.
*/
ostream & operator<<(ostream & os, ClientPrestige client)
{
	os << "\t\t Habite dans la " << client.getAdressCodeString() << endl;
	return os;
}
