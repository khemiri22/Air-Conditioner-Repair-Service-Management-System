#include "Reparation.h"
#include "Accueil.h"
#include <stdio.h>
#include <stdlib.h>
void CreeDemande(ListeDem* liste,FileDiag fileD)
{
    Nouvelle_Demande(liste,fileD);
}
void ConsulterTousLesDemandes(ListeDem* liste)
{
    printf("Tout les demandes sont :\n");
    DemRepCell* temp = liste->head;
    if(temp==NULL)
    {
        printf("Rien a afficher !\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("------------------------------------------------\n");
        printf("Nom de proprietaire du climatiseur : %s\n",temp->data.clim.prop.nom);
        printf("Numero telephone de proprietaire du climatiseur : %s\n",temp->data.clim.prop.telephone);
        printf("La Description du climatiseur : %s\n",temp->data.clim.description);
        printf("La reference de la demande : %d\n",temp->data.refer);
        printf("La description de la demande : %s\n",temp->data.description);
        switch(temp->data.ED)
        {
        case 1:
            printf("En attentes de reparation\n");
            break;
        case 2:
            printf("La reparation a reussi\n");
            break;
        case 3:
            printf("La reparation a echoue\n");
            break;
        default:
            printf("En attente de diagnostic\n");
        }
        printf("------------------------------------------------\n");
        temp=temp->next;
    }
}
void ConsulterLesDemandesAttDiagnostic(ListeDem* liste)
{
    printf("Les demandes en attante de diagnostic sont :\n");
    DemRepCell* temp = liste->head;
    if(temp==NULL)
    {
        printf("Rien a afficher !\n");
        return;
    }

    while(temp!=NULL)
    {
        if(temp->data.ED==0)
        {
            printf("------------------------------------------------\n");
            printf("Nom de proprietaire du climatiseur : %s\n",temp->data.clim.prop.nom);
            printf("Numero telephone de proprietaire du climatiseur : %s\n",temp->data.clim.prop.telephone);
            printf("La Description du climatiseur : %s\n",temp->data.clim.description);
            printf("La reference de la demande : %d\n",temp->data.refer);
            printf("La description de la demande : %s\n",temp->data.description);
            printf("------------------------------------------------\n");
        }
        temp=temp->next;
    }
}
void ConsulterLesDemandesAttReparation(ListeDem* liste)
{
    printf("Les demandes en attante de reparation sont :\n");
    DemRepCell* temp = liste->head;
    if(temp==NULL)
    {
        printf("Rien a afficher !");
        return;
    }

    while(temp!=NULL)
    {
        if(temp->data.ED==1)
        {
            printf("------------------------------------------------\n");
            printf("Nom de proprietaire du climatiseur : %s\n",temp->data.clim.prop.nom);
            printf("Numero telephone de proprietaire du climatiseur : %s\n",temp->data.clim.prop.telephone);
            printf("La Description du climatiseur : %s\n",temp->data.clim.description);
            printf("La reference de la demande : %d\n",temp->data.refer);
            printf("La description de la demande : %s\n",temp->data.description);
            printf("------------------------------------------------\n");
        }
        temp=temp->next;
    }
}
void ConsulterLesDemandesRepare(ListeDem* liste)
{
    printf("Les demandes repare sont :\n");
    DemRepCell* temp = liste->head;
    if(temp==NULL)
    {
        printf("Rien a afficher !\n");
        return;
    }

    while(temp!=NULL)
    {
        if(temp->data.ED==2)
        {
            printf("------------------------------------------------\n");
            printf("Nom de proprietaire du climatiseur : %s\n",temp->data.clim.prop.nom);
            printf("Numero telephone de proprietaire du climatiseur : %s\n",temp->data.clim.prop.telephone);
            printf("La Description du climatiseur : %s\n",temp->data.clim.description);
            printf("La reference de la demande : %d\n",temp->data.refer);
            printf("La description de la demande : %s\n",temp->data.description);
            printf("------------------------------------------------\n");
        }
        temp=temp->next;
    }
}
void SupprimerLesDemandesRepare(ListeDem* liste)
{
    SuppDem_Reparee(liste);
}


int MenuAccueil()
{
    int select=-1;
    printf("                BIENVENUE DANS LE SERVICE ACCUEIL");
            printf("\n---------------------------------------------------------------\n");
            while(select!=1 && select!=2 && select!=3 && select!=4 && select!=5 && select!=6 )
            {
                fflush(stdin);
                printf("Selectioner une commande de cette liste s il vous plait\n");
                printf("1- Creer une nouvelle demande de reparation\n");
                printf("2- Consulter toutes les demandes\n");
                printf("3- Consulter les demandes : en attentes de diagnostic\n");
                printf("4- Consulter les demandes : en attentes de reparation\n");
                printf("5- Consulter les demandes : reparees\n");
                printf("6- Supprimer les demandes reparees\n");
                scanf("%d",&select);
                printf("\n---------------------------------------------------------------\n");
            }
    return select;
}
void ServiceAccueil(int selection,ListeDem* listeDem,FileDiag fileDiag,FileRep fileRep)
{
    switch(selection)
            {
            case 1:
                Nouvelle_Demande(listeDem,fileDiag);
                break;
            case 2:
                ConsulterTousLesDemandes(listeDem);
                break;
            case 3:
                ConsulterLesDemandesAttDiagnostic(listeDem);
                break;
            case 4:
                ConsulterLesDemandesAttReparation(listeDem);
            case 5:
                ConsulterLesDemandesRepare(listeDem);
            default:
                SupprimerLesDemandesRepare(listeDem);
            }

}
