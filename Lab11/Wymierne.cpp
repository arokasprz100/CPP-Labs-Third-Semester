#include "Wymierne.h"
#include <iostream>

void CWymierne::Print () const
{
	if (m_mianownik==1)
		std::cout<<m_licznik<<std::endl;
	else
		std::cout<<m_licznik<<"/"<<m_mianownik<<std::endl;
}

int CWymierne::DajLicznik() const
{
	return m_licznik;
}



int CWymierne::DajMianownik() const
{
	return m_mianownik;
}

CWymierne::operator float () const
{
	return (float)m_licznik/(float)m_mianownik;
}

CWymierne Pomnoz (const CWymierne& skladnik1, const CWymierne skladnik2)
{
	return CWymierne (skladnik1.DajLicznik()*skladnik2.DajLicznik(), skladnik1.DajMianownik()*skladnik2.DajMianownik());
}
