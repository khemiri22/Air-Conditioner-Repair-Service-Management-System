#ifndef ACCUEIL_H_INCLUDED
#define ACCUEIL_H_INCLUDED
#include "Reparation.h"
void CreeDemande(ListeDem* liste,FileDiag fileD);
void ConsulterTousLesDemandes(ListeDem* liste);
void ConsulterLesDemandesAttDiagnostic(ListeDem* liste);
void ConsulterLesDemandesAttReparation(ListeDem* liste);
void ConsulterLesDemandesRepare(ListeDem* liste);
void SupprimerLesDemandesRepare(ListeDem* liste);
int MenuAccueil();
void ServiceAccueil(int selection,ListeDem* listeDem,FileDiag fileDiag,FileRep fileRep);



#endif // ACCUEIL_H_INCLUDED
