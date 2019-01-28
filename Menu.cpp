#include "Menu.h"

Menu::Menu()
{
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = Matin;
	listePlats_ = new Plat*[MAXPLAT];
	for (int i = 0; i < MAXPLAT; i++) {
		listePlats_[i] = nullptr;
	}

}

Menu::Menu(string fichier, TypeMenu type)
{

}

int Menu::getNbPlats() const
{
	return nbPlats_;
}


void Menu::afficher() const
{

}

Plat* Menu::trouverPlat(string& nom) const
{

}

void Menu::ajouterPlat(Plat & plat)
{

}

void Menu::ajouterPlat(string& nom, double montant, double cout)
{

}


bool Menu::lireMenu(const string& fichier,TypeMenu type) 
{
	string typeMenu;
	switch (type) {
		case Matin: typeMenu = "-MATIN";
			nbPlats_ = 5;
			break;
		case Midi: typeMenu = "-MIDI";
			nbPlats_ = 4;
			break;
		case Soir: typeMenu = "-SOIR";
			nbPlats_ = 5;
			break;
	}
	ifstream fichierLu(fichier, ios::beg);
	string ligneLue;
	while (ligneLue != typeMenu){
		getline(fichierLu, ligneLue);
		
	}
	for (int i = 0; i < nbPlats_; i++_) {
		fichierLu>> listePlats_[i]->
	}

}