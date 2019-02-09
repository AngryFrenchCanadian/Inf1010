/*
* Titre : Table.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"

class Table {
public:
	///constructeurs
	Table();
	Table(int id, int nbPlaces);



	///getters
	int getId() const;
	int getNbPlaces() const;
	int getnbClientATable() const;
	bool estPleine() const;
	bool estOccupee() const;

	///setters
	void libererTable(); 
	void placerClient(int nbClients);
	void setId(int id);

	///autres methodes
	void commander(Plat* plat); 
	double getChiffreAffaire() const;

	///affichage
	friend ostream& operator<<(ostream& o, const Table& table);

private :
	//A MODIFIER
	vector <Plat*> commande_;
	int id_;
	int nbPlaces_;
	int nbClientsATable_;
};

ostream& operator<<(ostream& o, const Table& table);
#endif // !TABLE_H
