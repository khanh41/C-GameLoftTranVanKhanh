#include "Virus.h"

Virus::Virus()
{
	this->m_dna = new char[100]{""};
	this->m_resistance = 0;
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
	this->SetDna(virus.m_dna);
	this->setResistance(virus.m_resistance);
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
	this->m_resistance -= medicine_resistance;
	if (this->m_resistance<=0) //if virus die
	{
		return true;
	}
	return false;
}

void Virus::DoBorn()
{
}

int Virus::getResistance()
{
	return this->m_resistance;
}

void Virus::setResistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}

void Virus::SetDna(const char m_dna[])
{
	this->m_dna = new char[100]{ "" };
	int i = 0;
	while (m_dna[i] != '\0') {
		this->m_dna[i] = m_dna[i];
		i++;
	}
}

char* Virus::GetDna()
{
	return this->m_dna;
}

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
}

FluVirus::FluVirus(const FluVirus& deng): Virus(deng)
{
	this->SetColor(deng.m_color);
}

void FluVirus::DoBorn()
{
	LoadADNInformation();
	this->m_color = rand() % 2 ? BLUE : RED;
}

FluVirus* FluVirus::DoClone(list<Virus*> &list)
{
	cout << "-(Clone FluVirus)" << endl;
	FluVirus *flu = new FluVirus(*this);
	return flu;
}

void FluVirus::DoDie()
{
	m_color = NULL;
	m_resistance = NULL;
}

void FluVirus::InitResistance()
{
	int min, max;
	if (this->m_color == BLUE) //blue -> random 10-15
	{
		min = 10;
		max = 15;
	}
	else{ //red - random 10->20
		min = 10;
		max = 20;
	}
	this->m_resistance = rand() % (max - min + 1) + min;;
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
	DoBorn();
	InitResistance();
}

DengueVirus::DengueVirus(const DengueVirus& deng) : Virus(deng)
{
	this->SetProtein(deng.m_protein);
}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
	int random = rand() % 3;
	if (random == 0) SetProtein("NS3");
	if (random == 1) SetProtein("NS5");
	if (random == 2) SetProtein("E");
}

DengueVirus* DengueVirus::DoClone(list<Virus*>& list)
{
	cout << "-(Clone DangueVirus)" << endl;
	
	DengueVirus* deng = new DengueVirus(*this);
	list.push_back(deng);
	deng = NULL;
	delete deng;
	deng = new DengueVirus(*this);
	return deng;
}

void DengueVirus::DoDie()
{
	delete[] this->m_protein;
	m_resistance = NULL;
}

void DengueVirus::InitResistance()
{
	string *temp = new string[100]{""};
	*temp = this->m_protein;
	if(*temp=="NS3") this->m_resistance = rand() % 10 + 1;
	if(*temp=="NS5") this->m_resistance = rand() % 10 + 11;
	if(*temp=="E")   this->m_resistance = rand() % 10 + 21;
	delete[] temp;
}

void DengueVirus::SetProtein(const char m_protein[])
{
	this->m_protein = new char[100]{""};
	int i = 0;
	while(m_protein[i] != '\0'){
		this->m_protein[i] = m_protein[i];
		i++;
	}
}

char* DengueVirus::GetProtein()
{
	return this->m_protein;
}
