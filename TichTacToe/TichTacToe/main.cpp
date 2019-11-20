#include<iostream>
#include <time.h>
using namespace std;

#define size 10 // do dai va rong cua ban co
#define tickX 1
#define tickO 0
#define lengthWin 4 // do dai chien thang
#define fill size*size-1 // het o trong de danh
int init(int& select, string& playerO, string& playerX, int board[size][size]);
bool check(int board[size][size], int tick, int row, int col);
void print(int a[size][size]);
bool change(string player, int board[size][size], int& row, int& col, int tick);
int main() {
	srand(time(NULL));
	int select, row, col;
	bool player1Win = rand() % 2;
	int board[size][size];
	string playerO, playerX;

	//loi gioi thieu, nhap cac tham so
	if (init(select, playerO, playerX, board) == 0) return 0;

	//play
	for (int i = 0; i < size * size; i++) {
		string index;
		player1Win = !player1Win;
		if (player1Win) {
			if (change(playerO, board, row, col, tickO)) break;
		}
		else if (change(playerX, board, row, col, tickX)) break;
		print(board);
		if (i == fill) cout << "Draw" << endl;
	}
	print(board);
	return 0;
}

int init(int& select, string& playerO, string& playerX, int board[size][size]) {
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl
		<< "If you find any problem, please contact john.nguyen@gameloft.com" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin >> select;
	if (select != 1) return 0;
	cout << "Enter Player 1-O Name: ";
	cin >> playerO;
	cout << "Enter Player 2-X Name: ";
	cin >> playerX;
	print(board);
	return 1;
}
bool check(int board[size][size], int tick, int row, int col) {
	//check duong cheo
	//tick = tickX || tick = tickO
	int dem = 0;
	int sovonglap = row + lengthWin + 1; //row - lengthWin + 1 + lengthWin * 2;
	for (int i = row - lengthWin + 1, j = col + lengthWin - 1; i < sovonglap; i++, j--) {
		if (i < 0 || j < 0) continue;
		if (board[i][j] == tick) dem++;
		else dem = 0;
		if (dem == lengthWin) {
			if (board[i + 1][j - 1] != 1 - tick || board[i - lengthWin][j + lengthWin] != 1 - tick)
				return true;
		}
	}
	dem = 0;
	for (int i = row - lengthWin + 1, j = col - lengthWin + 1; i < sovonglap; i++, j++) {
		if (i < 0 || j < 0) continue;
		if (board[i][j] == tick) dem++;
		else dem = 0;
		if (dem == lengthWin) {
			if (board[i + 1][j + 1] != 1 - tick || board[i - lengthWin][col - lengthWin] != 1 - tick)
				return true;
		}
	}
	//check duong thang theo cot
	dem = 0;
	for (int i = row - lengthWin + 1; i < sovonglap; i++) {
		if (i < 0) continue;
		if (board[i][col] == tick) dem++;
		else dem = 0;
		if (dem == lengthWin) {
			if (board[i + 1][col] == 1 - tick || board[i - lengthWin][col] == 1 - tick)
				return true;
		}
	}
	//check duong thang theo hang
	dem = 0;
	sovonglap = col + lengthWin + 1;
	for (int j = col - lengthWin + 1; j < sovonglap; j++) {
		if (j < 0) j = 0;
		if (board[row][j] == tick) dem++;
		else dem = 0;
		if (dem == lengthWin) {
			if (board[row][j + 1] == 1 - tick || board[row][j - lengthWin] == 1 - tick)
				return true;
		}
	}
	return false;
}
void print(int a[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] == 1) cout << " X ";
			else if (a[i][j] == 0) cout << " O ";
			else cout << " - ";
		}
		cout << endl;
	}
}
bool change(string player, int board[size][size], int& row, int& col, int tick) {
	string index;
	do {
		if (tick == 0) cout << "Your Turn " << player << " - O: ";
		else cout << "Your Turn " << player << " - X: ";
		cin >> index;
		row = (int)index[0] - '0';
		col = (int)index[1] - '0';
	} while (board[row][col] == 0 || board[row][col] == 1 || row > size - 1 || row < 0
		|| col>size - 1 || col < 0);

	board[(int)index[0] - '0'][(int)index[1] - '0'] = tick;
	if (check(board, tick, row, col)) {
		cout << player << " Win" << endl;
		return true;
	}
	return false;
}