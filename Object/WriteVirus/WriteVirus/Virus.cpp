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

void FluVirus::DoBorn()
{
	LoadADNInformation();
	srand(time(NULL));
	this->m_color = rand() % 2 ? 0x0000ff : 0xff0000;
}

FluVirus* FluVirus::DoClone()
{
	FluVirus *flu = new FluVirus();
	flu->m_color = this->m_color;
	flu->m_dna = this->m_dna;
	flu->m_resistance = this->m_resistance;
	return flu;
}

void FluVirus::DoDie()
{
	delete[] m_dna;
	m_color = NULL;
	m_resistance = NULL;
}

void FluVirus::InitResistance()
{
	srand(time(NULL));
	this->m_resistance = rand() % 11 + 10;
}

void FluVirus::SetColor(int m_color)
{
	this->m_color = m_color;
}

int FluVirus::GetColor()
{
	return this->m_color;
}

DengueVirus::DengueVirus()
{
	this->m_dna = '\0';
	this->m_protein[0] = '\0';
	this->m_resistance = 10;
}

DengueVirus::DengueVirus(char* m_dna, int m_resistance, char m_protein[])
{
	this->m_dna = m_dna;
	SetProtein(m_protein);
	this->m_resistance = m_resistance;
}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0) SetProtein("NS3");
	if (random == 1) SetProtein("NS5");
	if (random == 2) SetProtein("E");
}

DengueVirus* DengueVirus::DoClone()
{
	DengueVirus* deng = new DengueVirus();
	deng->SetProtein(this->m_protein);
	deng->m_dna = this->m_dna;
	deng->m_resistance = this->m_resistance;
	return deng;
}

void DengueVirus::DoDie()
{
	delete[] m_dna;
	delete[] m_protein;
	m_resistance = NULL;
}

void DengueVirus::InitResistance()
{
	srand(time(NULL));
	if(this->m_protein=="NS3") this->m_resistance = rand() % 10 + 1;
	if(this->m_protein=="NS5") this->m_resistance = rand() % 10 + 11;
	if(this->m_protein=="E")   this->m_resistance = rand() % 10 + 21;
}

void DengueVirus::SetProtein(const char m_protein[])
{
	int i = 0;
	while(m_protein != '\0'){
		this->m_protein[i] = m_protein[i];
		i++;
	}
}

char* DengueVirus::GetProtein()
{
	return this->m_protein;
}
