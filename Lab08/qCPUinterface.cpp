#include "qCPUinterface.h"

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method, const char* m_qName, int m_NqBit, int m_nExp){
	
	if ( !strcmp(m_Method,"Define") )     PARAMETER = 1;

	// Uwaga: wykorzystaj: switch, new, cout, endl

	switch (PARAMETER){
		case 1:
			if(MACHINE){
				AddCPU(m_qName, m_NqBit, m_nExp);
			}
			else{
				++NCPU;
				MACHINE = new TqCPU [NCPU];
				qCPU_alloc(m_qName, m_NqBit, m_nExp, &MACHINE[0]);
			}
			break;

		default:
			std::cout << std::endl << ">>> qInterface::Unknown method, use one of the following:";
			std::cout << "\n> 'Define' add new CPU to the Machine" << std::endl;
			break;
	}
}

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method){

	PARAMETER = 0;
	if ( !strcmp(m_Method,"Release") ) PARAMETER = 1;
	if ( !strcmp(m_Method,"Compute") ) PARAMETER = 2;
	if ( !strcmp(m_Method,"Print") )   PARAMETER = 3;

	switch (PARAMETER){
		case 1:
			for(int i=0; i<NCPU; ++i){
				qCPU_delete(&MACHINE[i]);
			}
			delete [] MACHINE;
			break;
		case 2:
			// std::cout << std::endl << ">>> qInterface::Machine state evaluation "<< std::endl;
			for(int i=0; i<NCPU; ++i)
				Evaluate_qCPU_State(&MACHINE[i]);
			break;
		case 3:
			// std::cout << std::endl << ">>> qInterface:: Printing the Machine state "<< std::endl;
			for(int i=0; i<NCPU; ++i)
				Print_qCPU_State(MACHINE[i]);
			break;

		default:
			std::cout << std::endl << "qInterface::Unknown method, use one of the following:";
			std::cout << "\n>'Compute' evaluate the Machine state";
			std::cout << "\n>'Print' printing the Machine state";
			std::cout << "\n>'Release' destroy the Machine" << std::endl << std::endl;
			break;
		}
			

}

///////////////////////////////////////////////////////////////////////////
void AddCPU(const char* m_qName, int m_NqBit, int m_nExp){

	
	TqCPU* qCPUtemp = MACHINE;
	MACHINE = new TqCPU [++NCPU];

	for(int i=0; i<NCPU-1; ++i){
		MACHINE[i] = qCPUtemp[i];
	}

	qCPU_alloc(m_qName, m_NqBit, m_nExp, &MACHINE[NCPU-1]);
	delete [] qCPUtemp;
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void GenerateNRandExp(TqCPU **m_Cpu){
	srand (time(NULL));
	for (int i=0; i<NCPU; i++)
	{
		m_Cpu[i]->cpuWord[0].NExp = rand() %1000 +1;
	}


}


void GetPointers( TqCPU** tab)
{
	for (int i=0; i<NCPU; i++)
	{
		tab[i]=&MACHINE[i];
	}
}

int PrintNames (TqCPU *m_MACHINE[])
{
	using namespace std;
	for (int i=0; i<NCPU; i++)
	{
		cout<<i<<" "<<m_MACHINE[i]->Name<<endl;
	}

	return 1;
}

void SwapCPU(TqCPU* &CPU1, TqCPU* &CPU2)
{

	TqCPU * temp = CPU1;
	CPU1=CPU2;
	CPU2=temp;
}

void PrintCPUName (TqCPU* CPU)
{
	using namespace std;
	cout<<"CPU Name :: "<<CPU->Name<<endl;
}