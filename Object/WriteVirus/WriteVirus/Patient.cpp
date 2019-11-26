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
	list <Virus*> ::iterator it;
	for (it = this->m_virusList.begin(); it != this->m_virusList.end(); ++it)
	{
		delete *it;
	}
	m_virusList.clear();
}
void Patient::InitResistance()
{
	int min = 1000, max = 9000;
	this->m_resistance = rand() % (max - min + 1) + min;
	cout << endl << "Health: " << this->m_resistance << endl;
}

void Patient::DoStart()
{
	int min = 10, max = 20;
	int VirusSize = rand() % (max - min + 1) + min;
	for (int i = 0; i < VirusSize; i++) {
		int randomVirus = rand() % 2; // 1 - Fluvirus , 0 - DengueVirus
		Virus* virus;
		if (randomVirus) virus = new FluVirus();
		else virus = new DengueVirus();
		this->m_virusList.push_back(virus);
		virus = NULL;
		delete virus;
	}
	m_state = ALIVE;
}

void Patient::TakeMedicine()
{
	list <Virus*> ::iterator it;
	cout << endl << "Amount of Virus: " << this->m_virusList.size() << endl;
	for (it = this->m_virusList.begin(); it != this->m_virusList.end();)
	{ 
		cout << "(" << TotalVirusResistance(m_virusList) << ")";
		cout << (*it)->getResistance();
		if ((*it)->ReduceResistance(rand() % 60 + 1) == false) {
			this->m_virusList.push_back((*it)->DoClone(this->m_virusList)); 
			it++;
		}
		else {
			(*it)->DoDie();
			delete *it;
			m_virusList.remove(*it);
			it = this->m_virusList.begin();
		}
	
		if (this->m_resistance < TotalVirusResistance(this->m_virusList)) {
			DoDie();
			break;
		}
		cout << "  " ;
	}
	cout << "(" << TotalVirusResistance(m_virusList) << ") ";
}

void Patient::DoDie()
{
	this->m_state = DIE;
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
