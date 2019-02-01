#include "Restaurant.h"

//constructeurs 
Restaurant::Restaurant() {
	nom_ =new string("inconnu");
	momentJournee_ = Matin;
	chiffreAffaire_ = 0;
	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	tables_ = new Table*[INTTABLES];
	
	
}
Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment) {
	nom_ =new string(nom);
	momentJournee_ = moment;
	chiffreAffaire_ = 0;
	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu(fichier, Soir);
	tables_ = new Table*[INTTABLES];
	lireTable(fichier);
}

//destructeur
Restaurant::~Restaurant() {
	delete nom_; nom_ = nullptr;

	//delete tables
	for (unsigned i = 0; i < nbTables_; i++) {
		tables_[i]->~Table();
	}
	delete[] tables_;
	tables_ = nullptr;

	//delete menus

	menuMatin_->~Menu(); menuMatin_ = nullptr;
	menuMidi_->~Menu(); menuMidi_ = nullptr;
	menuSoir_->~Menu(); menuSoir_ = nullptr;

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
void Restaurant::lireTable(const string& fichier) {
	string ligneLue;
	int idTampon; int nbPlacesTampon;

	ifstream fichierLu(fichier, ios::beg);

	//aftin de determiner ou debuter la lecture
	while (ligneLue != "-TABLES")
		getline(fichierLu, ligneLue);
	//lecture des tables
	while (!ws(fichierLu).eof()) {
		fichierLu >> idTampon >> nbPlacesTampon;
		tables_[nbTables_++] = new Table(idTampon, nbPlacesTampon);
	}
	fichierLu.close();
}

void Restaurant::ajouterTable(int id, int nbPlaces) {
	tables_[nbTables_++] = new Table(id, nbPlaces);
}


void Restaurant::libererTable(int id) {
	Table* pointeurTampon;
	for (unsigned i = 0; i < nbTables_; i++) {
		if (tables_[i]->getId() == id) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			pointeurTampon = tables_[i];
			tables_[i] = new Table(pointeurTampon->getId(),pointeurTampon->getNbPlaces());
			delete pointeurTampon; pointeurTampon = nullptr;
		}
	}
}
void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* ptrPlatTampon;

	//cherche le plat dans le menu approprie. ptrPlatTampon = nullptr si le plat est invalide
	switch (momentJournee_) {
	case Matin: ptrPlatTampon = menuMatin_->trouverPlat(nom);
		break;
	case Midi:  ptrPlatTampon = menuMidi_->trouverPlat(nom);
		break;
	case Soir:  ptrPlatTampon = menuSoir_->trouverPlat(nom);
		break;
	}


	for (unsigned i = 0; i < nbTables_; i++) {
		//verifie que la table est occuppee et que le plat est valide
		if (tables_[i]->getId() == idTable && ptrPlatTampon != nullptr) {
			tables_[i]->commander(ptrPlatTampon);
			return;
		}
		
	}
	cout << "Erreur : table non occupee ou plat introuvable \n";
}

void Restaurant::placerClients(int nbClients) {
	for (unsigned i = 0; i < nbTables_; i++) {
		//verifie que la table est libre et que le nb de places soit suffisant
		if (tables_[i]->estOccupee() == false && tables_[i]->getNbPlaces() >= nbClients) {
			tables_[i]->placerClient();
			return;
		}
	}
	cout << "Erreur : Il n'y a plus/pas de place disponible pour le client\n";
}
//affichage 
void Restaurant::afficher()const {

	//affichage chiffre d'affaire
	if (chiffreAffaire_ <= 0) {
		cout << "Le restaurant " << *nom_ 
			<< " n'a pas fait de benefice ou le chiffre d'affaire n'est pas encore calcule.\n";
	}
	else {
		cout << "Le restaurant " << *nom_
			<< "a fait un chiffre d'affaire de : " << chiffreAffaire_ << "$\n";
	}

	//affichage des tables
	cout << "Voice les tables : \n";
	for (unsigned i = 0; i < nbTables_; i++) 
		tables_[i]->afficher();
			

	//affichage des menus
	cout << "Voici son menu: \n" << "Matin :\n";
	menuMatin_->afficher();
	cout << "Midi : \n";
	menuMidi_->afficher();
	cout << "Soir :\n";
	menuSoir_->afficher();
}