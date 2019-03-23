/*
* Titre : Client.cpp - Travail Pratique #3
* Date : 15 f�vrier 2019
* Auteur : �tienne Bourgoin #1955553
* Auteur : Manuel Pellerin	#1960929
*/

#include "Client.h"

/**
* Ce constructeur par d�faut initialise les attributs du client aux valeurs par d�faut.
*/
Client::Client() {
	nom_ = "inconnu";
	prenom_ = "inconnu";
	statut_ = Occasionnel;
	tailleGroupe_ = 0;
}

/**
* Ce constructeur par param�tres initialise les attributs du client aux valeurs correspondantes.
*
* @param Son nom.
* @param Son pr�nom.
* @param La taille de son groupe.
*/
Client::Client(string nom, string prenom, int tailleGroupe) {
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	statut_ = Occasionnel;
}

/**
* Ce destructeur d�truit un client.
*/
Client::~Client() {}

/**
* Cette m�thode acc�de au statut du client.
*
* @return Le statut du client.
*/
StatutClient Client::getStatut()const {
	return statut_;
}

/**
* Cette m�thode acc�de au nom du client.
*
* @return Le nom du client.
*/
string Client::getNom()const {
	return nom_;
}

/**
* Cette m�thode acc�de au pr�nom du client.
*
* @return Le pr�nom du client.
*/
string Client::getPrenom()const {
	return prenom_;
}

/**
* Cette m�thode acc�de � la taille du groupe du client.
*
* @return La taille du groupe du client.
*/
int Client::getTailleGroupe()const {
	return tailleGroupe_;
}

/**
* Cette m�thode permet de convertir la valeur �num�r�e de statut_ en string.
*/
string Client::convertirStatutString() const{
	string statuts[3] = { "occasionnel","regulier","prestige" };
	return statuts[statut_];

}

/**
* Cette m�thode permet d'afficher le nom, le pr�nom et le statut du client.
*
* @param Le param�tre en sortie.
* @param Le client � afficher.
*
* @return La sortie.
*/
ostream & operator<<(ostream & os, const Client& client) {
	return(os << "\t -" << client.prenom_ << " " << client.nom_ << " statut: " << client.convertirStatutString());
	
}

