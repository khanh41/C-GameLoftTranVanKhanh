#pragma once
#include<iostream>
#include "Virus.h"
#include <list>
#include<time.h>
using namespace std;
#define ALIVE 1
#define DIE 0
class Patient
{
private:
	int m_resistance; // his natural resistance
	list<Virus*> m_virusList; // The current virus in his body
	int m_state; // 0 – DIE, 1 - ALIVE
public:
	Patient();
	Patient(int, list<Virus*>, int);
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine();
	void DoDie();
	int getState();
	int TotalVirusResistance(list<Virus*>);
};


