/*
* Titre : plat.cpp - Travail Pratique #1
* Date : 02 F�vrier 2019
* Auteur : �tienne Bourgoin #1955553
* Auteur : Manuel Pellerin #1960929
* Ce fichier r�alise l'impl�mentation de la classe plat
*/

#include "Plat.h"
using namespace std;
	
/**
* Ce constructeur par d�faut initialise les attributs d'un plat aux valeurs par d�faut.
*/
Plat::Plat() { 
	nom_ = "inconnu";
	prix_ = 0;
	cout_ = 0;
} 

/**
* Ce constructeur par param�tres initialise les attributs d'un plat aux valeurs correspondantes.
*/
Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

/**
* Cette m�thode acc�de au nom du plat.
*
* @return Le nom du plat.
*/
string Plat::getNom()const {
	return nom_;
}

/**
* Cette m�thode acc�de au prix du plat pour le client.
*
* @return Le prix du plat.
*/
double Plat::getPrix()const {
	return prix_;
}

/**
* Cette m�thode acc�de au co�t du plat pour le restaurant.
*
* @return Le co�t du plat.
*/
double Plat::getCout()const {
	return cout_;
}

/**
* Cette m�thode permet de modifier le nom du plat.
*/
void Plat::setNom(string nom) {
	nom_ = nom;
}

/**
* Cette m�thode permet de modifier le prix du plat pour le client.
*/
void Plat::setPrix(double prix) {
	prix_ = prix;
}

/**
* Cette m�thode permet d'afficher le nom du plat, son prix pour le client
* et le co�t pour le restaurant. 
*/
void Plat::afficher()const {
	cout << "	" << nom_ << " - " << prix_ << " $  ("
		<< cout_ << " $ pour le restaurant) \n";
}