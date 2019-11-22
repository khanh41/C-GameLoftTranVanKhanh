#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Virus
{
protected:
	char* m_dna; // A,T,G,X
	int m_resistance;//10-30
public:
	Virus();
	Virus(char*, int);
	~Virus();
	Virus(const Virus&);
	void LoadADNInformation(); // load m_dna from file 
	bool ReduceResistance(int); // when call TakeMedicine: m_resistance -= medicine_resistance, <=0 destroyed virus
	virtual void DoBorn();
	virtual void DoClone();
	virtual void DoBDie();
	virtual void InitResistance();
};

