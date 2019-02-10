/*
* Titre : Restaurant.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "Menu.h"
const int INTTABLES = 6;
class Restaurant {
public:
	//constructeurs
	Restaurant();
	Restaurant(const string& fichier, const string& nom,  TypeMenu moment);
	Restaurant(const Restaurant& resto);
	//destructeur
	~Restaurant();

	//setters
	void setMoment(TypeMenu moment);
	void setNom(const string& nom);
	//getters
	string getNom() const;
	TypeMenu getMoment() const;

	//Autres methodes
	void lireTable(const string& fichier);
	void ajouterTable(int id, int nbPlaces); // A MODIFIER
	void libererTable(int id);
	void afficher() const ; // A MODIFIER
	void commanderPlat(const string& nom, int idTable); 

	void placerClients(int nbClients);
	Restaurant& operator+=(const Table& table);
	Restaurant& operator=(const Restaurant& resto);
	friend ostream& operator<<(ostream& o, const Restaurant& resto);
	friend bool operator<(const Restaurant& resto1, const Restaurant& resto2);
private:
	string* nom_;

	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	

	//liste des tables
	
	vector <Table*> tables_;
	
};

ostream& operator<<(ostream& o, const Plat& plat);
bool operator<(const Restaurant& resto1, const Restaurant& resto2);
#endif // !RESTAURANT_H
