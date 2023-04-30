#include "Reparation.h"
#include "ReparationTeam.h"
#include "File.h"
#include <stdio.h>
void MettreAJourCheckList(ListeDem* liste,FileRep fileR,int nombreActes)
{
    if(EstFileVide(fileR))
        {
            printf("Il y a pas des demandes la Reparation !\n");
            return;
        }
    Reparation(liste,fileR,nombreActes);
}
