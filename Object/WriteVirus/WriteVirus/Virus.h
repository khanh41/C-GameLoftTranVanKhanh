#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
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
	virtual void DoBorn() = 0;
	virtual Virus* DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};

class FluVirus:public Virus {
private:
	int m_color;//blue (value 0x0000ff) or red (value 0xff0000)
public:
	void DoBorn();
	FluVirus *DoClone();
	void DoDie();
	void InitResistance();
	void SetColor(int);
	int GetColor();
};

class DengueVirus :public Virus {
private:
	char m_protein[4];
public:
	DengueVirus();
	DengueVirus(char*,int,char[]);
	void DoBorn();
	DengueVirus* DoClone();
	void DoDie();
	void InitResistance();
	void SetProtein(const char[]);
	char* GetProtein();
};
