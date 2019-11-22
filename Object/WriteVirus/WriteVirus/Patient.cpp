#include "Patient.h"

Patient::Patient()
{
	m_resistance = 20; // random
	m_state = 1; // 1 - ALIVE
	DoStart();
}

Patient::Patient(int m_resistance, list<Virus*> m_virusList, int m_state)
{
	this->m_resistance = m_resistance;
	this->m_virusList = m_virusList;
	this->m_state = m_state;
}

Patient::~Patient()
{
//	delete this->m_virusList;
}

void Patient::DoStart()
{
	srand(time(NULL));
	int VirusSize = rand() % 11 + 10;

	m_state = 1;
}
