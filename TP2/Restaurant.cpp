/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Restaurant.h"

/**
* Ce constructeur par défaut initialise les attributs du restaurant aux valeurs par défaut.
*/
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);
}

/**
* Ce constructeur par paramètres initialise les attributs du restaurant aux valeurs correspondantes.
*
* @param Le fichier contenant le menu du restaurant par référence.
* @param Le nom du restaurant par référence.
* @param Le moment de la journée.
*/
Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);

	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);


	
	lireTable(fichier);
}

/**
* Ce destructeur détruit le restaurant.
*/
Restaurant::~Restaurant() {
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;

	for (int i = 0; i <tables_.size() ; i++)
		delete tables_[i];
	tables_.clear();
}

/**
* Cette méthode permet de définir le moment de la journée.
*
* @param Le moment de la journée.
*/
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

/**
* Cette méthode permet de définir le nom du restaurant.
*
* @param Le nom du restaurant par référence.
*/
void Restaurant::setNom(const string& nom) {
	*nom_ = nom;
}

/**
* Cette méthode accède au nom du restaurant.
*
* @return Le pointeur vers le nom du restaurant.
*/
string Restaurant::getNom() const {
	return *nom_;
}

/**
* Cette méthode accède au moment de la journée.
*
* @return Le moment de la journée.
*/
TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

/**
* Cette méthode permet de libérer la table et d'ajouter le chiffre
* d'affaire de celle-ci au total du chiffre d'affaire du restaurant.
*
* @param Le numéro de la table(id).
*/
void Restaurant::libererTable(int id) {
	for (int i = 0; i < tables_.size(); i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
		}
	}
}

/**
* Cette méthode permet d'afficher le chiffre d'affaire du restaurant, ses tables et son menu.
*
* @param Le paramètre en sortie.
* @param Le restaurant à afficher par référence.
*
* @return La sortie.
*/
ostream& operator<<(ostream& o, const Restaurant& resto){
	cout << "Le restaurant " << *resto.nom_;
	if (resto.chiffreAffaire_ != 0)
		cout << " a fait un chiffre d'affaire de : " << resto.chiffreAffaire_ << "$" << endl;
	else
		cout << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	cout << "-Voici les tables : " << endl;
	for (int i = 0; i < resto.tables_.size(); i++) {
		cout << "\t" << resto.tables_[i] << endl;
		
	}
	cout << endl;


	cout << "-Voici son menu : " << endl;
	cout << "Matin : " << endl <<resto.menuMatin_;
	cout << "Midi : " << endl << resto.menuMidi_;
	cout << "Soir : " << endl << resto.menuSoir_;

	return o;
}

/**
* Cette méthode permet d'ajouter un plat commandé à une table
* en fonction du moment de la journée.
*
* @param Le nom du plat en référence.
* @param Le numéro de la table (id).
*
* @see Méthode trouverPlat dans Menu.cpp (utilisée).
* @see Méthode commander dans Table.cpp (utilisée).
*/
void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (int i = 0; i < tables_.size(); i++) {
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
		tables_[index]->commander(plat);
	}
	else cout << "Erreur : table non occupee ou plat introuvable" << endl;
}

/**
* Cette méthode permet de lire les informations d'une table dans un fichier.
*
* @param Le fichier contenant une table du restaurant par référence.
*/
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
					for (int i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}

					id = stoi(idString);

					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);

					ajouterTable(id, nbPersonnes);
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}


void Restaurant::ajouterTable(int id, int nbPlaces) {
	// A MODIFIER
	if (nbTables_ == capaciteTables_) {
		capaciteTables_ *= 2;
		Table** temp = new Table*[capaciteTables_];

		for (int i = 0; i < nbTables_; i++) {
			temp[i] = tables_[i];
		}

		delete[] tables_;
		tables_ = temp;

	}

	tables_[nbTables_] = new Table(id, nbPlaces);
	nbTables_++;
}

void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;


	for (int i = 0; i < nbTables_; i++) {
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
