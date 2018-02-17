#include "ClearStudents.h"

void ClearStudents (int *numberOfStudents, char ***namesList, char ***surnamesList, int **yearsList)
{
    if(*numberOfStudents==0){
        return;
    }

	for(int i=0 ; i<*numberOfStudents; i++)
	{
		delete [] ((*namesList)[i]);
		delete [] ((*surnamesList)[i]);
	}

	delete [] (*namesList);
    delete [] (*surnamesList);
    delete [] (*yearsList);

    (*namesList)=0;
    (*surnamesList)=0;
    (*yearsList)=0;

    *numberOfStudents=0;

}
