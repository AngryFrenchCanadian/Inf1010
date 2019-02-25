/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 11 Février 2019
* Auteur : Fatou S. MOUNZEO
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
	lireAdresses(fichier);
}

/**
* Ce constructeur crée une copie du restaurant existant.
*
* @param Les informations du restaurant par référence.
*/
Restaurant::Restaurant(const Restaurant & restau) : nom_(new string(*restau.nom_)),
chiffreAffaire_(restau.chiffreAffaire_),
momentJournee_(restau.momentJournee_),
menuMatin_(new Menu(*restau.menuMatin_)),
menuMidi_(new Menu(*restau.menuMidi_)),
menuSoir_(new Menu(*restau.menuSoir_))
{
	tables_.clear();
	for (unsigned i = 0; i < restau.tables_.size(); ++i)
		tables_.push_back(new Table(*restau.tables_[i]));
	for (unsigned i = 0; i < NB_ZONES_LIVR; i++) 
		fraisTransport_[i] = restau.getFraisTransports(i);


}

/**
* Ce destructeur détruit le restaurant.
*/
Restaurant::~Restaurant() {
	delete nom_; 
	delete menuMatin_; 
	delete menuMidi_; 
	delete menuSoir_; 
	for (unsigned i = 0; i < tables_.size(); ++i)
		delete tables_[i];

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
void Restaurant::setNom(const string & nom)
{
	nom_ = new string(nom);
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
* Cette méthode accède au frais de transport pour une table.
*
* @param L'index de la table de livraison.
*
* @return Le frais de transport pour la table de livraison.
*/
double Restaurant::getFraisTransports(int index) const
{
	return fraisTransport_[index];
}

/**
* Cette méthode permet de libérer la table et d'ajouter le chiffre
* d'affaire de celle-ci au total du chiffre d'affaire du restaurant.
*
* @param Le numéro de la table(id).
*/
void Restaurant::libererTable(int id) {

	for (unsigned i = 0; i < tables_.size(); ++i) {
		if (id == tables_[i]->getId()) {
			double chiffreAffaireTable = tables_[i]->getChiffreAffaire();
			chiffreAffaire_ += chiffreAffaireTable - calculerReduction(tables_[i]->getClientPrincipal(),
				chiffreAffaireTable, tables_[i]->getClientPrincipal()->getStatut() == Prestige);
			tables_[i]->libererTable(); 

			break;
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
ostream& operator<<(ostream& os, const Restaurant& restau)
{
	os << "Le restaurant " << *restau.nom_;
	if (restau.chiffreAffaire_ != 0)
		os << " a fait un chiffre d'affaire de : " << restau.chiffreAffaire_ << "$" << endl;
	else
		os << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;

	os << "-Voici les tables : " << endl;

	for (unsigned i = 0; i < restau.tables_.size(); i++) {
		os  << *restau.tables_[i] << endl;
	}
	os << endl;


	os << "-Voici son menu : " << endl;
	os << "Matin : " << endl
		<<*restau.menuMatin_<<endl << "Le plat le moins cher est : " << *restau.menuMatin_->trouverPlatMoinsCher() << endl;

	os << "Midi : " << endl
		<< *restau.menuMidi_<<endl << "Le plat le moins cher est : " << *restau.menuMidi_->trouverPlatMoinsCher() << endl;
	os << "Soir : " << endl
		<< *restau.menuSoir_<<endl << "Le plat le moins cher est : " << *restau.menuSoir_->trouverPlatMoinsCher() <<endl;


	return os;
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
void Restaurant::commanderPlat(const string& nom, int idTable,TypePlat type, int nbIngredients) {

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

			break;
		}
	}

	if (plat == nullptr || !tables_[index]->estOccupee()) {

		cout << "Erreur : table vide ou plat introuvable" << endl << endl;
	}
	else if(type == Custom)
	{
		
		tables_[index]->commander(new PlatCustom(plat->getNom(), plat->getPrix(),
			plat->getCout(), nbIngredients));
	}
	else
		tables_[index]->commander(plat);

 
}

/**
* Cette méthode permet de comparer les chiffres d'affaire de deux restaurants.
*
* @param Le restaurant 1 par référence.
* @param Le restaurant 2 par référence.
*
* @return Si le chiffre d'affaire du restaurant 1 est plus grand que celui du 2.
*/
bool Restaurant::operator<(const Restaurant & restau) const 
{
	return this->chiffreAffaire_ < restau.chiffreAffaire_;
}

/**
* Cette méthode permet de mettre à jour le restaurant.
*
* @param Les informations du restaurant par référence.
*
* @return Le restaurant mis à jour.
*/
Restaurant & Restaurant::operator=(const Restaurant & restau)
{
	if (this != &restau)
	{
		chiffreAffaire_ = restau.chiffreAffaire_;
		momentJournee_ = restau.momentJournee_;
		menuMatin_ = new Menu(*restau.menuMatin_);
		menuMidi_ = new Menu(*restau.menuMidi_);
		menuSoir_ = new Menu(*restau.menuSoir_);
		for (unsigned i = 0; i < tables_.size(); ++i)
			delete tables_[i];

		tables_.clear();
		for (unsigned i = 0; i < restau.tables_.size(); ++i)
			tables_.push_back(new Table(*restau.tables_[i]));
		for (unsigned i = 0; i < NB_ZONES_LIVR; i++)
			fraisTransport_[i] = restau.getFraisTransports(i);

	}

	return *this;
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
		while ( !file.eof()) {
			getline(file, ligne); 
			if (ligne == "-TABLES") {
					getline(file, ligne); 
				do {
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

					*this+= new Table(id, nbPersonnes); 
					nbPersonnesString = ""; 
					idString = ""; 					
					getline(file, ligne);

				} while (ligne[0] != '-' && !file.eof());
			}
		}
		file.close(); 
	}
}

/**
* Cette méthode permet d'ajouter une table au restaurant.
*
* @param Le fichier contenant une table du restaurant par référence.
*
* @return Le restaurant avec la table ajoutée.
*/
Restaurant& Restaurant::operator+=(Table* table) {
	tables_.push_back(new Table(*table)); 
	return *this;
}

/**
* Cette méthode permet de placer les clients à la table disponible ayant
* le moins de places tout en ayant assez de places pour le nombre de clients.
*
* @param Le nombre de clients à placer.
*/
void Restaurant::placerClients(Client* client) {

	int indexTable = -1;
	int minimum = 100;

	for (unsigned i = 0; i < tables_.size(); i++) {
		if (tables_[i]->getNbPlaces() >= client->getTailleGroupe() && !tables_[i]->estOccupee() 
			&& tables_[i]->getNbPlaces() < minimum && i != INDEX_TABLE_LIVRAISON) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour les clients. " << endl;
	}
	else {
		tables_[indexTable]->placerClients(client->getTailleGroupe());
		tables_[indexTable]->setClientPrincipal(client);
	}
}


	/**
	* Cette méthode permet de livrer le repas au client s'il a accès à ce service.
	*
	* @param Le nom du client.
	* @param La commande du client.
	*/

void Restaurant::livrerClient(Client * client, vector<string> commande, int nbIngredients)
{

	if (client->getStatut() == Prestige) {
		tables_[INDEX_TABLE_LIVRAISON]->placerClients(1);
		tables_[INDEX_TABLE_LIVRAISON]->setClientPrincipal(client);
		for (unsigned i = 0; i < commande.size(); i++) {
			if( nbIngredients != 0)
				commanderPlat(commande[i], tables_[INDEX_TABLE_LIVRAISON]->getId(), Custom, nbIngredients);
			else
				commanderPlat(commande[i], tables_[INDEX_TABLE_LIVRAISON]->getId());
		}
		
		cout << "Statut de la table de livraison: (table numero "
			<< tables_[INDEX_TABLE_LIVRAISON]->getId() << "):"
			<< endl << *tables_[INDEX_TABLE_LIVRAISON] << "Livraison terminee" << endl << endl;
		libererTable(tables_[INDEX_TABLE_LIVRAISON]->getId());
	}
	else {
		cout << "Le client " << client->getNom() << " n'est pas admissible a la livraison"
			<< endl << endl;
	}
	

}

/**
* Cette méthode permet de calculer la réduction du client s'il a accès à ce service.
*
* @param Le nom du client.
* @param Le montant de la commande du client.
* @param Si le client a commandé pour une livraison.
*/
double Restaurant::calculerReduction(Client* client, double montant, bool livraison) {
	if (client->getStatut() == Regulier) {
		ClientRegulier* clientReg = nullptr;
		clientReg = static_cast<ClientRegulier*>(client);
		if (clientReg->getNbPoints() > SEUIL_DEBUT_REDUCTION)
			return montant * TAUX_REDUC_REGULIER;
	}
		
	if (client->getStatut() == Prestige) {
		ClientPrestige* clientPrest = nullptr;
		clientPrest = static_cast<ClientPrestige*>(client);
		if (clientPrest->getNbPoints() < SEUIL_LIVRAISON_GRATUITE && livraison == true)
			return montant * TAUX_REDUC_PRESTIGE -
			getFraisTransports(clientPrest->getAdresseCode());
		else
			return montant * TAUX_REDUC_PRESTIGE;
	}
	return 0;
 }

/**
* Cette méthode permet de lire les frais de transport en fonction des adresses.
*
* @param Le fichier contenant les frais de transport. 
*/
void Restaurant::lireAdresses(const string & fichier)
{
	ifstream file(fichier, ios::in);

		if (file) {
			string ligne;

			string addresseCodeStr;
			int addressCode;

			string fraisStrg;
			double frais;

			int curseur;
			while (!file.eof()) {
				getline(file, ligne);
				if (ligne == "-ADDRESSES") {
					while (!file.eof()) {
						getline(file, ligne);
						for (unsigned i = 0; i < ligne.size(); i++) {
							if (ligne[i] == ' ') {
								curseur = i;
								break;
							}
							addresseCodeStr += ligne[i];
							addressCode = stoi(addresseCodeStr);

						}


						fraisStrg = ligne.substr(curseur + 1);
						frais = stod(fraisStrg);
						fraisTransport_[addressCode] = frais;

						addresseCodeStr = "";
						fraisStrg = "";



					}

					
				}
			}
			file.close();
		}
	}


