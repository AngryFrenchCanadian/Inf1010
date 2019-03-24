/*
* Titre : Menu.cpp - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*/

#include "Menu.h"
#include "LectureFichierEnSections.h"
#include <cassert>  //? Contient "assert" qui permet de s'assurer qu'une expression est vraie, et terminer le programme avec un message d'erreur en cas contraire.
using namespace std;

/**
* Ce constructeur par défaut initialise les attributs du menu aux valeurs par défaut.
*/
Menu::Menu() :
	type_{TypeMenu::Matin}
{
}

/**
* Ce constructeur par paramètres initialise les attributs du menu aux valeurs correspondantes.
*
* @param Le fichier contenant le menu.
* @param Le type du menu contenu dans le fichier sélectionné (matin, midi ou soir).
*/
Menu::Menu(string fichier, TypeMenu type) :
	type_{type}
{
	lireMenu(fichier); 
}

/*
* Ce destructeur detruit le menu.
*/
Menu::~Menu()
{
	Menu* menu;
	for (int i = 0; i < listePlats_.size(); ++i) {
		delete listePlats_[i];
	}
	delete menu;
}

/*
* Cette methode retourne un plat alloue dynamiquement qui est une copie d'un plat courant.
*
* @return le plat copie.
*/
Plat* Menu::allouerPlat(Plat* plat) {
    return plat->clone();
}

/**
* Ce constructeur crée une copie du menu existant.
*
* @param Les informations du menu par référence.
*/
Menu::Menu(const Menu & menu) : type_(menu.type_)
{
	Plat* plat;
	for (unsigned i = 0; i < menu.listePlats_.size(); ++i)
	{
		listePlats_.push_back(new owner<Plat> (allouerPlat(plat)));
	}
}
  
}


Menu & Menu::operator=(const Menu & menu)
{
        //TODO
}

/**
* Cette méthode accède à la liste de plats pointés par des pointeurs.
*
* @return La liste de plats.
*/
vector<Plat*> Menu::getListePlats() const
{
	return listePlats_;
}

/**
* Cette méthode permet d'ajouter un plat au menu en entrant le plat.
*
* @param Les informations du plat par référence contenues dans la classe Plat.
*
* @return Le menu avec le plat ajouté.
*
* @see plat.cpp
*/
Menu& Menu::operator+=(owner<Plat*> plat) 
{
	listePlats_.push_back(new owner<Plat>(plat));
	return *this;
}

/**
* Cette méthode permet de lire le menu contenu dans un fichier.
*
* @param Le nom du fichier contenant le menu par référence.
*/
void Menu::lireMenu(const string& nomFichier) {
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type_)]);
	while (!fichier.estFinSection())
		*this += lirePlatDe(fichier);
}

/**
* Cette méthode permet de trouver le plat le moins cher du menu.
*
* @return Le pointeur vers le plat le moins cher.
*/
Plat* Menu::trouverPlatMoinsCher() const
{
	assert(!listePlats_.empty() && "La liste de plats de doit pas etre vide pour trouver le plat le moins cher.");
	Plat* minimum = listePlats_[0];
	for (Plat* plat : listePlats_)
		if (*plat < *minimum)
			minimum = plat;

	return minimum;
}

/**
* Cette méthode permet de trouver un plat dans le menu.
*
* @param Le nom du plat à trouver.
*
* @return Le pointeur vers le plat trouvé ou le pointeur nul (plat non trouvé).
*/
Plat* Menu::trouverPlat(string_view nom) const
{
	for (Plat* plat : listePlats_)
		if (plat->getNom() == nom)
			return plat; 

	return nullptr; 
}

/**
* Cette méthode permet de lire un plat contenu dans un fichier.
*
* @param Le nom du fichier contenant le menu par référence.
*/
Plat* Menu::lirePlatDe(LectureFichierEnSections& fichier)
{
    auto lectureLigne = fichier.lecteurDeLigne();
    
    string nom, typeStr;
    TypePlat type;
    double prix, coutDeRevient;
    lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
    type = TypePlat(stoi(typeStr));
    double ecotaxe, vitamines, proteines, mineraux;
    switch (type) {
        case TypePlat::Bio :
            lectureLigne >> ecotaxe;
            return new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
        case TypePlat::BioVege:
            lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
            return new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
        case TypePlat::Vege:
            lectureLigne >> vitamines >> proteines >> mineraux;
            return new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
        default:
            return new Plat{nom, prix, coutDeRevient};
    }
    
}

/*
*Cette méthode permet d'afficher le menu.
*
* @param Le paramètre en sortie.
* @param Le menu à afficher par référence.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, const Menu& menu)
{   
        //TODO
}
