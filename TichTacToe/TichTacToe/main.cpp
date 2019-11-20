#include<iostream>
#include <time.h>
using namespace std;
bool check(int a[3][3]) {
	for (int i = 0; i < 2; i++) {
		if (a[0][0] == i && a[1][1] == i && a[2][2] == i) return true;
		if (a[0][2] == i && a[1][1] == i && a[2][0] == i) return true;
		for (int j = 0; j < 3; j++) {
			if (a[j][0] == i && a[j][1] == i && a[j][2] == i) return true;
			if (a[0][j] == i && a[1][j] == i && a[2][j] == i) return true;
		}
	}
	return false;
}
void print(int a[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == 1) cout << "X";
			else if (a[i][j] == 0) cout << "O";
			else cout << "-";
		}
		cout << endl;
	}
}
int main() {
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl
		<< "If you find any problem, please contact john.nguyen@gameloft.com" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	int select,row,col;
	srand(time(NULL));
	bool player1Win= rand() % 2;
	int arr[3][3];
	string player1, player2;
	cin >> select;
	if (select != 1) return 0;
	cout << "Enter Player 1 Name: ";
	cin >> player1;
	cout << "Enter Player 2 Name: ";
	cin >> player2;
	for (int i = 0; i < 9; i++) {
		string index;
		player1Win = !player1Win;
		if (player1Win) {
			do {
				cout << "Your Turn "<<player1<<" - O: ";
				cin >> index;
				row = (int)index[0] - '0';
				col = (int)index[1] - '0';
			} while (arr[row][col] == 0 || arr[row][col] == 1 || row > 2 || row < 0 || col>2 || col < 0);
			arr[(int)index[0]-'0'][(int)index[1] - '0'] = 0;
			if(i>2)
				if (check(arr)) {
					cout << player1<<" Win"<<endl;
					break;
				}
		}
		else {
			do {
				cout << "Your Turn "<<player2<<" - X: ";
				cin >> index;
				row = (int)index[0] - '0';
				col = (int)index[1] - '0';
			} while (arr[row][col] == 0 || arr[row][col] == 1 || row>2 || row <0 || col>2 || col<0);
			arr[row][col] = 1;
			if(i>2)
				if (check(arr)) {
					cout << player2<<" Win"<<endl;
					break;
				}
		}
		print(arr);
		if (i == 8)cout << "Draw"<<endl;
	}
	print(arr);
	return 0;
}