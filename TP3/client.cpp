#include "Client.h"

Client::Client() {
	nom_ = "inconnu";
	prenom_ = "inconnu";
	statut_ = Occasionnel;
	tailleGroupe_ = 0;
}

Client::Client(string nom, string prenom, int tailleGroupe) {
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	statut_ = Occasionnel;
}

StatutClient Client::getStatut() {
	return statut_;
}

string Client::getNom() {
	return nom_;
}

string Client::getPrenom() {
	return prenom_;
}

int Client::getTailleGroupe() {
	return tailleGroupe_;
}

string Client::convertirStatutString() {
	switch (statut_) {
	case Occasionnel:
		return "Occasionnel";
		break;
	case Fidele:
		return "Fidele";
		break;
	case Prestige:
		return "Prestige";
		break;
	}
}

ostream & operator<<(ostream & os, const Client& client) {
	os << "Le client principal est: " << endl << "\t\t" << client.prenom_ << " " << client.nom_ << " statut: " << client.statut_ << endl;
	return os;
}

