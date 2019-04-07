/*
* Date : 25 f�vrier 2019
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
* @param Le nom du restaurant.
* @param Le moment de la journée.
*/
Restaurant::Restaurant(const string& nomFichier, string_view nom, TypeMenu moment) :
	nom_{nom},
	momentJournee_{moment},
	chiffreAffaire_{0},
	menuMatin_{new GestionnairePlats{nomFichier, TypeMenu::Matin}},
	menuMidi_ {new GestionnairePlats{nomFichier, TypeMenu::Midi }},
	menuSoir_ {new GestionnairePlats{nomFichier, TypeMenu::Soir }},
	fraisLivraison_{}
{
	tables_->lireTables(nomFichier); 
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
	set<Table*> set = tables_->getConteneur();
	for (auto it = set.begin(); it != set.end(); it++) {
		delete *it;

	}
	
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//double Restaurant::getFraisLivraison(int index) const
//{
//	return fraisLivraison_[index];
//}

/**
* Cette méthode permet de libérer la table et d'ajouter le chiffre
* d'affaire de celle-ci au total du chiffre d'affaire du restaurant.
*
* @param Le numéro de la table(id).
*/
void Restaurant::libererTable(int id)
{
	if (Table* table = tables_->getTable(id)) {
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

	restaurent.tables_->afficherTables(os);

	os << "-Voici son menu : " << endl;
	for (TypeMenu typeMenu : { TypeMenu::Matin, TypeMenu::Midi, TypeMenu::Soir }) {
		GestionnairePlats* menu = restaurent.getMenu(typeMenu);
		os << restaurent.getNomTypeMenu(typeMenu) << " : " << endl;
		restaurent.getMenu(typeMenu)->afficherPlats(os); 
		os << endl << "Le plat le moins cher est : ";
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
	Table* table = tables_->getTable(idTable);
	if (table->estOccupee()) {
		Plat* plat = menuActuel()->trouverPlat(nom);
		if (plat != nullptr) {
			table->commander(plat);
			return;
		}
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
bool Restaurant::operator <(const Restaurant& autre) const 
{
	return chiffreAffaire_ < autre.chiffreAffaire_;
}

/**
* Cette méthode permet de placer les clients à la table disponible ayant
* le moins de places tout en ayant assez de places pour le nombre de clients.
*
* @param Le client à placer.
*
* @return Le booleen qui dit si le client a pu etre place.
*
* @see Classe GestionnaireTables.
*/
bool Restaurant::placerClients(Client* client)
{
	const int tailleGroupe = client->getTailleGroupe();
	//TODO : trouver la table la plus adaptée pour le client. 
	//TODO : Si possible assigner la table au client sinon retourner false.
}

/**
* Cette méthode permet de livrer le repas au client s'il a accès à ce service.
*
* @param Le nom du client.
* @param La commande du client.
*
* @return Le booleen qui dit si le client a pu etre livre.
*
* @see Classe GestionnaireTables.
*/
bool Restaurant::livrerClient(Client* client, const vector<string>& commande)
{
	if (dynamic_cast<ClientPrestige*>(client)) {
		// TODO: Placer le client principal a la table fictive en utilisant la classe GestionnaireTables.
		// tables_[INDEX_TABLE_LIVRAISON]->setClientPrincipal(client); // L'appel du TP4
		// TODO: Placer client à la table fictive en utilisant la classe GestionnaireTables.
		// tables_[INDEX_TABLE_LIVRAISON]->placerClients(1); // L'appel du TP4
		// Placer la commande
		for (unsigned int i = 0; i < commande.size(); i++)
			commanderPlat(commande[i], INDEX_TABLE_LIVRAISON);
		// Liberer la table fictive.
		libererTable(INDEX_TABLE_LIVRAISON);
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
*
* @return La reduction du client.
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
*
* @see GestionnairePlats.cpp.
*/
GestionnairePlats* Restaurant::getMenu(TypeMenu typeMenu) const
{
	switch (typeMenu) {
	case TypeMenu::Matin: return menuMatin_;
	case TypeMenu::Midi: return menuMidi_;
	case TypeMenu::Soir: return menuSoir_;
	}
	assert(false && "Le type du menu est invalide");
	return nullptr;  // On ne devrait jamais se rendre � cette ligne.
}

/**
* Cette méthode accède au menu actuel du restaurant.
*
* @return Le menu actuel.
*/
GestionnairePlats* Restaurant::menuActuel() const
{
	return getMenu(momentJournee_);
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
* Cette méthode accède aux tables du restaurant.
*
* @return Les tables du restaurant.
*/
GestionnaireTables* Restaurant::getTables() const
{
	return tables_;
}

/**
* Cette méthode accède au nom du type de menu du restaurant.
*
* @param Le type du menu (matin, midi, soir).
*
* @return Le nom du type de menu.
*/
string Restaurant::getNomTypeMenu(TypeMenu typeMenu)const {
	return string{nomsDesTypesDeMenu[static_cast<int>(typeMenu)]};
}
