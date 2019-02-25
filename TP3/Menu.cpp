/*
* Titre : Menu.cpp - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur : Fatou S Mounzeo
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
Menu::Menu(const Menu & menu): type_(menu.type_)
{
	///TODO 
	///Modifier
	for (unsigned i = 0; i < menu.listePlats_.size(); ++i)
	{	
		if(menu.listePlats_[i]->getType() == Regulier)
			listePlats_.push_back(new Plat(*menu.listePlats_[i]));
		if (menu.listePlats_[i]->getType() == Bio) {
			PlatBio* unPlatBio;
			unPlatBio = static_cast<PlatBio*>(menu.listePlats_[i]);
			listePlats_.push_back(new PlatBio(unPlatBio->getNom(),
				unPlatBio->getPrix(), unPlatBio->getCout(), unPlatBio->getEcoTaxe()));

		}
		

	}
}

/**
* Cette m�thode acc�de � la liste de plats point�s par des pointeurs.
*
* @return La liste de plats.
*/
vector<Plat*> Menu::getListePlats() const
{
	return listePlats_;
}

/**
* Cette m�thode permet d'afficher le menu.
*
* @param Le param�tre en sortie.
* @param Le menu � afficher par r�f�rence.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, const Menu& menu)
{
	for (unsigned i = 0; i < menu.listePlats_.size(); ++i) {
		
		
		if(menu.listePlats_[i]->getType()==Regulier)
			os << "\t" << *menu.listePlats_[i];
		if (menu.listePlats_[i]->getType() == Bio) {
			PlatBio* platBio;
			platBio= static_cast<PlatBio*>(menu.listePlats_[i]);
			os << "\t" << *platBio;
		}	
	}
	return os;
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
* Cette m�thode permet d'ajouter un plat bio au menu en entrant le plat.
*
* @param Les informations du plat bio par r�f�rence contenues dans la classe PlatBio.
*
* @return Le menu avec le plat bio ajout�.
*
* @see platBio.cpp
*/
Menu& Menu::operator+=(const PlatBio& platBio){
	listePlats_.push_back(new PlatBio(platBio.getNom(), platBio.getPrix(),
		platBio.getCout(), platBio.getEcoTaxe()));
	return *this;
}

/**
* Cette m�thode permet de mettre � jour le menu.
*
* @param Les informations du menu par r�f�rence.
*
* @return Le menu mis � jour.
*/
Menu & Menu::operator=(const Menu & menu)
{
	///TODO
	/// A Modifier
	if (this != &menu)
	{
		this->type_ = menu.type_;
		listePlats_.clear();

		for (unsigned i = 0; i < menu.listePlats_.size(); ++i) {
			if (menu.listePlats_[i]->getType() == Regulier)
				listePlats_.push_back(new Plat(*menu.listePlats_[i]));
			if (menu.listePlats_[i]->getType() == Bio) {
				PlatBio* unPlatBio;
				unPlatBio = static_cast<PlatBio*>(menu.listePlats_[i]);
				listePlats_.push_back(new PlatBio(unPlatBio->getNom(),
					unPlatBio->getPrix(), unPlatBio->getCout(), unPlatBio->getEcoTaxe()));
			}

		}
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
void Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in); 

	if (!file) {
		cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl; 
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
		double cout;

		string typeString;
		int typePlat;

		string ecotaxeString;
		double ecoTaxe;


		// lecture
		while (!file.eof()) {
			std::getline(file, ligne); 
			//trouver le bon type de menu (section)
			if (ligne == type){ 
				//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu 
				std::getline(file, ligne);
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

					//trouver le type 
					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						typeString += ligne[i];

					}

					typePlat = stoi(typeString);

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
						if (ligne[i] == ' ') {
							if (typePlat == Bio)
								curseur = i;
							break;

						}

						coutString += ligne[i]; 
					}

					cout = stod(coutString.c_str()); 

					//lire le taux si plat bio

					if (typePlat == TypePlat::Bio) {

						for (int i = curseur + 1; i < int(ligne.size()); i++) {
							if (ligne[i] == ' ')
								break;
							ecotaxeString += ligne[i];
						}
						ecoTaxe = stod(ecotaxeString);
						*this += PlatBio(nom, prix, cout, ecoTaxe);
					}
					else {
						*this += Plat(nom, prix, cout);
					}

					nom = ""; 
					prixString = ""; 
					coutString = ""; 
					typeString = "";
					ecotaxeString ="";

					std::getline(file, ligne);
				}
			}
		}

		file.close(); 
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
	for (unsigned i = 0; i < listePlats_.size(); ++i) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i]; 
	}
	return nullptr; 
}