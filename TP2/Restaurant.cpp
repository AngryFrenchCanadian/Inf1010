/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifi� par : �tienne Bourgoin #1955553 et Manuel Pellerin #1960929
* Date : 08 f�vrier 2019
*/

#include "Restaurant.h"

/**
* Ce constructeur par d�faut initialise les attributs du restaurant aux valeurs par d�faut.
*/
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("polyFood.txt", Matin);
	menuMidi_ = new Menu("polyFood.txt", Midi);
	menuSoir_ = new Menu("polyFood.txt",  Soir);





}

/**
* Ce constructeur par param�tres initialise les attributs du restaurant aux valeurs correspondantes.
*
* @param Le fichier contenant le menu du restaurant par r�f�rence.
* @param Le nom du restaurant par r�f�rence.
* @param Le moment de la journ�e.
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
* Ce constructeur cr�e une copie du restaurant existant.
*
* @param Les informations du restaurant par r�f�rence.
*/
Restaurant::Restaurant(const Restaurant& resto) :chiffreAffaire_(resto.chiffreAffaire_),
	momentJournee_(resto.momentJournee_),menuMatin_(nullptr),
	menuMidi_(nullptr),menuSoir_(nullptr),nom_(nullptr)
{
	nom_ = new string(*resto.nom_);
	menuMatin_ = new Menu(*resto.menuMatin_);
	menuMidi_ = new Menu(*resto.menuMidi_);
	menuSoir_ = new Menu(*resto.menuSoir_);

	for (unsigned i = 0; i < resto.tables_.size(); i++) {
		Table* tableTemp = new Table(*resto.tables_[i]);
		tables_.push_back(tableTemp);
	}
}


//destructeur

/**
* Ce destructeur d�truit le restaurant.
*/

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

/**
* Cette m�thode permet de d�finir le moment de la journ�e.
*
* @param Le moment de la journ�e.
*/
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

/**
* Cette m�thode permet de d�finir le nom du restaurant.
*
* @param Le nom du restaurant par r�f�rence.
*/
void Restaurant::setNom(const string& nom) {
	*nom_ = nom;
}

/**
* Cette m�thode acc�de au nom du restaurant.
*
* @return Le pointeur vers le nom du restaurant.
*/
string Restaurant::getNom() const {
	return *nom_;
}

/**
* Cette m�thode acc�de au moment de la journ�e.
*
* @return Le moment de la journ�e.
*/
TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

/**
* Cette m�thode permet de lib�rer la table et d'ajouter le chiffre
* d'affaire de celle-ci au total du chiffre d'affaire du restaurant.
*
* @param Le num�ro de la table(id).
*/
void Restaurant::libererTable(int id) {
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->Table::libererTable();
			
		}
	}
}

/**
* Cette m�thode permet d'afficher le chiffre d'affaire du restaurant, ses tables et son menu.
*
* @param Le param�tre en sortie.
* @param Le restaurant � afficher par r�f�rence.
*
* @return La sortie.
*/
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

/**
* Cette m�thode permet d'ajouter un plat command� � une table
* en fonction du moment de la journ�e.
*
* @param Le nom du plat en r�f�rence.
* @param Le num�ro de la table (id).
*
* @see M�thode trouverPlat dans Menu.cpp (utilis�e).
* @see M�thode commander dans Table.cpp (utilis�e).
*/
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

/**
* Cette m�thode permet de lire les informations d'une table dans un fichier.
*
* @param Le fichier contenant une table du restaurant par r�f�rence.
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

/**
* Cette m�thode permet d'ajouter une table au restaurant.
*
* @param Le fichier contenant une table du restaurant par r�f�rence.
*
* @return Le restaurant avec la table ajout�e.
*/
Restaurant& Restaurant::operator+=(const Table& table) {
	tables_.push_back(new Table(table));
	return *this;
}

/**
* Cette m�thode permet de comparer les chiffres d'affaire de deux restaurants.
*
* @param Le restaurant 1 par r�f�rence.
* @param Le restaurant 2 par r�f�rence.
*
* @return Si le chiffre d'affaire du restaurant 1 est plus grand que celui du 2.
*/
bool operator<(const Restaurant& resto1, const Restaurant& resto2) {
	if (resto1.chiffreAffaire_ < resto2.chiffreAffaire_)
		return true;
	else
		return false;
}

/**
* Cette m�thode permet de mettre � jour le restaurant.
*
* @param Les informations du restaurant par r�f�rence.
*
* @return Le restaurant mis � jour.
*/
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

/**
* Cette m�thode permet de placer les clients � la table disponible ayant
* le moins de places tout en ayant assez de places pour le nombre de clients.
*
* @param Le nombre de clients � placer.
*/
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
