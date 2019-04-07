/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:
	C getConteneur() const; //TODO
	void ajouter(T t);//TODO
	int getNombreElements() const;//TODO

protected:
	C conteneur_;
};

/**
* Cette methode generique permet de faire une copie d'un conteneur.
*
* @return La copie du conteneur.
*/
template<typename T, typename C>
C GestionnaireGenerique<T,C>::getConteneur() const {
	C conteneurCopy;
	return conteneur_;

}

/**
* Cette methode generique permet d'ajouter un element a un conteneur.
*
* @param L'element a ajouter.
*/
template<typename T, typename C>
void GestionnaireGenerique<T, C>::ajouter(T t) {
	conteneur_.insert(t);

}

/**
* Cette methode generique permet d'acceder a la taille d'un conteneur.
*
* @return La taille du conteneur.
*/
template<typename T, typename C>
int GestionnaireGenerique<T, C>::getNombreElements() const {
	return conteneur_.size();
}
