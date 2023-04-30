#ifndef GESTIONDESFICHIERS_H_INCLUDED
#define GESTIONDESFICHIERS_H_INCLUDED
#include"Reparation.h"
void sauvegarderToutDemandes(ListeDem* liste);
void sauvegarderDemandesEnAttenteDiag(FileDiag fileD);
void sauvegarderDemandesEnAttenteRep(FileRep fileR);
void ChargerToutDemandes(ListeDem* liste);
void ChargerDemandesEnAttenteDiag(FileDiag fileD);
void ChargerDemandesEnAttenteRep(FileRep fileR);


#endif // GESTIONDESFICHIERS_H_INCLUDED
