#include "Menu.h"
#include "Plat.h"

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
	nbPlats_ = 0;
	capacite_ = MAXPLAT;
	type_ = Matin;
	listePlats_ = new Plat*[MAXPLAT];
	lireMenu(fichier, type);
}

int Menu::getNbPlats() const
{
	return nbPlats_;
}


void Menu::afficher() const
{
	for (int i = 0; i < nbPlats_; i++) {
		listePlats_[i]->afficher();
	}
}

Plat* Menu::trouverPlat(string& nom) const
{
	for (int i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom == nom)
			return listePlats_[i];
	}

	return nullptr;
}

void Menu::ajouterPlat(Plat & plat)
{
	if (nbPlats_ != capacite_) {

		listePlats_[nbPlats_++] = new Plat(plat.getNom, plat.getPrix, plat.getCout);
	}
	else cout << "Erreur, le menu est plein. \n";
}

void Menu::ajouterPlat(string& nom, double montant, double cout)
{
	if (nbPlats_ != capacite_) {
		listePlats_[nbPlats_++] = new Plat(nom, montant, cout);
	}
	else std::cout<< "Erreur, le menu est plein. \n"; // std::cout plutot que double cout
}


bool Menu::lireMenu(const string& fichier,TypeMenu type) 
{
	string typeMenu;
	int nPlats;
	switch (type) {
		case Matin: typeMenu = "-MATIN";
			nPlats = 5;
			break;
		case Midi: typeMenu = "-MIDI";
			nPlats = 4;
			break;
		case Soir: typeMenu = "-SOIR";
			nPlats = 5;
			break;
	}
	ifstream fichierLu(fichier, ios::beg);
	string ligneLue;
	while (ligneLue != typeMenu){
		getline(fichierLu, ligneLue);
		
	}
	for (int i = 0; i < nPlats; i++) {
		string nomTampon; double prixTampon; double coutTampon;
		fichierLu >> nomTampon >> prixTampon >> coutTampon;
		ajouterPlat(nomTampon, prixTampon, coutTampon);
	}

}