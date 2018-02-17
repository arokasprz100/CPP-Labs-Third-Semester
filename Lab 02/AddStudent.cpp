#include <iostream>
#include <cstring>

#include "AddStudent.h"

void AddStudent(int *numberOfStudents, char ***namesList, char*** surnamesList, int **yearsList, char const *firstName, char const*  secondName,  char const *surname, int year)
{

	if (*namesList==0){
		(*namesList)=new char* [*numberOfStudents+1];
		(*surnamesList)=new char* [*numberOfStudents+1];
		(*yearsList)=new int [*numberOfStudents+1];
	}
	else{
        char **temp=new char *[*numberOfStudents];
        for (int i=0; i<*numberOfStudents; i++)
			temp[i]= (*namesList)[i];

        delete [] (*namesList);
        (*namesList)=new char* [*numberOfStudents+1];
        for (int i=0; i<*numberOfStudents; i++)
            (*namesList)[i]=temp[i];

        delete [] temp;
        temp=0;



        temp=new char* [*numberOfStudents];
        for (int i=0; i<*numberOfStudents; i++)
            temp[i]= (*surnamesList)[i];
        delete [] (*surnamesList);
        (*surnamesList)=new char* [*numberOfStudents+1];
        for (int i=0; i<*numberOfStudents; i++)
            (*surnamesList)[i]=temp[i];
        delete [] temp;
        temp=0;



        int *tmp=new int [*numberOfStudents];
        for (int i=0; i<*numberOfStudents; i++)
            tmp[i]=(*yearsList)[i];
        delete [] (*yearsList);
        (*yearsList)=new int [*numberOfStudents+1];
        for (int i=0; i<*numberOfStudents; i++)
            (*yearsList)[i]=tmp[i];
        delete [] tmp;
        tmp=0;

	}

    int stringLength=0;
    int halfLength=strlen(firstName);
    stringLength=strlen(firstName) + strlen(secondName)+1;
    (*namesList)[*numberOfStudents]=new char [stringLength+1];
    for (int i=0; i<halfLength; ++i)
        (*namesList)[*numberOfStudents][i]=firstName[i];

    (*namesList)[*numberOfStudents][halfLength]=' ';
    for (unsigned int i=0; i<strlen(secondName); ++i)
        (*namesList)[*numberOfStudents][halfLength+i+1]=secondName[i];

    (*namesList)[*numberOfStudents][stringLength]='\0';

    stringLength=strlen(surname);
    (*surnamesList)[*numberOfStudents]=new char [stringLength+1];
    strcpy ((*surnamesList)[*numberOfStudents], surname);

    (*yearsList)[*numberOfStudents]=year;

	*numberOfStudents=*numberOfStudents+1;

}
