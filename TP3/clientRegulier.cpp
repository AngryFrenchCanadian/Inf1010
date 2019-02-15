#include "ClientRegulier.h"

ClientRegulier::ClientRegulier()
{
	nbPoints_ = 0;
}
ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints)
	:Client(nom,prenom,tailleGroupe),nbPoints_(nbPoints)
{}


//Accesseurs
int ClientRegulier::getNbPoints()
{
	return nbPoints_;
}


//Autres Méthodes
void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}
ostream& operator<<(ostream & os, const ClientRegulier& client)
{
	os << client << " possede " << client.nbPoints_ << "points." << endl;
}

