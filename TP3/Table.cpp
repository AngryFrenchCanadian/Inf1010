/*
* Titre : Table.cpp - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur :Fatou S. MOUNZEO
* Modifi� par : �tienne Bourgoin #1955553
* Modifi� par : Manuel Pellerin	#1960929
*/

#include "Table.h"

/**
* Ce constructeur par d�faut initialise les attributs de la table aux valeurs par d�faut.
*/
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
	clientPrincipal_ = nullptr;
}

/**
* Ce constructeur par param�tres initialise les attributs de la table aux valeurs correspondantes.
*
* @param Le num�ro de la table (id).
* @param Le nombre de places de la table.
*/
Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
	clientPrincipal_ = nullptr;
}

/**
* Cette m�thode acc�de au numero de la table (id).
*
* @return Le numero de la table.
*/
int Table::getId() const {
	return id_;
}

/**
* Cette m�thode acc�de au nombre de places de la table.
*
* @return Le nombre de places de la table.
*/
int Table::getNbPlaces() const {
	return nbPlaces_;
}

/**
* Cette m�thode acc�de au bool�en qui permet de savoir si la table est occup�e par des clients.
*
* @return Si la table est occup�e par des clients.
*/
bool Table::estOccupee() const
{
	return nbClientsATable_!=0;
}

/**
* Cette m�thode acc�de au bool�en qui permet de savoir si la table est pleine.
*
* @return Si la table est pleine.
*/
bool Table::estPleine() const {
	return nbPlaces_ == 0;
}

/**
* Cette m�thode acc�de au nombre de clients de la table.
*
* @return Le nombre de clients de la table.
*/
int Table::getNbClientsATable() const
{
	return nbClientsATable_;
}

/**
* Cette m�thode permet d'obtenir la commande pass�e � une table.
*
* @param La commande pass�e � une table.
*/
vector<Plat*> Table::getCommande() const
{
	return commande_;
}

/**
* Cette m�thode permet d'obtenir le client principal d'une table.
*
* @return Le client principal d'une table
*/
Client* Table::getClientPrincipal() const
{
	return clientPrincipal_;
}

/**
* Cette m�thode permet de cr�er/modifier le client principal.
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
* Cette m�thode permet de cr�er/modifier le num�ro d'une table (id).
*
* @param Le num�ro de la table.
*/
void Table::setId(int id) {
	id_ = id;
}

/**
* Cette m�thode lib�re la table et efface les commandes pass�es � celle-ci.
*/
void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	commande_.clear();
	delete clientPrincipal_;
	clientPrincipal_ = nullptr;
}

/**
* Cette m�thode permet de placer un ou plusieurs client � une table et la rendre occup�e.
*
* @param Le nombre de clients plac�s � la table.
*/
void Table::placerClients(int nbClient) {
	nbPlaces_ -= nbClient;
	nbClientsATable_ = nbClient;
}

/**
* Cette m�thode permet d'ajouter un plat � la commande d'une table.
*
* @param Le pointeur vers le plat � ajouter.
*/
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
}

/**
* Cette m�thode permet de calculer le chiffre d'affaire des commandes d'une table.
*
* @return Le chiffre d'affaire des commandes d'une table.
*/
double Table::getChiffreAffaire() const {
	///TODO
	///Modifier pour que le chiffre d'Affaire prenne en compte le type de plat
	///voir �nonc�
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
* Cette m�thode permet d'afficher l'�tat d'une table et d'afficher les plats qui ont �t�
* command�s pour celle-ci.
*
* @param Le param�tre en sortie.
* @param La table � afficher par r�f�rence.
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
