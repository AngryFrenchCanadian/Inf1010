/*
* Titre : PlatBioVege.h - Travail Pratique #4
* Date : 25 février 2019
* Auteur : AbdeB
* Modifié par : Étienne Bourgoin #1955553
* Modifié par : Manuel Pellerin #1960929
*/
#ifndef PLAT_BIOVEGE_H
#define PLAT_BIOVEGE_H

#include "PlatBio.h"
#include "Vege.h"
#include "def.h"
class PlatBioVege :
	public PlatBio, public Vege
{
public:
	PlatBioVege(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0,
                double vitamines = 0, double proteines = 0, double mineraux = 0);// TODO
    virtual ~PlatBioVege() = default;
    virtual Plat* clone() const; // TODO
    virtual void afficherPlat(ostream & os) const;// TODO
    double calculerApportNutritif() const; // TODO


};
#endif
