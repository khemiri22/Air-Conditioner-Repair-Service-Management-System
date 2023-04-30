#include "GestionDesFichiers.h"
#include "Reparation.h"
#include <stdlib.h>
#include <stdio.h>
void sauvegarderToutDemandes(ListeDem* liste)
{
    FILE *pFichier=NULL;
    DemRepCell* itirator=liste->head;
    pFichier=fopen("Demandes.rep","w");
    if (pFichier==NULL)
    {
        return;
    }
    while(itirator!=NULL)
    {
        fprintf(pFichier,"%s\t",itirator->data.clim.prop.nom);
        fprintf(pFichier,"%s\t",itirator->data.clim.prop.telephone);
        fprintf(pFichier,"%s\t",itirator->data.clim.description);
        fprintf(pFichier,"%d\t",itirator->data.refer);
        fprintf(pFichier,"%s\t",itirator->data.description);
        fprintf(pFichier,"%d\n",itirator->data.ED);
        itirator=itirator->next;
    }
}
void sauvegarderDemandesEnAttenteDiag(FileDiag fileD)
{
    FILE *pFichier=NULL;
    pFichier=fopen("Diag.rep","w");
    if (pFichier==NULL)
    {
        return;
    }
    while(fileD->head!=NULL)
    {
        fprintf(pFichier,"%d\n",fileD->head->data);
        Defiler(fileD);
    }
}
void sauvegarderDemandesEnAttenteRep(FileRep fileR)
{
    FILE *pFichier=NULL;
    pFichier=fopen("Rep.rep","w");
    if (pFichier==NULL)
    {
        return;
    }
    while(fileR->head!=NULL)
    {
        fprintf(pFichier,"%d\n",fileR->head->data);
        Defiler(fileR);
    }
}
void ChargerToutDemandes(ListeDem* liste)
{
    FILE *pFichier=NULL;
    DemRep dr;
    pFichier=fopen("Demandes.rep","r");
    if (pFichier==NULL)
    {
        return;
    }
    while(fscanf(pFichier,"%s\t%s\t%s\t%d\t%s\t%d\n",dr.clim.prop.nom,dr.clim.prop.telephone,dr.clim.description,&dr.refer,dr.description,&dr.ED)!=EOF)
    {
        Ajouter_Liste(liste,dr);
    }
}
void ChargerDemandesEnAttenteDiag(FileDiag fileD)
{
    FILE *pFichier=NULL;
    int ref;
    pFichier=fopen("Diag.rep","r");
    if (pFichier==NULL)
    {
        return;
    }
    while(fscanf(pFichier,"%d\n",&ref)!=EOF)
    {
        Enfiler(fileD,ref);
    }
}
void ChargerDemandesEnAttenteRep(FileRep fileR)
{
    FILE *pFichier=NULL;
    int ref;
    pFichier=fopen("Rep.rep","r");
    if (pFichier==NULL)
    {
        return;
    }
    while(fscanf(pFichier,"%d\n",&ref)!=EOF)
    {
        Enfiler(fileR,ref);
    }
}



