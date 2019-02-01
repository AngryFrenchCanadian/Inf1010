#include "Table.h"
using namespace std;

/**
* Ce constructeur par défaut initialise les attributs de la table aux valeurs par défaut.
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
* Ce constructeur par paramètres initialise les attributs de la table aux valeurs correspondantes.
*
* @param Le numéro de la table (id).
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
* Ce destructeur détruit les commandes passées à la table.
*/
Table::~Table() {
	for (unsigned i = 0; i < nbPlats_; i++) {
		delete commande_[i];
		commande_[i] = nullptr;
	}
	delete[] commande_;
			
}

/**
* Cette méthode accède au numero de la table (id).
*
* @return Le numero de la table.
*/
int Table::getId()const {
	return id_;
}

/**
* Cette méthode accède au nombre de places de la table.
*
* @return Le nombre de places de la table.
*/
int Table::getNbPlaces()const {
	return nbPlaces_;
}

/**
* Cette méthode accède au booléen qui permet de savoir si la table est occupée par des clients.
*
* @return Si la table est occupée par des clients.
*/
bool Table::estOccupee()const {
	return occupee_;
}

/**
* Cette méthode efface les commandes passées à la table.
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
* Cette méthode permet de placer un client à une table et la rendre occupée.
*/
void Table::placerClient() {
	occupee_ = true;
}

/**
* Cette méthode permet de créer le numéro d'une table (id).
*/
void Table::setId(int id) {
	id_ = id;
}

/**
* Cette méthode permet d'ajouter un plat à la commande d'une table.
*/
void Table::commander(Plat* plat) {
	commande_[nbPlats_++] = new Plat(plat->getNom(), plat->getPrix(), plat->getCout());

}

/**
* Cette méthode permet de calculer le chiffre d'affaire des commandes d'une table.
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
* Cette méthode permet d'afficher l'état d'une table et d'afficher les plats qui ont été
* commandés pour celle-ci.
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
