#ifndef QCPU_H
#define QCPU_H

///////////////////////////////////////////////////////////////////////////
// Definicja typu strukturalnego TqBIT definiujacego pojedynczy qBit:
// liczba stanow: up lub down (typ int)
// prawdopodobienstwo stanu up oraz down (double)
// liczba experymentow wykorzystana do ewaluacji stanu

typedef struct {
	int up;
	int down;
	double upProb;
	double downProb;
	int numberOfExperiments;
}TqBIT;

///////////////////////////////////////////////////////////////////////////
// Definicja typu struktiralnego TqCPU definiujacego kwantowy procesor:
// nazwa
// liczba N qbitow
// slowo CPU zlozone z N qBitow (odniesienie do struktury TqBIT)

typedef struct {
	char *name;
	int NqBits;
	TqBIT* cpuWord;

}TqCPU;



///////////////////////////////////////////////////////////////////////////
// Function declarations:

///////////////////////////////////////////////////////////////////////////
///This function allocates memory for out Quantum CPU
///It uses malloc to allocate memory for CPU's name (char *string)
///It also uses malloc to allocate memory for cpuWord - array of Qbits
///Function qCPU_delete should be used afterwards to free this memory
///First argument represents name that should be given to out Quantum CPU
///Second argument represents number of qBits out CPU will containt
///Third argument is pointer to CPU itself
///Because of that, object representing CPU should be created outside of this function
void qCPU_alloc(const char* newName, int m_NqBit, TqCPU* m_qCPU);

///////////////////////////////////////////////////////////////////////////
///This function uses free() to deallocate memory used for out CPU
///It sould be used after qCPU_alloc to clear the memory and avoid leaks
void qCPU_delete(TqCPU* m_qCPU);

///////////////////////////////////////////////////////////////////////////
///This function initialises out CPU
///It uses C++11 features, so flag -std=c++11 should be used
///First argument is pointer to TqCPU
///Second and third arguments are doubles representing statistical values
void qBitsProb_init(TqCPU* m_qCPU, double m_Mean, double m_Sigma);

///////////////////////////////////////////////////////////////////////////
///This function evaluates qCPU state
///It uses C++11 features, so compiler flag -std=c++11 should be used
///It's first argument is pointer to our Quantum CPU
///Second argument is int representing number of experiments
void Evaluate_qCPU_State(TqCPU * m_qCPU, int m_nExp);

///////////////////////////////////////////////////////////////////////////
///This function prints state of single qBit (TqBIT)
///It uses std::cout and std::endl from <iostream>
///First and only argument is & (reference) to this qBit
void Print_qBit_State(TqBIT& qBit);

///////////////////////////////////////////////////////////////////////////
///This function prints  state of all qBits (TqBIT) in out CPU (TqCPU)
///It uses std::cout and std::endl from <iostream>
///First and only argument is & (reference) to out Quantum CPU
void Print_qCPU_State(TqCPU& m_qCPU);


#endif // QCPU_H
