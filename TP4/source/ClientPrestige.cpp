/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "ClientPrestige.h"
#include "Restaurant.h"

/**
* Ce constructeur par d�faut initialise les attributs du client prestige aux valeurs par d�faut.
*/
ClientPrestige::ClientPrestige()
{
	adresse_ = ZoneHabitation::Zone3;
}

/**
* Ce constructeur par param�tres initialise les attributs du client prestige aux valeurs correspondantes.
*
* @param Son nom.
* @param Son prenom.
* @param La taille de son groupe.
* @param Son nombre de points.
* @param Son adresse.
*/
ClientPrestige::ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse)
: ClientRegulier(nom, prenom, tailleGroupe, nbPoints), adresse_(adresse)
{
}

/**
* Cette m�thode acc�de a l'adresse du client prestige.
*
* @return L'adresse du client.
*/
ZoneHabitation ClientPrestige::getAdresseCode() const
{
	return adresse_;
}

/**
* Cette m�thode permet d'afficher le nom, le pr�nom et le la table du client.
*
* @param Le param�tre en sortie.
*/
void ClientPrestige::afficherClient(ostream & os) const
{
	if (tableOccupee_ != nullptr) {
		os << "La table numero " << tableOccupee_ << " est occupee. Le client principal est: " << endl <<
			prenom_ << nom_ << endl;
	}
}

/**
* Cette m�thode acc�de a l'adresse du client prestige en string.
*
* @return L'adresse en string.
*/
string ClientPrestige::getAdressCodeString() const
{
	string zone;
	switch (adresse_)
	{
	case ZoneHabitation::Zone1:
		zone = "Zone 1";
		break;
	case  ZoneHabitation::Zone2:
		zone = " Zone 2";
		break;
	case  ZoneHabitation::Zone3:
		zone = "Zone 3";
		break;

	default:
		zone = "erreur zone";
		break;
	}
	return zone;
}

/**
* Cette m�thode acc�de a la reduction du client prestige.
*
* @param Le nom du restaurant.
* @param Le montant de la facture.
* @param Si le client se fait livrer.
*
* @return La reduction.
*/
double ClientPrestige :: getReduction(const Restaurant & res, double montant , bool estLivraison) const
{
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION && nbPoints_ > SEUIL_LIVRAISON_GRATUITE) {
		return (-montant * TAUX_REDUC_PRESTIGE);
	}
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION && nbPoints_ < SEUIL_LIVRAISON_GRATUITE) {
		return (-montant * TAUX_REDUC_PRESTIGE + res.getFraisLivraison(adresse_));
	}
	else return res.getFraisLivraison(adresse_);
}
