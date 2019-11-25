#include "Patient.h"

Patient::Patient()
{
	InitResistance();
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
	this->m_virusList.clear();
	//list <Virus*> ::iterator it;
	//for (it = this->m_virusList.begin(); it != this->m_virusList.end(); ++it)
		//delete (*it);
}
void Patient::InitResistance()
{
	int min = 1000, max = 9000;
	this->m_resistance = rand() % (max - min + 1) + min;
}

void Patient::DoStart()
{
	int min = 10, max = 20;
	int VirusSize = rand() % (max - min + 1) + min;
	for (int i = 0; i < VirusSize; i++) {
		int randomVirus = rand() % 2;
		Virus* virus;
		if (randomVirus) virus = new FluVirus();
		else virus = new DengueVirus();
		this->m_virusList.push_back(virus);
	}
	m_state = 1;
}

void Patient::TakeMedicine()
{
	list <Virus*> ::iterator it;

	for (it = this->m_virusList.begin(); it != this->m_virusList.end(); ++it)
	{
		if ((*it)->ReduceResistance(rand() % 60 + 1) == false) {
			this->m_virusList.push_back((*it)->DoClone());
		}
		else (*it)->DoDie();
		if (m_resistance < TotalVirusResistance(this->m_virusList)) DoDie();
	}
}

void Patient::DoDie()
{
//	delete this;
	this->m_virusList.clear();
	this->m_state = 0;
}

int Patient::getState()
{
	return this->m_state;
}
int Patient::TotalVirusResistance(list<Virus*> m_virusList) {
	int sum = 0;
	list <Virus*> ::iterator it;
	for (it = m_virusList.begin(); it != m_virusList.end(); ++it) {
		sum += (*it)->getResistance();
	}
	return sum;
}
