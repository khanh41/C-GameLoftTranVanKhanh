#include <iostream>
#include<list>
#include <fstream>
#include <string>
using namespace std;
struct students {
	int id;
	string name;
	float score;
};
void main()
{
	list<students> listSt;
	int choose;
	do {
		cout << "-----------MENU----------" << endl;
		cout << "\t1. Input" << endl;
		cout << "\t2. Display" << endl;
		cout << "\t3. Save to file" << endl;
		cout << "\t4. Load from file" << endl;
		cout << "\t0. Exit" << endl;
		cout << "Choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1: while (input(listSt)); break;
		case 2:
			cout << "\t" << "ID" << "\t\t" << "NAME" << "\t\t" << "SCORE" << endl;
			output(listSt);
			break;
		case 3:
			savefile(listSt);
			break;
		case 4:
			loadfile(listSt);
		}
		cout << endl;
	} while (choose != 0);
	reuturn 0;
}