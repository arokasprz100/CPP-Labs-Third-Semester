#include "qCPU.h"

#include <cstdlib>
#include <random>
#include <iostream>

///Integer value representing number of experiments
///extern int NEXPERIMENTS;  is in Main.cpp file
int NEXPERIMENTS=0;

///////////////////////////////////////////////////////////////////////////
//Function definitions:

///////////////////////////////////////////////////////////////////////////
void qCPU_alloc(const char* newName, int m_NqBit, TqCPU* m_qCPU){

	//Name of TqCPU
	int length=0;
	while (newName[length]!='\0')
		length++;
	m_qCPU->name=(char*)malloc(length*sizeof(char)+1);
	for (int i=0; i<length; ++i)
	{
		m_qCPU->name[i]=newName[i];
	}
	m_qCPU->name[length]='\0';

	//Number of qBits
	m_qCPU->NqBits=m_NqBit;

	//Allocating memory for CPU Word containing m_NqBit qBits
	m_qCPU->cpuWord=(TqBIT*)malloc(m_NqBit*sizeof(TqBIT));


	//Set qBits states probabilities according to Gaussian distribution
	double mean = m_NqBit/2.;
	double sigma = m_NqBit/10.;
	qBitsProb_init(m_qCPU, mean, sigma);

	std::cout<< ">>> qCPU initialized with " << m_NqBit << " qBits" << std::endl;

}

///////////////////////////////////////////////////////////////////////////
void qBitsProb_init(TqCPU* m_qCPU, double m_Mean, double m_Sigma){


  	std::random_device generator;
  	std::mt19937 mt(generator());
  	std::normal_distribution<double> distribution(m_Mean, m_Sigma);


  	int* p= (int*) malloc(m_qCPU->NqBits*sizeof(int));
  	int pmax=0;
  	for (int i=0; i<m_qCPU->NqBits; ++i) p[i] = 0;

  	NEXPERIMENTS = 1000;
	for (int i=0; i<NEXPERIMENTS; ++i) {
	    double number = distribution(mt);
	    if ((number>=0.0)&&(number<m_qCPU->NqBits)) ++p[int(number)];
	  }

  	for (int i=0; i<m_qCPU->NqBits; ++i) pmax = pmax > p[i] ? pmax : p[i];

	for (int i=0; i<m_qCPU->NqBits; ++i) {
		m_qCPU->cpuWord[i].upProb = (double)p[i]/pmax;
		m_qCPU->cpuWord[i].downProb = 1. - (double)p[i]/pmax;

	}

	free(p);

}

///////////////////////////////////////////////////////////////////////////
void Evaluate_qCPU_State(TqCPU * m_qCPU, int m_nExp){

	// Evaluating qBit state

  	std::random_device generator;
  	std::mt19937 mt(generator());

	std::uniform_real_distribution<> distribution(0.0, 1.0);

	for (int q=0; q<m_qCPU->NqBits; ++q) {
		m_qCPU->cpuWord[q].up = 0;
		m_qCPU->cpuWord[q].down = 0;
		for (int i=0; i<m_nExp; ++i)
		{
			m_qCPU->cpuWord[q].numberOfExperiments=m_nExp; //Number of experiments
		    double number = distribution(mt);
		    if (m_qCPU->cpuWord[q].upProb*number >0.5) // up+=1 if upProb * number > 0.5
		    	m_qCPU->cpuWord[q].up+=1;
		    if (m_qCPU->cpuWord[q].downProb*number >0.5) // down+=1 if downProb * number > 0.5
		    	m_qCPU->cpuWord[q].down+=1;


	  }
	}

}

///////////////////////////////////////////////////////////////////////////
void Print_qBit_State(TqBIT& qBit){

	using namespace std;
	// Print 'up' if qBit.up > qBit.down otherwise print 'down'
	qBit.up > qBit.down ? cout<<"up " : cout<<"down ";

}

///////////////////////////////////////////////////////////////////////////
void Print_qCPU_State(TqCPU& m_qCPU){

	//Prints CPU Word using Print_qBit_State() function
	using namespace std;
	cout<<m_qCPU.name<<" CPU word ("<<m_qCPU.cpuWord[0].numberOfExperiments<<" experiments) :	";
	for (int i=0; i<m_qCPU.NqBits; ++i)
		Print_qBit_State(m_qCPU.cpuWord[i]);
	cout<<endl;
}

///////////////////////////////////////////////////////////////////////////
void qCPU_delete(TqCPU* m_qCPU){

	// free() memory allocated for qCPU
	if (m_qCPU==0) //if there is no qCPU
		return;

	if (m_qCPU->name!=0) //check if name of qCPU is not empty
	{
		free (m_qCPU->name);
		m_qCPU->name=0;
	}

	if (m_qCPU->cpuWord!=0) //check if array of qBITs is not empty
	{
		free (m_qCPU->cpuWord);
		m_qCPU->cpuWord=0;

	}
}

