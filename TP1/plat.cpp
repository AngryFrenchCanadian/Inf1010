/*
* Titre : plat.cpp - Travail Pratique #1
* Date : 02 Février 2019
* Auteur : Étienne Bourgoin #1955553
* Auteur : Manuel Pellerin #1960929
* Ce fichier réalise l'implémentation de la classe plat
*/

#include "Plat.h"
using namespace std;
	
/**
* Ce constructeur par défaut initialise les attributs d'un plat aux valeurs par défaut.
*/
Plat::Plat() { 
	nom_ = "inconnu";
	prix_ = 0;
	cout_ = 0;
} 

/**
* Ce constructeur par paramètres initialise les attributs d'un plat aux valeurs correspondantes.
*/
Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

/**
* Cette méthode accède au nom du plat.
*
* @return Le nom du plat.
*/
string Plat::getNom()const {
	return nom_;
}

/**
* Cette méthode accède au prix du plat pour le client.
*
* @return Le prix du plat.
*/
double Plat::getPrix()const {
	return prix_;
}

/**
* Cette méthode accède au coût du plat pour le restaurant.
*
* @return Le coût du plat.
*/
double Plat::getCout()const {
	return cout_;
}

/**
* Cette méthode permet de modifier le nom du plat.
*/
void Plat::setNom(string nom) {
	nom_ = nom;
}

/**
* Cette méthode permet de modifier le prix du plat pour le client.
*/
void Plat::setPrix(double prix) {
	prix_ = prix;
}

/**
* Cette méthode permet d'afficher le nom du plat, son prix pour le client
* et le coût pour le restaurant. 
*/
void Plat::afficher()const {
	cout << "	" << nom_ << " - " << prix_ << " $  ("
		<< cout_ << " $ pour le restaurant) \n";
}