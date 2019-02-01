#include "Menu.h"
#include "Plat.h"

Menu::Menu()
{
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = Matin;
	listePlats_ = new Plat*[MAXPLAT];
	}

Menu::Menu(string fichier, TypeMenu type)
{
	nbPlats_ = 0;
	capacite_ = MAXPLAT;
	type_ = Matin;
	listePlats_ = new Plat*[MAXPLAT];
	lireMenu(fichier, type);
}

//desalloue la memoire de la liste de plats
Menu::~Menu() {
	for (int i = 0; i < MAXPLAT; i++) {
		delete listePlats_[i];
		listePlats_[i] = nullptr;
	}

	delete[] listePlats_;
	listePlats_ = nullptr;
}
int Menu::getNbPlats() const
{
	return nbPlats_;
}


void Menu::afficher() const
{
	for (unsigned i = 0; i < nbPlats_; i++) {
		listePlats_[i]->afficher();
	}
}

Plat* Menu::trouverPlat(const string& nom) const
{
	for (unsigned i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}

	return nullptr;
}

void Menu::ajouterPlat(Plat & plat)
{
	if (nbPlats_ != capacite_) {

		listePlats_[nbPlats_++] = new Plat(plat.getNom(), plat.getPrix(), plat.getCout());
	}
	else cout << "Erreur, le menu est plein. \n";
}

void Menu::ajouterPlat(const string& nom, double montant, double cout)
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
	//permet de determiner le debut et la fin de la lecture
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
	if (fichierLu.fail())
		return false;
	string ligneLue;

	//positionnement de la tete de lecture
	while (ligneLue != typeMenu){
		getline(fichierLu, ligneLue);
		
	}
	//lecture des plats
	for (int i = 0; i < nPlats; i++) {
		string nomTampon; double prixTampon; double coutTampon;
		fichierLu >> nomTampon >> prixTampon >> coutTampon;
		ajouterPlat(nomTampon, prixTampon, coutTampon);
	}
	fichierLu.close();
	
	return true;
}