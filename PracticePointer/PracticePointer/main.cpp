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
bool InPut(list<students*> &listStudent) {

	students* student = new students;
	list<students*>::iterator it;
	bool checkExis = 0;
	cout << "Input ID (0 to stop): ";
	do {
		checkExis = 0;
		cin >> student->id;
		if (student->id == 0) return false;
		for (it = listStudent.begin(); it != listStudent.end(); it++)
		{
			if (student->id == (*it)->id) {
				checkExis = 1;
				cout << "Input ID again: ";
				break;
			}
		}
	} while (checkExis);
	cout << "Input Name: ";
	cin >> student->name;
	cout << "Input Score: ";
	do {
		cin >> student->score;
		if (student->score <= 10 && student->score >= 0) break;
		cout << "Input Score again (0 to 10)";
	} while (1 == 1);
	listStudent.push_back(student);
//	delete student;
	return true;
}
void OutPut(list<students*> listStudent)
{
	list<students*>::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); it++)
	{
		cout << "\t" << (*it)->id << "\t\t" << (*it)->name << "\t\t" << (*it)->score << endl;
	}
	cout << '\n';
}
void SaveFile(list<students*> listStudent) {
	ofstream myfile("DSSV.txt");
	if (myfile.is_open())
	{
		list<students*>::iterator it;
		for (it = listStudent.begin(); it != listStudent.end(); it++)
			myfile << "\t" << (*it)->id << "\t\t" << (*it)->name << "\t\t" << (*it)->score << endl;
		myfile.close();
	}
	else cout << "Unable to open file";
}
void LoadFile(list<students*> &listStudent) {
	string line;
	ifstream myfile("DSSV.txt");
	students* student = new students;
	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			cout << line << '\n';
			for (int i = 0, dem = 0; i < line.length(); i++) {
				if (line[i] != '\t') {
					string temp;
					while (line[i] != '\t' && i < line.length())
					{
						temp += line[i];
						i++;
					}
					if (dem == 0) student->id = stoi(temp, 0, 10);
					if (dem == 1) student->name = temp;
					if (dem == 2) student->score = stoi(temp, 0, 10);
					dem++;
					i--;
				}
			}
			listStudent.push_back(student);
		}
		delete student;
		myfile.close();
	}
	else cout << "Unable to open file";
}void main()
{
	list<students*> listSt;
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
		case 1: while (InPut(listSt)); break;
		case 2:
			cout << "\t" << "ID" << "\t\t" << "NAME" << "\t\t" << "SCORE" << endl;
			OutPut(listSt);
			break;
		case 3:
			SaveFile(listSt);
			break;
		case 4:
			LoadFile(listSt);
		}
		cout << endl;
	} while (choose != 0);

}