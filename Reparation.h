#ifndef REPARATION_H_INCLUDED
#define REPARATION_H_INCLUDED
#include "File.h"
typedef struct proprietaire{
    char nom[30];
    char telephone[13];
}proprietaire;

typedef struct climatiseur{
    proprietaire prop;
    char description[150];

}climatiseur;

typedef struct ReparationAct{
    int code;
    int ER;
}ReparationAct;
typedef struct DemRep{
    int refer;
    climatiseur clim;
    char description[150];
    int ED;
    ReparationAct* checkList;
}DemRep;

typedef struct DemRepCell{
    DemRep data;
    struct DemRepCell* next;
}DemRepCell;

typedef struct ListeDem{
    DemRepCell* head;
    DemRepCell* tail;
}ListeDem;

typedef File* FileDiag;
typedef File* FileRep;
DemRep Saisir_Dem();
ListeDem* creeListe();
void Ajouter_Liste(ListeDem* liste,DemRep dr);
void Nouvelle_Demande(ListeDem* liste,FileDiag fileD);
DemRepCell* chercher_Demande(ListeDem* liste,int refer);
int Diagnostic(ListeDem* liste,FileDiag fileD,FileRep fileR);
void Reparation(ListeDem* liste,FileRep fileR,int nombreActes);
void SuppDem_Reparee(ListeDem* liste);

#endif // REPARATION_H_INCLUDED
