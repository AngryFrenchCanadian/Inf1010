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
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	nbPoints_ = nbPoints;
	adresse_ = adresse;
	statut_ = Prestige;
}

/**
* Cette m�thode acc�de � l'adresse du client prestige.
*
* @return L'adresse du client prestige.
*/
AdressCode ClientPrestige::getAdresseCode()
{
	return adresse_;
}

/**
* Cette m�thode permet de convertir la valeur �num�r�e de adresse_ en string.
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
* Cette m�thode permet d'afficher l'adresse du client prestige.
*
* @param Le param�tre en sortie.
* @param Le client � afficher.
*
* @return La sortie.
*/
ostream & operator<<(ostream & os, ClientPrestige client)
{
	os << "\t\t Habite dans la " << client.getAdressCodeString() << endl;
	return os;
}
