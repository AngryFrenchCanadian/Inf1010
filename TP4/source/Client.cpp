/*
* Date : 25 février 2019
* Auteur : AbdeB
*/

#include "Client.h"

/**
* Ce constructeur par défaut initialise les attributs du client aux valeurs par défaut.
*/
Client::Client()
{ 
	tableOccupee_ = nullptr;
}

/**
* Ce constructeur par paramètres initialise les attributs du client aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prenom.
* @param La taille de son groupe.
*/
Client::Client(string_view nom, string_view prenom, int tailleGroupe) :
	nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe)
{
    tableOccupee_ = nullptr;
}

/**
* Ce destructeur détruit un client.
*/
Client::~Client() {}

/**
* Cette méthode accède à la taille du groupe du client.
*
* @return La taille du groupe du client.
*/
int Client::getTailleGroupe() const
{
	return tailleGroupe_;
}

/**
* Cette méthode accède au nom du client.
*
* @return Le nom du client.
*/
string Client::getNom() const
{
	return nom_;
}

/**
* Cette méthode accède au prénom du client.
*
* @return Le prénom du client.
*/
string Client::getPrenom() const
{
	return prenom_;
}

/**
* Cette méthode permet de modifier le numero de table du client.
*
* @param Le numero de table du client.
*/
void Client:: setTable(Table* ta)
{ 
	tableOccupee_ = ta;
}

/**
* Cette méthode accède au numero de table du client.
*
* @return Le numero de table du client.
*/
Table* Client:: getTable() const
{ 
	return tableOccupee_;
}

/**
* Cette méthode permet d'afficher le nom, le prénom et la table du client.
*
* @param Le paramètre en sortie.
*/
void Client::afficherClient(ostream & os) const
{ 
	if (tableOccupee_ != nullptr) {
		os << "La table numero " << tableOccupee_ << " est occupee. Le client principal est: " << endl <<
			prenom_ << nom_ << endl;
	}
}

