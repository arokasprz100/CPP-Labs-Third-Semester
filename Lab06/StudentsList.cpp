#include "StudentsList.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

void AddStudent(int *numberOfStudents, char ***namesList, char***surnamesList, int **yearsList,
	const char * firstname, const char *secondname, const char *surname, int year)
{
	if (*numberOfStudents==0)
	{
		(*namesList)=(char**)malloc(sizeof(char*));
		(*surnamesList)=(char**)malloc(sizeof(char*));
		(*yearsList)=(int*)malloc(sizeof(int));
	}
	else
	{
		(*namesList)=(char**)realloc((*namesList), (*numberOfStudents+1)*sizeof(char*));
		(*surnamesList)=(char**)realloc((*surnamesList), (*numberOfStudents+1)*sizeof(char*));
		(*yearsList)=(int*)realloc((*yearsList), (*numberOfStudents+1)*sizeof(int));
	}

	int halfLength=strlen(firstname);
	int length=strlen(secondname);

	(*namesList)[*numberOfStudents]=(char*)malloc((halfLength+length+2)*sizeof(char));
	for (int i=0; i<halfLength; i++)
	{
		(*namesList)[*numberOfStudents][i]=firstname[i];
	}
	(*namesList)[*numberOfStudents][halfLength]=' ';
	for (int i=0; i<length; i++)
	{
		(*namesList)[*numberOfStudents][halfLength+1+i]=secondname[i];
	}
	(*namesList)[*numberOfStudents][halfLength+length+1]='\0';

	(*yearsList)[*numberOfStudents]=year;

	length=strlen(surname);
	(*surnamesList)[*numberOfStudents]=(char*)malloc((length+1)*sizeof(char));

	for (int i=0; i<length; i++)
	{
		(*surnamesList)[*numberOfStudents][i]=surname[i];
	}
	(*surnamesList)[*numberOfStudents][length]='\0';

	(*numberOfStudents)++;




}

void PrintListContent (int numberOfStudents, char ** wordsList)
{
	using namespace std;
	for (int i=0; i<numberOfStudents; i++)
	{
		cout<<wordsList[i]<<endl;
	}

}

void  PrintListContent (int numberOfStudents, int *yearsList)
{
	using namespace std;
	for (int i=0; i<numberOfStudents; i++)
	{
		cout<<yearsList[i]<<endl;
	}
}

void PrintListContent (int numberOfStudents, char **namesList, char **surnamesList, int *yearsList)
{
	using namespace std;
	for (int i=0; i<numberOfStudents; i++)
	{
		cout<<surnamesList[i]<<", "<<namesList[i]<<" - year "<<yearsList[i]<<endl;
	}

}

void ClearStudents (int *numberOfStudents, char***namesList, char***surnamesList, int**yearsList)
{
	for (int i=0; i<*numberOfStudents; i++)
	{
		free((*namesList)[i]);
		free((*surnamesList)[i]);
	}

	free((*namesList));
	free((*surnamesList));
	free((*yearsList));

	(*namesList)=NULL;
	(*surnamesList)=NULL;
	(yearsList)=NULL;

	(*numberOfStudents)=0;
}

void DeleteStudent(int *numberOfStudents, char*** namesList, char***surnamesList, int **yearsList, int studentToDeleteID)
{
	if (*numberOfStudents==0)
		return;
	if (studentToDeleteID>*numberOfStudents)
		return;

	char **temp=(char**)malloc((*numberOfStudents)*sizeof(char*));
	for (int i=0; i<*numberOfStudents; i++)
	{
		temp[i]=(*namesList)[i];
	}
	free ((*namesList));
	(*namesList)=(char**)malloc((*numberOfStudents-1)*sizeof(char*));
	free((temp)[studentToDeleteID]);
	(*namesList)[studentToDeleteID]=NULL;
	for (int i=0; i<studentToDeleteID; i++)
	{
		(*namesList)[i]=temp[i];
	}
	for (int i=studentToDeleteID+1; i<*numberOfStudents; i++)
	{
		(*namesList)[i-1]=temp[i];
	}
	free(temp);



	temp=(char**)malloc((*numberOfStudents)*sizeof(char*));
	for (int i=0; i<*numberOfStudents; i++)
	{
		temp[i]=(*surnamesList)[i];
	}
	free ((*surnamesList));

	(*surnamesList)=(char**)malloc((*numberOfStudents-1)*sizeof(char*));
	free((temp)[studentToDeleteID]);
	for (int i=0; i<studentToDeleteID; i++)
	{
		(*surnamesList)[i]=temp[i];
	}
	for (int i=studentToDeleteID+1; i<*numberOfStudents; i++)
	{
		(*surnamesList)[i-1]=temp[i];
	}
	free(temp);
	temp=NULL;





	int *tmp=(int*)malloc((*numberOfStudents)*sizeof(int));
	for (int i=0; i<*numberOfStudents; i++)
	{
		tmp[i]=(*yearsList)[i];
	}
	free((*yearsList));
	(*yearsList)=(int*)malloc(sizeof(int)*(*numberOfStudents-1));
	for (int i=0; i<studentToDeleteID; i++)
	{
		(*yearsList)[i]=tmp[i];
	}
	for (int i=studentToDeleteID+1; i<*numberOfStudents; i++)
	{
		(*yearsList)[i-1]=tmp[i];
	}
	free(tmp);
	tmp=NULL;

	(*numberOfStudents)--;


}

void RenameStudent(char ***namesList, const char *firstname, const char * secondname, int studentToRenameID)
{
	free((*namesList)[studentToRenameID]);
	int halfLength=strlen(firstname);
	int length=strlen(secondname);

	(*namesList)[studentToRenameID]=(char*)malloc((halfLength+length+2)*sizeof(char));
	for (int i=0; i<halfLength; i++)
	{
		(*namesList)[studentToRenameID][i]=firstname[i];
	}
	(*namesList)[studentToRenameID][halfLength]=' ';
	for (int i=0; i<length; i++)
	{
		(*namesList)[studentToRenameID][halfLength+1+i]=secondname[i];
	}
	(*namesList)[studentToRenameID][halfLength+length+1]='\0';



}