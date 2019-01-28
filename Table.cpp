#include "Table.h"
using namespace std;

	Table::Table() {
	}
	
	Table::Table(int id, int nbPlaces) {
		id_ = id;
		nbPlaces_ = nbPlaces;
	}

	int Table::getId() {
		return id_;
	}

	int Table::getNbPlaces() {
		return nbPlaces_;
	}

	bool Table::estOccupee() {
		return occupee_;
	}

	void Table::libererTable() {

	}

	void Table::placerClients() {

	}

	void Table::setId(int Id) {

	}

	void Table::commander(Plat* plat) {

	}

	double Table::getChiffreAffaire() {

	}

	void Table::afficher() {

	}
