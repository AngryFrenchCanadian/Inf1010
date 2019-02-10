/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifié par : Étienne Bourgoin #1955553 et Manuel Pellerin #1960929
* Date : 08 février 2019
*/

#include "Table.h"

/**
* Ce constructeur par défaut initialise les attributs de la table aux valeurs par défaut.
*/
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

/**
* Ce constructeur par paramètres initialise les attributs de la table aux valeurs correspondantes.
*
* @param Le numéro de la table (id).
* @param Le nombre de places de la table.
*/
Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}



/**
* Cette méthode accède au numero de la table (id).
*
* @return Le numero de la table.
*/
int Table::getId() const {
	return id_;
}

/**
* Cette méthode accède au nombre de places de la table.
*
* @return Le nombre de places de la table.
*/
int Table::getNbPlaces() const {
	return nbPlaces_;
}

/**
* Cette méthode accède au nombre de clients de la table.
*
* @return Le nombre de clients de la table.
*/
int Table::getnbClientATable() const
{
	return nbClientsATable_;
}

/**
* Cette méthode accède au booléen qui permet de savoir si la table est pleine.
*
* @return Si la table est pleine.
*/
bool Table::estPleine() const {
	return nbPlaces_==0;
}

/**
* Cette méthode accède au booléen qui permet de savoir si la table est occupée par des clients.
*
* @return Si la table est occupée par des clients.
*/
bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

/**
* Cette méthode permet de créer le numéro d'une table (id).
*
* @param Le numéro de la table.
*/
void Table::setId(int id) {
	id_ = id;
}

/**
* Cette méthode libère la table et efface les commandes passées à celle-ci.
*/
void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	for (unsigned i = 0; i < commande_.size(); i++) {
		delete commande_[i];
		commande_[i] = nullptr;
	}
	commande_.clear();


}

/**
* Cette méthode permet de placer un client à une table et la rendre occupée.
*
* @param Le nombre de clients placés à la table.
*/
void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

/**
* Cette méthode permet d'ajouter un plat à la commande d'une table.
*
* @param Le pointeur vers le plat à ajouter.
*/
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

/**
* Cette méthode permet de calculer le chiffre d'affaire des commandes d'une table.
*
* @return Le chiffre d'affaire des commandes d'une table.
*/
double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (unsigned i = 0; i < commande_.size(); i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

/**
* Cette méthode permet d'afficher l'état d'une table et d'afficher les plats qui ont été
* commandés pour celle-ci.
*
* @param Le paramètre en sortie.
* @param La table à afficher par référence.
*
* @return La sortie.
*/
ostream& operator<<(ostream& o, const Table& table) {
	o << "La table numero " << table.id_;
	if (table.estOccupee()) {
		o << " est occupee. :";
		if (table.commande_.size() != 0) {
			o << "Voici la commande passee par les clients : \n";
			for (unsigned i = 0; i < table.commande_.size(); i++) {
				o << "\t" << *table.commande_[i];
			}

		}
		else
			o << "Mais ils n'ont rien commande pour l'instant. \n";
	}
	else
		o << " est libre. \n";
	
	return o;
}


