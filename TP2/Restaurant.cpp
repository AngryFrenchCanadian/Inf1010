/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("polyFood.txt", Matin);
	menuMidi_ = new Menu("polyFood.txt", Midi);
	menuSoir_ = new Menu("polyFood.txt",  Soir);





}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);

	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);


	
	lireTable(fichier);
}

Restaurant::Restaurant(const Restaurant& resto) :chiffreAffaire_(resto.chiffreAffaire_),
	momentJournee_(resto.momentJournee_),menuMatin_(nullptr),
	menuMidi_(nullptr),menuSoir_(nullptr),nom_(nullptr)
{
	nom_ = new string(*resto.nom_);
	menuMatin_ = new Menu(*resto.menuMatin_);
	menuMidi_ = new Menu(*resto.menuMidi_);
	menuSoir_ = new Menu(*resto.menuSoir_);

	for (unsigned i = 0; i < resto.tables_.size(); i++) {
		Table* tableTemp = new Table(resto.tables_[i]->getId(),
			resto.tables_[i]->getNbPlaces());
		tables_.push_back(tableTemp);
	}
}
//destructeur
Restaurant::~Restaurant() {
	delete nom_; nom_ = nullptr;
	delete menuMatin_; menuMatin_ = nullptr;
	delete menuMidi_; menuMidi_ = nullptr;
	delete menuSoir_; menuSoir_ = nullptr;

	for (unsigned i = 0; i < tables_.size(); i++) {
		libererTable(tables_[i]->getId());
	}

	
	tables_.clear();
}


//setter

void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

void Restaurant::setNom(const string& nom) {
	*nom_ = nom;
}
//getters
string Restaurant::getNom() const {
	return *nom_;
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

//autres methodes


void Restaurant::libererTable(int id) {
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->Table::libererTable();
			
		}
	}
}


ostream& operator<<(ostream& o, const Restaurant& resto){
	cout << "Le restaurant " << *resto.nom_;
	if (resto.chiffreAffaire_ != 0)
		cout << " a fait un chiffre d'affaire de : " << resto.chiffreAffaire_ << "$\n";
	else
		cout << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule.\n" ;
	cout << "-Voici les tables : \n" ;
	for (unsigned i = 0; i < resto.tables_.size(); i++) {
		cout << "\t" << *resto.tables_[i] << '\n';
		
	}
	cout << endl;


	cout << "-Voici son menu : \n" ;
	cout << "Matin : \n"  <<*resto.menuMatin_;
	cout << "Midi : \n"  << *resto.menuMidi_;
	cout << "Soir : \n"  << *resto.menuSoir_;
	return o;
}

void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (idTable == tables_[i]->getId()) {
			index = i;
			switch (momentJournee_) {
			case Matin :
				plat = menuMatin_->trouverPlat(nom);
				break;
			case Midi :
				plat = menuMidi_->trouverPlat(nom);
				break;
			case Soir :
				plat = menuSoir_->trouverPlat(nom);
				break;
			}
		}
	}
	if (plat != nullptr && tables_[index]->estOccupee()) {
		tables_[index]->commander(new Plat(plat->getNom(), plat->getPrix(),
			plat->getCout()));
	}
	else cout << "Erreur : table non occupee ou plat introuvable\n" ;
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne;

		string idString;
		int id;

		string nbPersonnesString;
		int nbPersonnes;

		int curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-TABLES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (unsigned i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}

					id = stoi(idString);

					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);

					*this+= Table(id, nbPersonnes);
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}

Restaurant& Restaurant::operator+=(const Table& table) {
	tables_.push_back(new Table(table));
	return *this;
}

bool operator<(const Restaurant& resto1, const Restaurant& resto2) {
	if (resto1.chiffreAffaire_ < resto2.chiffreAffaire_)
		return true;
	else
		return false;
}

Restaurant& Restaurant::operator=(const Restaurant& resto) {
	if (this != &resto) {
		
		delete menuMatin_;
		delete menuMidi_;
		delete menuSoir_;

		for (unsigned i = 0; i < tables_.size(); i++) {
			delete tables_[i];

		}
		tables_.clear();

		
		chiffreAffaire_ = resto.chiffreAffaire_;
		momentJournee_ = resto.momentJournee_;
		menuMatin_ = new Menu(*resto.menuMatin_);
		menuMidi_ = new Menu(*resto.menuMidi_);
		menuSoir_ = new Menu(*resto.menuSoir_);

		tables_ = resto.tables_;

	}
	return *this;
}
void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;


	for (unsigned i = 0; i < tables_.size(); i++) {
		if (tables_[i]->getNbPlaces() >= nbClients && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client. " << endl;
	}else
	tables_[indexTable]->placerClient(nbClients);
}
