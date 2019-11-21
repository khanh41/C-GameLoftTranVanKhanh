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
bool input(list<students>& listStudent) {

	students student;
	list<students>::iterator it;
	bool checkExis = 0;
	cout << "Nhap id (0 neu khong nhap): ";
	do {
		checkExis = 0;
		cin >> student.id;
		if (student.id == 0) return false;
		for (it = listStudent.begin(); it != listStudent.end(); it++)
		{
			if (student.id == (*it).id) {
				checkExis = 1;
				cout << "Nhap lai id: ";
				break;
			}
		}
	} while (checkExis);
	cout << "Nhap name: ";
	cin >> student.name;
	cout << "Nhap score: ";
	do {
		cin >> student.score;
		if (student.score <= 10 && student.score >= 0) break;
		cout << "nhap lai score (0 den 10)";
	} while (1 == 1);
	listStudent.push_back(student);
	return true;
}
void output(list<students> listStudent)
{
	list<students>::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); it++)
	{
		cout << "\t" << (*it).id << "\t\t" << (*it).name << "\t\t" << (*it).score << endl;
	}
	cout << '\n';
}
void savefile(list<students> listStudent) {
	ofstream myfile("DSSV.txt");
	if (myfile.is_open())
	{
		list<students>::iterator it;
		for (it = listStudent.begin(); it != listStudent.end(); it++)
			myfile << "\t" << (*it).id << "\t\t" << (*it).name << "\t\t" << (*it).score << endl;
		myfile.close();
	}
	else cout << "Unable to open file";
}
void loadfile(list<students> listStudent) {
	string line;
	ifstream myfile("DSSV.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}void main()
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

}