/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifi� par : �tienne Bourgoin #1955553 et Manuel Pellerin #1960929
* Date : 08 f�vrier 2019
*/

#include "Menu.h"

/**
* Ce constructeur par d�faut initialise les attributs du menu aux valeurs par d�faut.
*/
Menu::Menu() {

	type_ = Matin;
}

/**
* Ce constructeur par param�tres initialise les attributs du menu aux valeurs correspondantes.
*
* @param Le fichier contenant le menu.
* @param Le type du menu contenu dans le fichier s�lectionn� (matin, midi ou soir).
*/
Menu::Menu(string fichier, TypeMenu type) {
	
	type_ = type;

	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

/**
* Ce constructeur cr�e une copie du menu existant.
*
* @param Les informations du menu par r�f�rence. 
*/
Menu::Menu(const Menu& menu) :type_(menu.type_)
{
	for (unsigned i = 0; i < menu.listePlats_.size(); i++) {
		Plat* platTemp = new Plat(menu.listePlats_[i]->getNom(),
			menu.listePlats_[i]->getPrix(), menu.listePlats_[i]->getCout());
		listePlats_.push_back(platTemp);
	}
}

/**
* Ce destructeur r�initialise le menu � la valeur nulle.
*/
Menu::~Menu() {
	// A MODIFIER
	for (unsigned i = 0; i < listePlats_.size(); i++) {
		delete listePlats_[i];
		listePlats_[i] = nullptr;
	}

	listePlats_.clear();

}

/**
* Cette m�thode permet d'afficher le menu.
*
* @param Le param�tre en sortie.
* @param Le menu � afficher par r�f�rence.
*
* @return La sortie.
*/
ostream& operator<<(ostream& o, const Menu& menu) {
	for (unsigned i = 0; i < menu.listePlats_.size(); i++) {
		cout << "\t" << *menu.listePlats_[i] << '\n';
	}
	return o;
}


/**
* Cette m�thode permet d'ajouter un plat au menu en entrant le plat.
*
* @param Les informations du plat par r�f�rence contenues dans la classe Plat.
*
* @return Le menu avec le plat ajout�.
*
* @see plat.cpp
*/
Menu& Menu::operator+=(const Plat& plat) {
	listePlats_.push_back(new Plat(plat));
	return *this;
}

/**
* Cette m�thode permet de mettre � jour le menu.
*
* @param Les informations du menu par r�f�rence.
*
* @return Le menu mis � jour.
*/
Menu& Menu::operator=(const Menu& menu) {
	if (this != &menu) {
		for (unsigned i = 0; i < listePlats_.size(); i++) {
			delete listePlats_[i];
			listePlats_[i] = nullptr;
		}
		listePlats_.clear();

		type_ = menu.type_;
		listePlats_ = menu.listePlats_;
	}
	return *this;
}

/**
* Cette m�thode permet de lire le menu contenu dans un fichier.
*
* @param Le nom du fichier contenant le menu par r�f�rence.
*
* @return Si le fichier du menu a pu �tre lu.
*
* @see m�thode ajouterPlat (utilis�e).
*/
bool Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (!file) {
		cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
		return false;
	}
	else {
		string type;
		switch (type_) {
		case Matin :
			type = "-MATIN";
			break;
		case Midi :
			type = "-MIDI";
			break;
		case Soir :
			type = "-SOIR";
			break;
		}
		string ligne;

		string nom;

		string prixString;
		double prix;

		string coutString;
		int cout;


		// lecture
		while(!file.eof()) {
			getline(file, ligne);
			//trouver le bon type de menu (section)
			if (ligne == type){
				//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
				getline(file, ligne);
				int curseur;
				while (ligne[0] != '-' && !file.eof()) {
					//trouver le nom
					for (int i = 0; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						nom += ligne[i];
					}
					//trouver le prix

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						prixString += ligne[i];

					}
					//passer le prixString en double --- indice dans l'enonce
					prix = stof(prixString.c_str());

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ')
							break;
						coutString += ligne[i];
					}

					cout =int( stof(coutString.c_str()));

					*this += Plat(nom, prix, cout);   
					nom = "";
					prixString = "";
					coutString = "";

					getline(file, ligne);
				}
			}
		}

		file.close();
		return true;
	}
}

/**
* Cette m�thode permet de trouver le plat le moins cher du menu.
*
* @return Le pointeur vers le plat le moins cher.
*/
Plat * Menu::trouverPlatMoinsCher() const
{
	Plat minimum(*listePlats_[0]);
	int found = -1;

	for (unsigned i = 0; i < listePlats_.size(); ++i)
	{
		if (*listePlats_[i] < minimum)
		{
			minimum = *listePlats_[i];
			found = i;
		}
	}

	return listePlats_[found];

}

/**
* Cette m�thode permet de trouver un plat dans le menu.
*
* @param Le nom du plat � trouver.
*
* @return Le pointeur vers le plat trouv� ou le pointeur nul (plat non trouv�).
*/
Plat* Menu::trouverPlat(const string& nom) const {
	for (unsigned i = 0; i < listePlats_.size(); i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}

