/*
* Titre : ClientPrestige.h - Travail Pratique #3
* Date : 11  Février 2019
* Auteur : Fatou S. Mounzeo
*/
#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"
enum AdressCode{Zone1,Zone2,Zone3};
class ClientPrestige : public ClientRegulier
{
public:
	ClientPrestige();
	ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AdressCode adresse);

	//Accesseur 
	AdressCode getAdresseCode();

	//Autres Fonctions??
	friend ostream & operator<<(ostream & os, ClientPrestige client);
	string getAdressCodeString();



private: 
	AdressCode adresse_;

};

#endif;

