/*
* Titre : Table.cpp - Travail Pratique #1
* Date : 02 Février 2019
* Auteur : Étienne Bourgoin #1955553
* Auteur : Manuel Pellerin #1960929
* ce fichier effectue les instructions demandées dans le tp1 du cours INF1010 (H2019)
*/


/*
	Question1: Il s'agit d'une composition puisque plat est detruit lorsque menu est detruit.
	Question2: Une methode constante ne peut modifier les attributs.
*/
#include "Restaurant.h"
using namespace std; 

int main() {
	
	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 
	string nomResto = "PolyFood";
	TypeMenu MomentJournee = Soir;
	string nomFichier = "polyFood.txt";
	Restaurant polyFood(nomFichier,nomResto, MomentJournee);
	//creer plusieurs clients -- des entiers 

	int client1 = 1; 
	int client2 = 5; 
	int client3 = 15; 
	int client4 = 3; 
	int client5 = 2; 

	//placer les clients 
	polyFood.placerClients(client1);
	polyFood.placerClients(client2);
	polyFood.placerClients(client3);
	polyFood.placerClients(client4);
	polyFood.placerClients(client5);
	// commander des plats
	//Poisson - Table 1 
	//Poulet - Table 2 
	//Pizza - Table 2 
	//Poulet - Table 4
	//Muffin - Table 4 
	//Oeud - Table 4 
	enum Tables {Table1 = 1, Table2 = 2,Table3 = 3, Table4 = 4};
	string plats[6] = { "Poisson","Poulet", "Pizza", "Poulet", "Muffin", "Oeud" };
	
	polyFood.commanderPlat(plats[0], Table1);
	polyFood.commanderPlat(plats[1], Table2);
	polyFood.commanderPlat(plats[2], Table2);
	polyFood.commanderPlat(plats[3], Table4);
	polyFood.commanderPlat(plats[4], Table4);
	polyFood.commanderPlat(plats[5], Table4);
	
	//afficher le restaurant
	polyFood.afficher(); 

	cout << "-------------------------------------------------" << endl; 

	//liberer les tables 
	for (int i = Table1; i <= Table4; i++)
		polyFood.libererTable(i);
	//afficher le restaurant 
	polyFood.afficher(); 
	return 0;

}