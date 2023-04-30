#include"Reparation.h"
#include"Diagnostic.h"
#include "File.h"
int SaisirListeDeDiagnostic(ListeDem* liste,FileDiag fileD,FileRep fileR)
{
    if(EstFileVide(fileD))
        return -1;
    return Diagnostic(liste,fileD,fileR);
}
