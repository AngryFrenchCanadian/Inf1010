#include "Restaurant.h"

//constructeurs 
Restaurant::Restaurant() {
	*nom_ = "inconnu";
	momentJournee_ = Matin;
	chiffreAffaire_ = 0;
	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	tables_ = new Table*[capaciteTables_];
	
}
Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment) {
	*nom_ = nom;
	momentJournee_ = moment;
	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	tables_ = new Table*[capaciteTables_];
}

//setters 
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

//getters 
string Restaurant::getNom()const {
	return *nom_;
}
TypeMenu Restaurant::getMoment()const {
	return momentJournee_;
}

//Autres methodes 
void Restaurant::lireTable(string& fichier) {

}
void Restaurant::ajouterTable(int id, int nbPlaces) {
	tables_[nbTables_++] = new Table(id, nbPlaces);
}
void Restaurant::libererTable(int id) {
	for (int i = 0; i < nbTables_; i++) {
		if (tables_[i]->getId == id) {
			tables_[i]->libererTable;
			for (int j = i; j < nbTables_ - 1; j++)
				tables_[i] = tables_[i + 1];
			nbTables_--;
			break;
		}
	}
}
void Restaurant::commanderPlat(string& nom, int idTable) {

}

void Restaurant::placerClients(int nbClients) {

}
//affichage 
void Restaurant::afficher()const {

}