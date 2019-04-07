/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"

/**
* Cette methode permet de lire toutes les tables dans un fichier et de les ajouter a un conteneur.
*
* @param Le fichier contenant les plats.
*/
void GestionnaireTables::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}

/*
* Cette methode permet d'acceder a une table specifique.
*
* @param Le numero de la table (id).
*
* @return La table specifique ou un pointeur nul si la table n'existe pas.
*/
Table* GestionnaireTables::getTable(int id) const {
	
	auto it = conteneur_.begin();
	auto end = conteneur_.end();
	for (it; it != end; ++it) {
		if ((*it)->getId() == id)
			return *it;
	}
	return nullptr;
}

/*
* Cette methode permet de retourner la plus petite table pouvant contenir le groupe.
*
* @param La taille du groupe.
*
* @return La plus petite table pouvant contenir le groupe.
*/
Table* GestionnaireTables::getMeilleureTable(int tailleGroupe) const {
	Table* resultat = nullptr;
	auto it = conteneur_.begin();
	auto end = conteneur_.end();
	for (it; it != end; ++it) {
		if ((*it)->getNbPlaces() >= tailleGroupe && (*it)->estOccupee() == false) {
			if (resultat == nullptr) {
				resultat = *it;
			}
			else if ((*it)->getNbPlaces() < resultat->getNbPlaces()) {
				resultat = *it;
			}
		}
	}
	return resultat;
}

/*
* Cette méthode permet d'afficher les tables.
*
* @param Le paramètre en sortie.
*/
void GestionnaireTables::afficherTables(ostream& os) const {
	auto it = conteneur_.begin();
	auto end = conteneur_.end();
	for (it; it != end; ++it) {
		os << **it;
	}
}

/**
* Cette méthode permet d'ajouter une table au restaurant.
*
* @param La table a ajouter.
*
* @return Le conteneur avec la table ajoutée.
*/
GestionnaireTables& GestionnaireTables::operator+=(Table* table) {
	ajouter(table);
	return *this;
}
