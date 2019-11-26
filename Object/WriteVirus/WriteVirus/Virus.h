#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<list>
using namespace std;
#define BLUE 111
#define RED 222
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
	virtual Virus* DoClone(list<Virus*>&) = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
	int getResistance();
	void setResistance(int);
	void SetDna(const char[]);
	char* GetDna();
};

class FluVirus:public Virus {
private:
	int m_color;//blue (value 0x0000ff) or red (value 0xff0000)
public:
	FluVirus();
	FluVirus(const FluVirus&);
	void DoBorn();
	FluVirus *DoClone(list<Virus*>&);
	void DoDie();
	void InitResistance();
	void SetColor(int);
	int GetColor();
};

class DengueVirus :public Virus {
private:
	char* m_protein;
public:
	DengueVirus();
	DengueVirus(const DengueVirus&);
	void DoBorn();
	DengueVirus* DoClone(list<Virus*>&);
	void DoDie();
	void InitResistance();
	void SetProtein(const char[]);
	char* GetProtein();
};
