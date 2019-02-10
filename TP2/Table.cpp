/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifi� par : �tienne Bourgoin #1955553 et Manuel Pellerin #1960929
* Date : 08 f�vrier 2019
*/

#include "Table.h"

/**
* Ce constructeur par d�faut initialise les attributs de la table aux valeurs par d�faut.
*/
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

/**
* Ce constructeur par param�tres initialise les attributs de la table aux valeurs correspondantes.
*
* @param Le num�ro de la table (id).
* @param Le nombre de places de la table.
*/
Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}



/**
* Cette m�thode acc�de au numero de la table (id).
*
* @return Le numero de la table.
*/
int Table::getId() const {
	return id_;
}

/**
* Cette m�thode acc�de au nombre de places de la table.
*
* @return Le nombre de places de la table.
*/
int Table::getNbPlaces() const {
	return nbPlaces_;
}

/**
* Cette m�thode acc�de au nombre de clients de la table.
*
* @return Le nombre de clients de la table.
*/
int Table::getnbClientATable() const
{
	return nbClientsATable_;
}

/**
* Cette m�thode acc�de au bool�en qui permet de savoir si la table est pleine.
*
* @return Si la table est pleine.
*/
bool Table::estPleine() const {
	return nbPlaces_==0;
}

/**
* Cette m�thode acc�de au bool�en qui permet de savoir si la table est occup�e par des clients.
*
* @return Si la table est occup�e par des clients.
*/
bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

/**
* Cette m�thode permet de cr�er le num�ro d'une table (id).
*
* @param Le num�ro de la table.
*/
void Table::setId(int id) {
	id_ = id;
}

/**
* Cette m�thode lib�re la table et efface les commandes pass�es � celle-ci.
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
* Cette m�thode permet de placer un client � une table et la rendre occup�e.
*
* @param Le nombre de clients plac�s � la table.
*/
void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

/**
* Cette m�thode permet d'ajouter un plat � la commande d'une table.
*
* @param Le pointeur vers le plat � ajouter.
*/
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

/**
* Cette m�thode permet de calculer le chiffre d'affaire des commandes d'une table.
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
* Cette m�thode permet d'afficher l'�tat d'une table et d'afficher les plats qui ont �t�
* command�s pour celle-ci.
*
* @param Le param�tre en sortie.
* @param La table � afficher par r�f�rence.
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


