#pragma once
#include<iostream>
#include "Virus.h"
#include <list>
#include<time.h>
using namespace std;
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
	void DoStart();
};

