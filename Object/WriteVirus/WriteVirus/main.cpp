#include<iostream>
#include"Patient.h"
#include"Virus.h"
using namespace std;
int main() {
	srand(time(NULL));
	Patient p;
	int t = 0;
	if (p.getState() == 1)
	{
		cout<<"Take Medicine (0 = NO, 1 = YES): ";
		cin>>t;
		if (t == 1)
		{
			p.TakeMedicine();
		}
		else {
			cout << "No take" << endl;
		}
	}
	if (p.getState() == 1) cout << endl << "KILLED ALL" << endl;
	else cout << endl << "YOU DIED" << endl;
	return 0;
}