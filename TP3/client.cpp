/*
* Titre : Client.cpp - Travail Pratique #3
* Date : 15 février 2019
* Auteur : Étienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "Client.h"

/**
* Ce constructeur par défaut initialise les attributs du client aux valeurs par défaut.
*/
Client::Client() {
	nom_ = "inconnu";
	prenom_ = "inconnu";
	statut_ = Occasionnel;
	tailleGroupe_ = 0;
}

/**
* Ce constructeur par paramètres initialise les attributs du client aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prénom.
* @param La taille de son groupe.
*/
Client::Client(string nom, string prenom, int tailleGroupe) {
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	statut_ = Occasionnel;
}

/**
* Ce destructeur détruit un client.
*/
Client::~Client() {}

/**
* Cette méthode accède au statut du client.
*
* @return Le statut du client.
*/
StatutClient Client::getStatut() {
	return statut_;
}

/**
* Cette méthode accède au nom du client.
*
* @return Le nom du client.
*/
string Client::getNom() {
	return nom_;
}

/**
* Cette méthode accède au prénom du client.
*
* @return Le prénom du client.
*/
string Client::getPrenom() {
	return prenom_;
}

/**
* Cette méthode accède à la taille du groupe du client.
*
* @return La taille du groupe du client.
*/
int Client::getTailleGroupe() {
	return tailleGroupe_;
}

/**
* Cette méthode permet de convertir la valeur énumérée de statut_ en string.
*/
string Client::convertirStatutString() {
	switch (statut_) {
	case Occasionnel:
		return "Occasionnel";
		break;
	case Fidele:
		return "Fidele";
		break;
	case Prestige:
		return "Prestige";
		break;
	}
}

/**
* Cette méthode permet d'afficher le nom, le prénom et le statut du client.
*
* @param Le paramètre en sortie.
* @param Le client à afficher.
*
* @return La sortie.
*/
ostream & operator<<(ostream & os, const Client& client) {
	os << "Le client principal est: " << endl << "\t\t" << client.prenom_ << " " << client.nom_ << " statut: " << client.convertirStatutString;
	return os;
}

