#include<iostream>
#include"Patient.h"
#include"Virus.h"
#include"vld.h"
#define USE 1
using namespace std;
int main() {
	srand(time(NULL));
	Patient p;
	int t = 0, count = 0;
	while (p.getState() == ALIVE && p.getSize() > 0)
	{
		cout<<"Take Medicine (0 = NO, 1 = YES): ";
		cin>>t;
		if (t == USE)
		{
			count++;
			p.TakeMedicine();
		}
		else {
			cout << "xxxNo take" << endl;
			if (p.getSize() > 0) p.setState(DIE);
			break;
		}
	}
	if (p.getState() == ALIVE) cout << endl << "KILLED ALL" << endl;
	else cout << endl << "YOU DIED" << endl;
	cout << endl << "YOU USE " << count << " MEDICINE" << endl;
	system("pause");
	return 0;
}