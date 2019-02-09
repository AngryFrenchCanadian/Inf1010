/*
* Titre : Menu.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef MENU_H
#define MENU_H

#include "Plat.h"
#include <fstream>

enum TypeMenu{Matin, Midi, Soir};
const int MAXPLAT = 5;
class Menu {
public:
	// constructeurs
	Menu();
	Menu(string fichier, TypeMenu type);

	//destructeur
	~Menu();

	//getters
	int getNbPlats() const;

	//affichage
	

	//methodes en plus
	Plat* trouverPlat(const string& nom) const; // A MODIFIER
	Plat * trouverPlatMoinsCher() const; // Utilise les vecteurs (NE PAS MODIFIER)
	void ajouterPlat(const Plat & plat); // A MODIFIER
	bool lireMenu(const string& fichier);
	friend ostream& operator<<(ostream& o, const Menu& menu);


private :
	// A MODIFIER
	vector <Plat*> listePlats_;
	TypeMenu type_;

};

ostream& operator<<(ostream& o, const Menu& menu);
#endif // !MENU_H
