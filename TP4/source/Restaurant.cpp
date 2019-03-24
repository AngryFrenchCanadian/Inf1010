/*
* Titre : Restaurant.cpp - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*/

#include "Restaurant.h"
#include "LectureFichierEnSections.h"
#include "debogageMemoire.hpp"
#include <cassert>
using namespace std;

/**
* Ce constructeur par défaut initialise les attributs du restaurant aux valeurs par défaut.
*/
Restaurant::Restaurant() :
	Restaurant{"menu.txt", "Inconnu", TypeMenu::Matin}
{
}

/**
* Ce constructeur par paramètres initialise les attributs du restaurant aux valeurs correspondantes.
*
* @param Le fichier contenant le menu du restaurant par référence.
* @param Le nom du restaurant par référence.
* @param Le moment de la journée.
*/
Restaurant::Restaurant(const string& nomFichier, string_view nom, TypeMenu moment) :
	nom_{nom},
	momentJournee_{moment},
	chiffreAffaire_{0},
	menuMatin_{new Menu{nomFichier, TypeMenu::Matin}},
	menuMidi_ {new Menu{nomFichier, TypeMenu::Midi }},
	menuSoir_ {new Menu{nomFichier, TypeMenu::Soir }},
	fraisLivraison_{}
{
	lireTables(nomFichier); 
	lireAdresses(nomFichier);
}

/**
* Ce destructeur détruit le restaurant.
*/
Restaurant::~Restaurant()
{
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	for (Table* table : tables_)
		delete table;
}

/**
* Cette méthode permet de définir le moment de la journée.
*
* @param Le moment de la journée.
*/
void Restaurant::setMoment(TypeMenu moment)
{
	momentJournee_ = moment; 
}

/**
* Cette méthode permet de définir le nom du restaurant.
*
* @param Le nom du restaurant par référence.
*/
void Restaurant::setNom(string_view nom)
{
	nom_ = nom;
}

/*
*Cette méthode permet de définir le chiffre d'affaire du restaurant.
*
* @param Le nom du restaurant par référence.
*/
 void  Restaurant::setChiffreAffaire( double chiffre)
{ chiffreAffaire_ = chiffre;
}

 /**
 * Cette méthode accède au nom du restaurant.
 *
 * @return Le pointeur vers le nom du restaurant.
 */
string Restaurant::getNom() const
{
	return nom_; 
}

/**
* Cette méthode accède au moment de la journée.
*
* @return Le moment de la journée.
*/
TypeMenu Restaurant::getMoment() const
{
	return momentJournee_; 
}

/**
* Cette méthode accède au frais de livraison pour une table.
*
* @param L'index de la table de livraison.
*
* @return Le frais de livraison pour la table de livraison.
*/
double Restaurant::getFraisLivraison(int index) const
{
	return fraisLivraison_[index];
}

