#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

typedef struct Cellule{
    int data;
    struct Cellule* next;
}Cellule;
typedef struct File{
    Cellule* head;
    Cellule* tail;
}File;
File* CreerFile();
int EstFileVide(File* file);
int Premier(File* file);
void Enfiler(File* file,int data);
void Defiler(File* file);
void afficherFile(File* file);
#endif // FILE_H_INCLUDED
