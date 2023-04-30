#include "File.h"
#include <stdio.h>
#include <stdlib.h>
File* CreerFile()
{
    File* file=(File*)malloc(sizeof(File));
    file->head=NULL;
    file->tail=NULL;
    return file;
}
int EstFileVide(File* file)
{
    return file->head==NULL;

}
int Premier(File* file)
{
    if(!EstFileVide(file))
        return (file->head)->data;
    else
        return -1;

}

void Enfiler(File* file,int data)
{
    Cellule* nouv = (Cellule*)malloc(sizeof(Cellule));
    nouv->data=data;
    nouv->next=NULL;
    if(EstFileVide(file))
    {
        file->head=nouv;
        file->tail=nouv;
        return;
    }
    file->tail->next=nouv;
    file->tail=nouv;


}
void Defiler(File* file)
{
    if(EstFileVide(file))
    {
        printf("Il est impossible de defiler une file vide");
        return;
    }
    Cellule* temp = file->head;
    file->head=file->head->next;
    if(EstFileVide(file))
        file->tail=NULL;
    free(temp);

}

void afficherFile(File* file)
{
    if(EstFileVide(file))
        {
            printf("La file est vide !");
            return;
        }

    Cellule* itirator = file->head;
    while(itirator!=NULL)
    {
        printf(" (%d)   ",itirator->data);
        itirator=itirator->next;
    }

}

