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
StatutClient Client::getStatut()const {
	return statut_;
}

/**
* Cette méthode accède au nom du client.
*
* @return Le nom du client.
*/
string Client::getNom()const {
	return nom_;
}

/**
* Cette méthode accède au prénom du client.
*
* @return Le prénom du client.
*/
string Client::getPrenom()const {
	return prenom_;
}

/**
* Cette méthode accède à la taille du groupe du client.
*
* @return La taille du groupe du client.
*/
int Client::getTailleGroupe()const {
	return tailleGroupe_;
}

/**
* Cette méthode permet de convertir la valeur énumérée de statut_ en string.
*/
string Client::convertirStatutString() const{
	string statuts[3] = { "occasionnel","regulier","prestige" };
	return statuts[statut_];

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
	return(os << "\t -" << client.prenom_ << " " << client.nom_ << " statut: " << client.convertirStatutString());
	
}

