#include "ClientPrestige.h"

ClientPrestige::ClientPrestige()
{

}
ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse)
	:ClientRegulier(nom,prenom,tailleGroupe,nbPoints),addresse_(addresse)
{}

//Accesseur 
AddressCode ClientPrestige::getAddresseCode()
{
	return addresse_;
}

//Autres Fonctions??
ostream & operator<<(ostream & os, ClientPrestige client)
{
	os << client << "Habite dans la " << client.getAddressCodeString() << endl;
}
string ClientPrestige::getAddressCodeString()
{
	switch (addresse_) {
	case Zone1: return"Zone 1";
		break;
	case Zone2: return"Zone 2";
		break;
	case Zone3: return"Zone3";
		break;
	}
}
