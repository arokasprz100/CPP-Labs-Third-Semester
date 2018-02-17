#include "qCPUinterface.h"

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method, const char* m_qName, int m_NqBit, int m_nExp){

    using namespace std;
	if ( !strcmp(m_Method,"Add") )     	  PARAMETER = 1;
	if ( !strcmp(m_Method,"Redefine") )   PARAMETER = 2;
switch (PARAMETER)
{
case 1:
    {
        if (MACHINE==0)
        {
            cout<<">>> qInterface:: adding first qCPU"<<endl;
            MACHINE = new TqCPU [1];
            NCPU = 1;
            qCPU_alloc(m_qName, m_NqBit, m_nExp, &MACHINE[0]);
            break;

        }
        else
        {
            cout<<">>> qInterface:: adding new qCPU"<<endl;
            AddCPU(m_qName, m_NqBit, m_nExp);
            break;

        }
        break;

    }
case 2:
    {
        cout<<">>> qInterface:: redefining qCPU"<<endl;
        break;

    }


	// Pseudokod:
	// W zaleznosci od wybranej, metody wykonaj operacje:


	// m_Method = "Add" : dodaj kolejny qCPU do obiektu (TqCPU*)MACHINE:
	//						 jesli pierwsze qCPU : wywolaj : qCPU_alloc()
	//                       kolejne : wywolaj : AddCPU()
	// m_Method = "Redefine" : wydrukuj tylko komunikat

	// Wydrukuj komunikat dla nieznanej m_Method
default:
    {

        cout<<endl;
        cout<<">>> qInterface::Unknown method, use one of the following: \n> 'Add' add new CPU to the Machine \n> 'Redefine' redefine the existing CPU in the Machine"<<endl;
        cout<<endl;
        break;

	}
}
	// Uwaga: wykorzystaj: switch, new, cout, endl

}

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method){
    using namespace std;
	PARAMETER = 0;
	if ( !strcmp(m_Method,"Release") ) PARAMETER = 1;
	if ( !strcmp(m_Method,"Evaluate") ) PARAMETER = 2;
	if ( !strcmp(m_Method,"Print") )   PARAMETER = 3;

	// Pseudokod:
	// W zaleznosci od wybranej metody wykonaj operacje:
	// m_Method = "Release" : zwolnij wczesniej zaalokowana pamiec na kazdy qCPU
	// m_Method = "Evaluate" : wykonaj Evaluate_qCPU_State() dla calej MACHINE
	// m_Method = "Print" : wykonaj Print_qCPU_State() dla calej MACHINE

	// Wydrukuj komunikat dla nieznanej m_Method

	switch (PARAMETER)
	{
    case 1:
        {
            for (int i=0; i<NCPU; i++)
            {
                delete [] MACHINE[i].cpuWord;
            }
            delete [] MACHINE;
            MACHINE = 0;
            NCPU = 0;
            break;
        }
    case 2:
        {
            cout<<">>> qInterface::Machine state evaluation "<<endl;
            for (int i=0; i<NCPU; i++)
            {
                Evaluate_qCPU_State(&MACHINE[i]);
            }
            cout<<endl;
            break;
        }
    case 3:
        {
            cout<<">>> qInterface:: Printing the Machine state "<<endl;
            for (int i=0; i<NCPU; i++)
            {
                Print_qCPU_State(MACHINE[i]);
            }

            break;
        }
    default:
        {
            cout<<endl;
            cout<<"qInterface::Unknown method, use one of the following:"<<endl;
            cout<<">'Evaluate' evaluate the Machine state"<<endl;
            cout<<">'Print' printing the Machine state"<<endl;
            cout<<">'Release' destroy the Machine"<<endl;
            cout<<endl;
            break;
        }


	}

}

///////////////////////////////////////////////////////////////////////////
void AddCPU(const char* m_qName, int m_NqBit, int m_nExp){

	// Pseudokod:
	// Zwieksz dynamicznie tablice MACHINE, dodajac koleny qCPU
	// Wskazowka: dla nowego qCPU wykonaj qCPU_alloc()

	TqCPU *temp = new TqCPU [NCPU];
	for (int i=0; i<NCPU; i++)
    {
        temp[i]=MACHINE[i];
    }
    delete [] MACHINE;
    MACHINE = new TqCPU [NCPU+1];
    for (int i=0; i<NCPU; i++)
    {
        MACHINE[i] = temp[i];
    }
    delete [] temp;

    qCPU_alloc (m_qName, m_NqBit, m_nExp, &MACHINE[NCPU]);
    NCPU++;



}
