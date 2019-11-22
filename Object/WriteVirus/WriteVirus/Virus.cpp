#include "Virus.h"

Virus::Virus()
{
	this->m_dna = new char[100]{""};
	this->m_resistance = 10;
}

Virus::Virus(char* m_dna, int m_resistance)
{
	this->m_dna = new char[100]{ "" };
	this->m_dna = m_dna;
	this->m_resistance = m_resistance;
}

Virus::~Virus()
{
	delete[] this->m_dna;
}

Virus::Virus(const Virus& virus)
{
	this->m_dna = virus.m_dna;
	this->m_resistance = virus.m_resistance;
}

void Virus::LoadADNInformation()
{
	string line;
	ifstream myfile("ATGX.bin");
	if (myfile.is_open())
	{
		getline(myfile, line);
		for (int i = 0; i < line.length(); i++) {
			this->m_dna[i] = line[i];
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

bool Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance -= medicine_resistance;
	if (this->m_resistance <= 0) //if virus die
	{
		cout << "Die ";
		return true;
	}
	return false;
}
