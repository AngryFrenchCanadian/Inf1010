/*
* Titre : main.cpp - Travail Pratique #3
* Date : 11 F�vrier 2019 
* Auteur : Fatou S. Mounzeo
* Modifi� par : �tienne Bourgoin #1955553 et Manuel Pellerin #1960929
*
*Q1: Car c'est ce qui nous permet de d�terminer si le plat lu est d'un type different. Ainsi, sans son existance,
* on ne pourrait connaitre le moment appropri� pour utiliser static_cast ( et donc on ne pourrait pas convertir les objets). 
*
*Q2: Static_cast est essentiel pour convertir les classes derivees des clients aux type approprie.
*
*Q3: Car ClientPrestige herite ainsi des methodes ( et donc des avantages ) de ClientRegulier. Puisque le client Prestige
*benificie des memes avanages que le client regulier, on se trouve a eviter la repetition de code.
*/

#include "Restaurant.h"
#include "ClientPrestige.h"


using namespace std; 

int main() {



	//creation du restaurant 
	Restaurant poly("polyFood.txt", "PolyFood", Soir); 

	///creer plusieurs clients  


	Client * cl1 = new Client("Martin", "b", 1);

	vector<string> commandeMartin;
	commandeMartin.push_back("Muffin");
	commandeMartin.push_back("Poisson");
	Client * cl2 = new Client("Amy", "wh", 15);
	Client * cl3 = new ClientRegulier("Jonh", "sm", 5,25);
	Client * cl4 = new ClientRegulier("Moussa", "T", 3,45);
	Client * cl5 = new ClientPrestige("Andree", "F", 2,150, Zone2);
	Client * cl6 = new ClientPrestige("Marie", "C", 1,125, Zone1);
	vector<string> commandeMarie;
	commandeMarie.push_back("Pizza");
	commandeMarie.push_back("ShitJokesBelow");
	commandeMarie.push_back("PizzAAAAAYOYE");
	commandeMarie.push_back("PizzaAaaH");


	cout << "\t\t\t\t\tLIVRAISONS" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	//Livrer les clients Marie et Martins
	poly.livrerClient(cl6, commandeMarie);
	poly.livrerClient(cl1, commandeMartin);

	cout << "\t\t\t\t\tPLACEMENT DES CLIENT" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	//placer les clients 
	poly.placerClients(cl1);
	poly.placerClients(cl2);
	poly.placerClients(cl3); 
	poly.placerClients(cl4); 
	poly.placerClients(cl5); 

	// commander des plats 

	poly.commanderPlat("Poisson", 1, Custom, 3);
	poly.commanderPlat("Poulet", 2);
	poly.commanderPlat("Pizza", 2, Custom, 4);
	poly.commanderPlat("Poulet", 4); 
	poly.commanderPlat("Muffin", 4); 
	poly.commanderPlat("Oeuf", 4); 


	//Creation d'une copie du poly restaurant 
	Restaurant poly2(poly);
	poly2.setNom("PolyFood2");

	//Affichage du restaurant poly 
	cout << poly;

	cout << "--------------------------------------------------------------------------------------------------" << endl;


	//liberer les tables et calcule du chiffre d'affaire
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);


	cout << poly;

	cout << "====================================================================================================" << endl;

	// Le restaurant Poly2 ne doit pas encore avoir liberer ses tables
	cout << poly2;

	poly2 = poly;


	cout << "--------------------------------------------------------------------------------------------------" << endl;
	// Le restaurant Poly2 doit maintenant avoir toutes ses tables lib�r�es
	cout << poly2;

	delete cl1;
	delete cl2;
	delete cl3;
	delete cl4;
	delete cl5;

	return 0;
}