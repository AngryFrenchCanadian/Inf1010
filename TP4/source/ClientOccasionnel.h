/*
* Titre : ClientOccasionnel.h - Travail Pratique #4
* Date : 25 f�vrier 2019
* Auteur : AbdeB
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin #1960929
*/
#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel: public Client
{
public:
	ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);//TODO
    ~ClientOccasionnel();
    virtual int getNbPoints() const;// TODO
    virtual void afficherClient(ostream & os) const;// TODO
    virtual double getReduction(const Restaurant & res, double montant, bool estLivraison) const; // TODO
};

#endif
