/*
* Titre : Client.cpp - Travail Pratique #4
* Date : 25 f�vrier 2019
* Auteur : AbdeB
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin #1960929
*/

#include "Client.h"

/**
* Ce constructeur par d�faut initialise les attributs du client aux valeurs par d�faut.
*/
Client::Client()
{ 
	tableOccupee_ = nullptr;
}

/**
* Ce constructeur par param�tres initialise les attributs du client aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prenom.
* @param La taille de son groupe.
*/
Client::Client(string_view nom, string_view prenom, int tailleGroupe) :
	nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe),tableOccupee_(nullptr)
{
}

/**
* Ce destructeur d�truit un client.
*/
Client::~Client() {
	
	tableOccupee_ = nullptr;
}

/**
* Cette m�thode acc�de � la taille du groupe du client.
*
* @return La taille du groupe du client.
*/
int Client::getTailleGroupe() const
{
	return tailleGroupe_;
}

/**
* Cette m�thode acc�de au nom du client.
*
* @return Le nom du client.
*/
string Client::getNom() const
{
	return nom_;
}

/**
* Cette m�thode acc�de au pr�nom du client.
*
* @return Le pr�nom du client.
*/
string Client::getPrenom() const
{
	return prenom_;
}

/**
* Cette m�thode permet de modifier le numero de table du client.
*
* @param Le numero de table du client.
*/
void Client:: setTable(Table* ta)
{ 
	tableOccupee_ = ta;
}

/**
* Cette m�thode acc�de au numero de table du client.
*
* @return Le numero de table du client.
*/
Table* Client:: getTable() const
{ 
	return tableOccupee_;
}

/**
* Cette m�thode permet d'afficher le nom, le pr�nom et la table du client.
*
* @param Le param�tre en sortie.
*/
void Client::afficherClient(ostream & os) const
{ 
	os << prenom_ << ' ' << nom_ << endl;
	if (tableOccupee_ != nullptr)
		os << *tableOccupee_;
	
}

