#include <stdio.h>
#include <stdlib.h>
#include "File.h"
#include "Reparation.h"
DemRep Saisir_Dem()
{
    DemRep dr;
    fflush(stdin);
    printf("Donner le nom de proprietaire du climatiseur\n");
    gets(dr.clim.prop.nom);
    printf("Donner le numero de telephone de proprietaire du climatiseur\n");
    gets(dr.clim.prop.telephone);
    printf("Donner une description sur ce climatiseur\n");
    gets(dr.clim.description);
    printf("Saisir une description sur cette demande\n");
    gets(dr.description);
    dr.refer=rand();
    dr.ED=0;
    dr.checkList=NULL;
    return dr;
}
ListeDem* creeListe()
{
    ListeDem* ld=(ListeDem*)malloc(sizeof(ListeDem));
    ld->head=NULL;
    ld->tail=NULL;
    return ld;
}
void Ajouter_Liste(ListeDem* liste,DemRep dr)
{
    DemRepCell* nouv = (DemRepCell*)malloc(sizeof(DemRepCell));
    nouv->data=dr;
    nouv->next=NULL;
    if(liste->head==NULL)
    {
        liste->head=nouv;
        liste->tail=nouv;
        return;
    }
    liste->tail->next=nouv;
    liste->tail=nouv;
}
void Nouvelle_Demande(ListeDem* liste,FileDiag fileD)
{
    DemRep dr=Saisir_Dem();
    Ajouter_Liste(liste,dr);
    Enfiler(fileD,dr.refer);
}
DemRepCell* chercher_Demande(ListeDem* liste,int refer)
{
    DemRepCell* itirator = liste->head;
    if(liste->head==NULL)
        return NULL;
    while(itirator!=NULL && itirator->data.refer!=refer)
    {
        itirator=itirator->next;
    }
    return itirator;
}
int Diagnostic(ListeDem* liste,FileDiag fileD,FileRep fileR)
{
    int ref=Premier(fileD),stop=1,n=0;
    DemRepCell* tempCell=chercher_Demande(liste,ref);
    printf("Diagnostic de climatiseur de %s\n",tempCell->data.clim.prop.nom);
    while(stop==1)
        {
            ReparationAct act;
            printf("Passer l'act que vous voulez appliquer\n");
            scanf("%d",&act.code);
            act.ER=0;
            if(n==0)
                tempCell->data.checkList=(ReparationAct*)malloc(sizeof(ReparationAct));
            else
                tempCell->data.checkList=(ReparationAct*)realloc(tempCell->data.checkList,(n+1)*sizeof(ReparationAct));
            tempCell->data.checkList[n]=act;
            n++;
            printf("Voulez-vous ajouter une autre act , tapez 1 si oui et 0 si non ?\n");
            scanf("%d",&stop);
        }

        tempCell->data.ED=1;
        Defiler(fileD);
        Enfiler(fileR,ref);
        printf("Diagnostic Terminer !\n");
        return n;
}
void Reparation(ListeDem* liste,FileRep fileR,int nombreActes)
{
    int success=0;
    DemRepCell* tempCell = chercher_Demande(liste,Premier(fileR));
    for(int i=0;i<nombreActes;i++)
    {
        while(tempCell->data.checkList[i].ER<=0)
        {
            printf("Act %d est il verifie ? si oui taper 1,si non taper 2\n",tempCell->data.checkList[i].code);
            scanf("%d",&tempCell->data.checkList[i].ER);
        }
        success+=tempCell->data.checkList[i].ER;
    }

    if(success==nombreActes)
        tempCell->data.ED=2;
    else
        tempCell->data.ED=3;
    printf("Reparation Terminer !\n");
    Defiler(fileR);
}
void SuppDem_Reparee(ListeDem* liste)
{
    DemRepCell* l=liste->head;
    DemRepCell* temp;
   if(liste->head!=NULL && liste->head->data.ED==2)
   {
       liste->head=liste->head->next;
   }

    while(l->next!=NULL)
    {
        temp=l->next;
        if(temp->data.ED==2)
        {
            l->next=temp->next;
            free(temp);
        }
        else
            l=l->next;
    }
}

