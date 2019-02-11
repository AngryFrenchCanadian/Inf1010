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

class Menu {
public:
	// constructeurs
	Menu();
	Menu(string fichier, TypeMenu type);
	Menu(const Menu& menu);
	//destructeur
	~Menu();

	

	

	//methodes en plus
	Plat* trouverPlat(const string& nom) const; 
	Plat * trouverPlatMoinsCher() const; // Utilise les vecteurs (NE PAS MODIFIER)
	bool lireMenu(const string& fichier);
	friend ostream& operator<<(ostream& o, const Menu& menu);
	Menu& operator+=(const Plat& plat);
	Menu& operator=(const Menu& menu);

private :
	// A MODIFIER
	vector <Plat*> listePlats_;
	TypeMenu type_;

};


#endif // !MENU_H
