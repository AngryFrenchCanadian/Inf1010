/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Table.h"

//constructeurs
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}



//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

int Table::getnbClientATable() const
{
	return nbClientsATable_;
}

bool Table::estPleine() const {
	return nbPlaces_==0;
}

bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

//setters
void Table::setId(int id) {
	id_ = id;
}

void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	
	for (int i = 0; i < commande_.size(); i++) {
		delete commande_[i];
	}
	commande_.clear();

}

void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

//autres methodes
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (int i = 0; i < commande_.size(); i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}
//affichage
ostream& operator<<(ostream& o, const Table& table) {
	o << "La table numero " << table.id_;
	if (table.estOccupee()) {
		o << " est occupee. :";
		if (table.commande_.size() != 0) {
			o << "Voice la commande passee par les clients : \n";
			for (int i = 0; i < table.commande_.size(); i++) {
				o << "\t" << *table.commande_[i];
			}

		}
		else
			o << "Mais ils n'ont riend commande pour l'instant. \n";
	}
	else
		o << "est libre. \n";
}