/**
* Cette méthode permet de libérer la table et d'ajouter le chiffre
* d'affaire de celle-ci au total du chiffre d'affaire du restaurant.
*
* @param Le numéro de la table(id).
*/
void Restaurant::libererTable(int id)
{
	if (Table* table = getTable(id)) {
		chiffreAffaire_ += table->getChiffreAffaire(); 
		chiffreAffaire_ += calculerReduction(table->getClientPrincipal(), table->getChiffreAffaire(), id == tables_[INDEX_TABLE_LIVRAISON]->getId());
		table->libererTable(); 
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
ostream& operator<<(ostream& os, const Restaurant& restaurent)
{
	os << "Le restaurant " << restaurent.getNom();
	if (restaurent.chiffreAffaire_ != 0)
		os << " a fait un chiffre d'affaire de : " << restaurent.chiffreAffaire_ << "$" << endl;
	else
		os << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;

	os << "-Voici les tables : " << endl;

	for (Table* table : restaurent.tables_)
		os  << *table << endl;
	os << endl;

	os << "-Voici son menu : " << endl;
	for (TypeMenu typeMenu : { TypeMenu::Matin, TypeMenu::Midi, TypeMenu::Soir }) {
		Menu* menu = restaurent.getMenu(typeMenu);
		os << getNomTypeMenu(typeMenu) << " : " << endl
			<< *menu << endl
			<< "Le plat le moins cher est : ";
		menu->trouverPlatMoinsCher()->afficherPlat(os);
		os << endl;
	}
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
void Restaurant::commanderPlat(string_view nom, int idTable)
{
	if (Table* table = getTable(idTable); table && table->estOccupee())
		if (Plat* plat = menuActuel()->trouverPlat(nom)) {
			table->commander(plat);
			return;
		}
	cout << "Erreur : table vide ou plat introuvable." << endl << endl;
}

/**
* Cette méthode permet de comparer les chiffres d'affaire de deux restaurants.
*
* @param Le restaurant 1 par référence.
* @param Le restaurant 2 par référence.
*
* @return Si le chiffre d'affaire du restaurant 1 est plus grand que celui du 2.
*/
bool Restaurant::operator<(const Restaurant& autre) const 
{
	return chiffreAffaire_ < autre.chiffreAffaire_;
}

/**
* Cette méthode permet de lire les informations d'une table dans un fichier.
*
* @param Le fichier contenant une table du restaurant par référence.
*/
void Restaurant::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		*this += new Table(id, nbPlaces);
	}
}

/**
* Cette méthode permet d'ajouter une table au restaurant.
*
* @param Le fichier contenant une table du restaurant par référence.
*
* @return Le restaurant avec la table ajoutée.
*/
Restaurant& Restaurant::operator+=(owner<Table*> table)
{
	tables_.push_back(table); 
	return *this;
}

/**
* Cette méthode permet de placer les clients à la table disponible ayant
* le moins de places tout en ayant assez de places pour le nombre de clients.
*
* @param Le nombre de clients à placer.
*/
bool Restaurant::placerClients(Client* client)
{
	const int tailleGroupe = client->getTailleGroupe();
	Table* meilleureTable = nullptr;
	for (Table* table : tables_) {
		if (!table->estOccupee() && table->getId() != ID_TABLE_LIVRAISON) {
			int placesACetteTable = table->getNbPlaces();
			if (placesACetteTable >= tailleGroupe && (!meilleureTable || placesACetteTable < meilleureTable->getNbPlaces()))
				meilleureTable = table;
		}
	}
	if (meilleureTable) {
		meilleureTable->setClientPrincipal(client);
		meilleureTable->placerClients(tailleGroupe);
        client->setTable(meilleureTable);
        return true;
	}
	else
        return false;
}

/**
* Cette méthode permet de livrer le repas au client s'il a accès à ce service.
*
* @param Le nom du client.
* @param La commande du client.
*/
bool Restaurant::livrerClient(Client* client, const vector<string>& commande)
{
	if (dynamic_cast<ClientPrestige*>(client)) {
		cout << "livraison en cours ..." << endl;
		tables_[INDEX_TABLE_LIVRAISON]->setClientPrincipal(client);
		tables_[INDEX_TABLE_LIVRAISON]->placerClients(1);
		for (unsigned int i = 0; i < commande.size(); i++)
			commanderPlat(commande[i], tables_[INDEX_TABLE_LIVRAISON]->getId());
		cout << "Statut de la table de livraison:" << "(table numero 5):" << endl;
		cout << (*tables_[INDEX_TABLE_LIVRAISON]);
		libererTable(tables_[INDEX_TABLE_LIVRAISON]->getId());
        return true;
	}
	else {
        return false;
	}
}

/**
* Cette méthode permet de calculer la réduction du client s'il a accès à ce service.
*
* @param Le nom du client.
* @param Le montant de la commande du client.
* @param Si le client a commandé pour une livraison.
*/
double Restaurant::calculerReduction(Client* client, double montant, bool estLivraison)
{
    return client->getReduction(*this, montant, estLivraison);
}

/**
* Cette méthode accède au frais de livraison pour une table.
*
* @param La zone de livraison.
*
* @return Le frais de livraison pour la table de livraison.
*/
double Restaurant::getFraisLivraison(ZoneHabitation zone) const
{
	return fraisLivraison_[static_cast<int>(zone)];
}

/**
* Cette méthode accède au menu du restaurant.
*
* @param Le type du menu (matin, midi, soir).
*
* @return Le menu.
*/
Menu* Restaurant::getMenu(TypeMenu typeMenu) const
{
	switch (typeMenu) {
	case TypeMenu::Matin : return menuMatin_;
	case TypeMenu::Midi  : return menuMidi_;
	case TypeMenu::Soir  : return menuSoir_;
	}
	assert(false && "Le type du menu est invalide");
	return nullptr;  // On ne devrait jamais se rendre à cette ligne.
}

/**
* Cette méthode accède au menu actuel du restaurant.
*
* @return Le menu actuel.
*/
Menu* Restaurant::menuActuel() const
{
	return getMenu(momentJournee_);
}

/**
* Cette méthode accède a une table du restaurant.
*
* @param Le numero de la table (id).
*
* @return La table.
*/
Table* Restaurant::getTable(int id) const
{
	for (Table* table : tables_)
		if (table->getId() == id)
			return table;
	return nullptr;
}

/**
* Cette méthode permet de lire les frais de transport en fonction des adresses.
*
* @param Le fichier contenant les frais de transport.
*/
void Restaurant::lireAdresses(const string& nomFichier)
{
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection("-ADDRESSES");
	while (!fichier.estFinSection()) {
		int zone; double frais;
		fichier >> zone >> frais;
		fraisLivraison_[zone] = frais;
	}
}

/**
* Cette méthode accède au chiffre d'affaire du restaurant.
*
* @return Le chiffre d'affaire.
*/
double Restaurant::getChiffreAffaire() {
	return chiffreAffaire_;
}

/**
* Cette méthode accède au nom du type de menu du restaurant.
*
* @param Le type du menu (matin, midi, soir).
*
* @return Le nom du type de menu.
*/
string getNomTypeMenu(TypeMenu typeMenu)
{
	return string{nomsDesTypesDeMenu[static_cast<int>(typeMenu)]};
}
