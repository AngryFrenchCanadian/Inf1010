#include "Menu.h"
#include "Plat.h"

/**
* Ce constructeur par défaut initialise les attributs du menu aux valeurs par défaut.
*/
Menu::Menu()
{
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = Matin;
	listePlats_ = new Plat*[MAXPLAT];
	}

/**
* Ce constructeur par paramètres initialise les attributs du menu aux valeurs correspondantes.
*
* @param Le fichier contenant le menu.
* @param Le type du menu contenu dans le fichier sélectionné (matin, midi ou soir).
*/
Menu::Menu(string fichier, TypeMenu type)
{
	nbPlats_ = 0;
	capacite_ = MAXPLAT;
	type_ = Matin;
	listePlats_ = new Plat*[MAXPLAT];
	lireMenu(fichier, type);
}

/**
* Ce destructeur réinitialise le menu à la valeur nulle.
*/
Menu::~Menu() {
	for (int i = 0; i < MAXPLAT; i++) {
		delete listePlats_[i];
		listePlats_[i] = nullptr;
	}

	delete[] listePlats_;
	listePlats_ = nullptr;
}

/**
* Cette méthode accède au nombre de plats.
*
* @return Le nombre de plats.
*/
int Menu::getNbPlats() const
{
	return nbPlats_;
}

/**
* Cette méthode permet d'afficher le menu.
*/
void Menu::afficher() const
{
	for (unsigned i = 0; i < nbPlats_; i++) {
		listePlats_[i]->afficher();
	}
}

/**
* Cette méthode permet de trouver un plat faisant partie du menu.
* 
* @return Le nom du plat.
* @return Un pointeur nul si le plat ne fait pas partie du menu.
*/
Plat* Menu::trouverPlat(const string& nom) const
{
	for (unsigned i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}

	return nullptr;
}

/**
* Cette méthode permet d'ajouter un plat au menu s'il n'est pas déjà plein en entrant le plat.
*
* @param Les informations du plat par référence contenues dans la classe Plat.
*
* @see plat.cpp
*/
void Menu::ajouterPlat(Plat & plat)
{
	if (nbPlats_ != capacite_) {

		listePlats_[nbPlats_++] = new Plat(plat.getNom(), plat.getPrix(), plat.getCout());
	}
	else cout << "Erreur, le menu est plein. \n";
}


/**
* Cette méthode permet d'ajouter un plat au menu s'il n'est pas déjà plein en entrant
* son nom, le prix pour le client et le coût pour le restaurant.
*
* @param Le nom du plat.
* @param Le prix du plat pour le client.
* @param Le coût du plat pour le restaurant.
*
* @see plat.cpp
*/
void Menu::ajouterPlat(const string& nom, double montant, double cout)
{
	if (nbPlats_ != capacite_) {
		listePlats_[nbPlats_++] = new Plat(nom, montant, cout);
	}
	else std::cout<< "Erreur, le menu est plein. \n"; // std::cout plutot que double cout
}

/**
* Cette méthode permet de lire le menu contenu dans un fichier.
*
* @param Le nom du fichier contenant le menu.
* @param Le type de menu sélectionné (matin, midi ou soir).
*
* @return Si le fichier du menu a pu être lu.
*
* @see méthode ajouterPlat (utilisée).
*/
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