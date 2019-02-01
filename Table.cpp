#include "Table.h"
using namespace std;

/**
* Ce constructeur par d�faut initialise les attributs de la table aux valeurs par d�faut.
*/
Table::Table() {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];

}

/**
* Ce constructeur par param�tres initialise les attributs de la table aux valeurs correspondantes.
*
* @param Le num�ro de la table (id).
* @param Le nombre de places de la table.
*/
Table::Table(int id, int nbPlaces) {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = id;
	nbPlaces_ = nbPlaces;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
		
			
}

/**
* Ce destructeur d�truit les commandes pass�es � la table.
*/
Table::~Table() {
	for (unsigned i = 0; i < nbPlats_; i++) {
		delete commande_[i];
		commande_[i] = nullptr;
	}
	delete[] commande_;
			
}

/**
* Cette m�thode acc�de au numero de la table (id).
*
* @return Le numero de la table.
*/
int Table::getId()const {
	return id_;
}

/**
* Cette m�thode acc�de au nombre de places de la table.
*
* @return Le nombre de places de la table.
*/
int Table::getNbPlaces()const {
	return nbPlaces_;
}

/**
* Cette m�thode acc�de au bool�en qui permet de savoir si la table est occup�e par des clients.
*
* @return Si la table est occup�e par des clients.
*/
bool Table::estOccupee()const {
	return occupee_;
}

/**
* Cette m�thode efface les commandes pass�es � la table.
*/
void Table::libererTable() {
	for (int i = 0; i < MAXCAP; i++) {
		delete commande_[i];
		commande_[i] = nullptr;
	}
	delete[] commande_;
	commande_ = nullptr;
}

/**
* Cette m�thode permet de placer un client � une table et la rendre occup�e.
*/
void Table::placerClient() {
	occupee_ = true;
}

/**
* Cette m�thode permet de cr�er le num�ro d'une table (id).
*/
void Table::setId(int id) {
	id_ = id;
}

/**
* Cette m�thode permet d'ajouter un plat � la commande d'une table.
*/
void Table::commander(Plat* plat) {
	commande_[nbPlats_++] = new Plat(plat->getNom(), plat->getPrix(), plat->getCout());

}

/**
* Cette m�thode permet de calculer le chiffre d'affaire des commandes d'une table.
*
* @return Le chiffre d'affaire des commandes d'une table.
*/
double Table::getChiffreAffaire() {
	double chiffreAffaire = 0;
	for (unsigned i = 0; i < nbPlats_; i++) 
		chiffreAffaire += (commande_[i]->getPrix() - commande_[i]->getCout());
	return chiffreAffaire;
		
}

/**
* Cette m�thode permet d'afficher l'�tat d'une table et d'afficher les plats qui ont �t�
* command�s pour celle-ci.
*/
void Table::afficher()const {
	cout << "	La table numero " << id_ << " est ";

	if (occupee_ == true) {
		cout << "occupee.";
		if (nbPlats_ != 0) {
			cout << " Voici la commande passee par les clients. \n";
			for (unsigned i = 0; i < nbPlats_; i++) {
				commande_[i]->afficher();
			}
		}
		else
			cout << " Mais ils n'ont rien commande pour l'instant. \n";
	}

	else
		cout << "libre.\n";
	//pour le formating
	cout << "\n";
}
