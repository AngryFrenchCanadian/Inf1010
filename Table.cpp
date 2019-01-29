#include "Table.h"
using namespace std;

	Table::Table() {
		capacite_ = MAXCAP;
		nbPlats_ = 0;
		id_ = -1;
		nbPlaces_ = 1;
		occupee_ = false;
		commande_ = new Plat*[MAXCAP];

	}
	
	Table::Table(int id, int nbPlaces) {
		capacite_ = MAXCAP;
		nbPlats_ = 0;
		id_ = id;
		nbPlaces_ = nbPlaces;
		occupee_ = true;
		commande_ = new Plat*[MAXCAP];
		
			
	}

	int Table::getId()const {
		return id_;
	}

	int Table::getNbPlaces()const {
		return nbPlaces_;
	}

	bool Table::estOccupee()const {
		return occupee_;
	}

	void Table::libererTable() {
		for (int i = 0; i < MAXCAP; i++) {
			delete commande_[i];
			commande_[i] = nullptr;
		}
		delete[] commande_;
		commande_ = nullptr;
	}

	void Table::placerClient() {

	}

	void Table::setId(int id) {
		id_ = id;
	}

	void Table::commander(Plat* plat) {
		commande_[nbPlats_++] = new Plat(plat->getNom, plat->getPrix, plat->getCout);

	}

	double Table::getChiffreAffaire() {
		double chiffreAffaire = 0;
		for (int i = 0; i < nbPlats_; i++) 
			chiffreAffaire += (commande_[i]->getPrix - commande_[i]->getCout);
		return chiffreAffaire;
		
	}

	void Table::afficher()const {
		for (int i = 0; i < nbPlats_; i++) {
			commande_[i]->afficher();
		}
	}
