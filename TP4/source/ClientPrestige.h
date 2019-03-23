/*
* Titre : ClientPrestige.h - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*/
#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"

#include "def.h"
class ClientPrestige : public ClientRegulier
{
public:
	ClientPrestige();
	ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, 
		           int nbPoints, ZoneHabitation adresse);// TODO
     ~ClientPrestige(){};
	//Accesseur 
	ZoneHabitation getAdresseCode() const;

	//Autres Fonctions
    virtual void afficherClient(ostream & os) const;// TODO
	string getAdressCodeString() const;
    virtual double getReduction(const Restaurant & res, double montant, bool estLivraison) const; //TODO

private:
	ZoneHabitation adresse_;

};

#endif

