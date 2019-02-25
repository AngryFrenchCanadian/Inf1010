/*
* Titre : Table.cpp - Travail Pratique #3
* Date : 11 Février 2019
* Auteur :Fatou S. MOUNZEO
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin	#1960929
*/

#include "Table.h"

/**
* Ce constructeur par défaut initialise les attributs de la table aux valeurs par défaut.
*/
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
	clientPrincipal_ = nullptr;
}

/**
* Ce constructeur par paramètres initialise les attributs de la table aux valeurs correspondantes.
*
* @param Le numéro de la table (id).
* @param Le nombre de places de la table.
*/
Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
	clientPrincipal_ = nullptr;
}

/**
* Cette méthode accède au numero de la table (id).
*
* @return Le numero de la table.
*/
int Table::getId() const {
	return id_;
}

/**
* Cette méthode accède au nombre de places de la table.
*
* @return Le nombre de places de la table.
*/
int Table::getNbPlaces() const {
	return nbPlaces_;
}

/**
* Cette méthode accède au booléen qui permet de savoir si la table est occupée par des clients.
*
* @return Si la table est occupée par des clients.
*/
bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

/**
* Cette méthode accède au booléen qui permet de savoir si la table est pleine.
*
* @return Si la table est pleine.
*/
bool Table::estPleine() const {
	return nbPlaces_ == 0;
}

/**
* Cette méthode accède au nombre de clients de la table.
*
* @return Le nombre de clients de la table.
*/
int Table::getNbClientsATable() const
{
	return nbClientsATable_;
}

/**
* Cette méthode permet d'obtenir la commande passée à une table.
*
* @param La commande passée à une table.
*/
vector<Plat*> Table::getCommande() const
{
	return commande_;
}

/**
* Cette méthode permet d'obtenir le client principal d'une table.
*
* @return Le client principal d'une table
*/
Client* Table::getClientPrincipal() const
{
	return clientPrincipal_;
}

/**
* Cette méthode permet de créer/modifier le client principal.
*
* @param Le client principal.
*/void Table::setClientPrincipal(Client* clientPrincipal)
{
	

	switch (clientPrincipal->getStatut()) {
	case Occasionnel:clientPrincipal_ = new Client(clientPrincipal->getNom(),
		clientPrincipal->getPrenom(), clientPrincipal->getTailleGroupe());
		break;
	case Fidele:ClientRegulier* clientReg;
		clientReg = static_cast<ClientRegulier*>(clientPrincipal);
		clientPrincipal_ = new ClientRegulier(clientReg->getNom(), clientReg->getPrenom(),
			clientReg->getTailleGroupe(), clientReg->getNbPoints());
		break;
	case Prestige: ClientPrestige* clientPrest;
		clientPrest = static_cast<ClientPrestige*>(clientPrincipal);
		clientPrincipal_ = new ClientPrestige(clientPrest->getNom(), clientPrest->getPrenom(),
			clientPrest->getTailleGroupe(), clientPrest->getNbPoints(),clientPrest->getAdresseCode());
		
		break;
	}
	
}

/**
* Cette méthode permet de créer/modifier le numéro d'une table (id).
*
* @param Le numéro de la table.
*/
void Table::setId(int id) {
	id_ = id;
}

/**
* Cette méthode libère la table et efface les commandes passées à celle-ci.
*/
void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	commande_.clear();
	delete clientPrincipal_;
	clientPrincipal_ = nullptr;
}

/**
* Cette méthode permet de placer un ou plusieurs client à une table et la rendre occupée.
*
* @param Le nombre de clients placés à la table.
*/
void Table::placerClients(int nbClient) {
	nbPlaces_ -= nbClient;
	nbClientsATable_ = nbClient;
}

/**
* Cette méthode permet d'ajouter un plat à la commande d'une table.
*
* @param Le pointeur vers le plat à ajouter.
*/
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

/**
* Cette méthode permet de calculer le chiffre d'affaire des commandes d'une table.
*
* @return Le chiffre d'affaire des commandes d'une table.
*/
double Table::getChiffreAffaire() const {
	///TODO
	///Modifier pour que le chiffre d'Affaire prenne en compte le type de plat
	///voir Énoncé
	double chiffre = 0;
	for (unsigned i = 0; i < commande_.size(); ++i) {
		switch (commande_[i]->getType()) {
		case Regulier:
			chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
			break;
		case Bio:PlatBio* unPlatBio;
			unPlatBio= static_cast<PlatBio*>(commande_[i]);
			chiffre += ((unPlatBio->getPrix() + unPlatBio->getEcoTaxe())
				- unPlatBio->getCout());
			break;
		case Custom: PlatCustom* unPlatCustom;
			unPlatCustom= static_cast<PlatCustom*>(commande_[i]);
			chiffre += ((unPlatCustom->getPrix() + unPlatCustom->getSupplement())
				- unPlatCustom->getPrix());
			break;
		}
	}
	return chiffre;
}

/**
* Cette méthode permet d'afficher l'état d'une table et d'afficher les plats qui ont été
* commandés pour celle-ci.
*
* @param Le paramètre en sortie.
* @param La table à afficher par référence.
*
* @return La sortie.
*/
ostream& operator<<(ostream& os, Table& table)
{
	os << "La table numero " << table.id_;
	if (table.estOccupee())
	{
		os << " est occupee. Le client principal est: " << endl;
		switch (table.getClientPrincipal()->getStatut()) {
		case Occasionnel: os << *table.getClientPrincipal();
			break;
		case Fidele: 
			ClientRegulier* clientReg;
			clientReg = static_cast<ClientRegulier*>(table.getClientPrincipal());
			os << *clientReg;
			break;
		case Prestige: 
			ClientPrestige* clientPrest;
			clientPrest = static_cast<ClientPrestige*>(table.getClientPrincipal());
			os << *clientPrest;
			break;
		}
		if (!table.commande_.empty())
		{
			os << endl << "Voici la commande passee par les clients : " << endl;
			for (unsigned i = 0; i < table.commande_.size(); ++i)
			{
				switch (table.commande_[i]->getType()) {
				case Regulier: os << "\t" << *table.commande_[i];
					break;
				case Bio: PlatBio* platBio;
					platBio = static_cast<PlatBio*>(table.commande_[i]);
					os << "\t" << *platBio;
					break;
				case Custom: PlatCustom* platCustom;
					platCustom = static_cast<PlatCustom*>(table.commande_[i]);
					os << "\t" << *platCustom;
					break;
				}
			
			}
		}
		else
			os << "Mais ils n'ont rien commande pour l'instant. " << endl;
	}
	else
		os << " est vide. " << endl;

	return os;
}
