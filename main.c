#include <stdio.h>
#include <stdlib.h>
#include "Reparation.h"
#include "Accueil.h"
#include "GestionDesFichiers.h"
#include "Diagnostic.h"
#include "ReparationTeam.h"
int main()
{
    ListeDem* listeDemandes=creeListe();
    FileDiag fileDiagnositic = CreerFile();
    FileRep fileReparation = CreerFile();
    ChargerToutDemandes(listeDemandes);
    ChargerDemandesEnAttenteDiag(fileDiagnositic);
    ChargerDemandesEnAttenteRep(fileReparation);

    while(1)
    {
        system("COLOR F3");
        int select=-1,nombreActes=-1;
        printf("                BIENVENUE DANS CLIMA-REPARATION");
        printf("\n---------------------------------------------------------------\n");
        while(select!=1 && select!=2 && select!=3 && select!=0)
        {
           fflush(stdin);
           printf("Selecter le numero service que vous voulez utiliser\n\n");
           printf("1-Accueil\t2-Diagnostic\t3-Reparation\t0-Quitter\n");
           scanf("%d",&select);
           printf("\n---------------------------------------------------------------\n");
        }
        if(select==0)
            break;

        switch(select)
        {
        case 1:
            system("COLOR FA");
            select=MenuAccueil();
            ServiceAccueil(select,listeDemandes,fileDiagnositic,fileReparation);
            break;
        case 2:
            system("COLOR F0");
            printf("                BIENVENUE DANS LE SERVICE DIAGNOSTIC");
            printf("\n---------------------------------------------------------------\n");
            nombreActes=SaisirListeDeDiagnostic(listeDemandes,fileDiagnositic,fileReparation);
            if(nombreActes==-1)
                printf("Il y a pas des demandes pour le Diagnostic !\n");
            break;
        case 3:
            system("COLOR FD");
            printf("                BIENVENUE DANS LE SERVICE REPARATION");
            printf("\n---------------------------------------------------------------\n");
            MettreAJourCheckList(listeDemandes,fileReparation,nombreActes);
            break;
        default:
            break;
        }

    }
    sauvegarderToutDemandes(listeDemandes);
    sauvegarderDemandesEnAttenteDiag(fileDiagnositic);
    sauvegarderDemandesEnAttenteRep(fileReparation);
    system("COLOR FC");
    printf("\n                       GOOD BYE :) \n");
}
