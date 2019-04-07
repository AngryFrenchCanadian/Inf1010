/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"

/**
* Cette methode permet de lire tous les plats dans un fichier et de les ajouter a un conteneur.
*
* @param Le fichier contenant les plats.
* @param Le type du menu contenu dans le fichier.
*/
void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

/**
* Cette methode permet de lire un plat dans un fichier.
*
* @param Le fichier contenant le plat.
*
* @return Une paire contenant le nom du plat et un pointeur sur celui-ci.
*/
pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}

/**
* Ce constructeur par paramètres initialise les attributs du menu aux valeurs correspondantes.
*
* @param Le fichier contenant le menu.
* @param Le type du menu contenu dans le fichier sélectionné (matin, midi ou soir).
*/
GestionnairePlats::GestionnairePlats(const string& nomFichier, TypeMenu type) {
	type_ = type;
	lirePlats(nomFichier, type_);
}

/**
* Ce constructeur crée une copie du menu existant.
*
* @param Les informations du menu par pointeur.
*/
GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire) { // pas sur
	type_ = gestionnaire->getType();
	pair<string, Plat*> copiePair;
	map<string, Plat*> copieConteneur = gestionnaire->getConteneur();
	auto it = copieConteneur.begin();
	auto end = copieConteneur.end();

	for (it; it != end; ++it) {
		copiePair.first = it->second->getNom();
		copiePair.second = allouerPlat(it->second);
		ajouter(copiePair);
	}
}

/*
* Ce destructeur detruit le menu.
*/
GestionnairePlats::~GestionnairePlats() { // pas sur
	auto it = conteneur_.begin();
	auto end = conteneur_.end();
	for (it; it != end; ++it) {
		delete it->second;
	}
	conteneur_.clear();
}

/*
* Cette methode permet d'acceder au type du menu.
*
* @return Le type du menu.
*/
TypeMenu GestionnairePlats::getType() const {
	return type_;
}

/*
* Cette methode permet de creer un plat a partir d'un autre.
*
* @return Le plat cree.
*/
Plat* GestionnairePlats::allouerPlat(Plat* plat) {
	return plat->clone();
}

/*
* Cette methode permet de trouver le plat le moins cher dans un conteneur.
*
* @return Le plat le moins cher.
*/
Plat* GestionnairePlats::trouverPlatMoinsCher() const {
	auto it = min_element(conteneur_.begin(), conteneur_.end(), FoncteurPlatMoinsCher());
	return it->second;
}

/*
* Cette methode permet de trouver le plat le plus cher dans un conteneur.
*
* @return Le plat le plus cher.
*/
Plat* GestionnairePlats::trouverPlatPlusCher() const { // pas sur
	auto it = max_element(conteneur_.begin(), conteneur_.end(), 
		[](const pair<string, Plat*>& left, const pair<string, Plat*>& right) -> bool 
		{ return left.second->getPrix() > right.second->getPrix(); });
		return it->second;
}

/*
* Cette methode permet de trouver un plat dans un conteneur.
*
* @param Le nom du plat.
*
* @return Le plat du conteneur portant le nom spécifié.
*/
Plat* GestionnairePlats::trouverPlat(const string& nom) const {
	auto it = conteneur_.find(nom); // retourne iterateur pointant a l'element qui contient la cle
	if (it != conteneur_.end())
		return it->second;
	else
		return nullptr;
}

/*
* Cette methode permet de retourner dans un vecteur tous les plats qui sont dans un intervalle de prix spécifique.
*
* @param La borne inferieure de l'intervalle.
* @param La borne superieure de l'intervalle.
*
* @return Le vecteur contenant les plats qui font partie de l'intervalle.
*
* @see FoncteurIntervalle dans Foncteur.h.
*/
vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup) { // pas sur
	vector<pair<string, Plat*>> platsConformes;
	FoncteurIntervalle appartientIntervalle(borneInf, borneSup);
	auto it = conteneur_.begin();

	copy_if(it, conteneur_.end(), back_inserter(platsConformes), appartientIntervalle(*it));
	return platsConformes;
}

/*
*Cette méthode permet d'afficher le menu.
*
* @param Le paramètre en sortie.
*/
void GestionnairePlats::afficherPlats(ostream& os) {
	auto it = getConteneur().begin();
	auto end = getConteneur().end();
	for (it; it!=end; it++) {
		(*it->second).afficherPlat(os);
	}
}
