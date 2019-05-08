#include<iostream>
#include<vector>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int a = 0; a < 9; a++) {
		if (a % 3 == 0) cout << endl;
		for (int b = 0; b < 9; b++) {
			if (b % 3 == 0) cout << ' ';
			cout << board[a][b] << ' ';

		}
		cout << endl;
	}
	cout << endl << endl << endl << endl;
	int z = 0;
	bool result = true;
	while (z < 9) {
		int j = 0;
		while (j < 9) {
			if (board[z][j] == '.') j++;
			else {
				for (int p = 0; p < 9; p++) {
					if ((board[z][p] == board[z][j]) && (p != j)) {
						result = false;
					}

				}
				if (result == false) break;
				for (int p = 0; p < 9; p++) {
					if ((board[p][j] == board[z][j]) && (p != z)) result = false;
				}
				if (result == false)break;
				int m = z / 3;
				int n = j / 3;
				for (int p = 0; p < 3; p++) {
					for (int q = 0; q < 3; q++) {
						int x = m * 3 + p;
						int y = n * 3 + q;
						if ((board[x][y] == board[z][j]) && (x != z) && (y != j)) {
							result = false;
						}
					}
				}
				if (result == false)break;
				else j++;
			}

		}
		if (result == false)break;
		else z++;
	}
	return result;
}

int main()
{
	vector<char> ini1 = { '.','.','9','7','4','8','.','.','.' };
	vector<char> ini2 = { '7','.','.','.','.','.','.','.','.' };
	vector<char> ini3 = { '.','2','.','1','.','9','.','.','.' };
	vector<char> ini4 = { '.','.','7','.','.','.','2','4','.' };
	vector<char> ini5 = { '.','6','4','.','1','.','5','9','.' };
	vector<char> ini6 = { '.','9','8','.','.','.','3','.','.' };
	vector<char> ini7 = { '.','.','.','8','.','3','.','2','.' };
	vector<char> ini8 = { '.','.','.','.','.','.','.','.','6' };
	vector<char> ini9 = { '.','.','.','2','7','5','9','.','.' };
	vector<vector<char>> board;
	board.push_back(ini1);
	board.push_back(ini2);
	board.push_back(ini3);
	board.push_back(ini4);
	board.push_back(ini5);
	board.push_back(ini6);
	board.push_back(ini7);
	board.push_back(ini8);
	board.push_back(ini9);
	int numofdot = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') numofdot++;
		}
	}
	int numofdotbe = numofdot;
	int guess = 1;
	int bakx;
	int baky;
	vector<vector<char>> bakboard;
	int baknum;
	while (numofdot != 0)
	{
		for (int n = 1; n < 10; n++) {//´Ó1µ½9Ë³´ÎÊÔÌî
			vector<vector<char>>tmp = board;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] - '0' == n) {
						for (int p = 0; p < 9; p++) {
							if (board[i][p] == '.') tmp[i][p] = ',';
						}
						for (int p = 0; p < 9; p++) {
							if (board[p][j] == '.') tmp[p][j] = ',';
						}
						int cubex = i / 3;
						int cubey = j / 3;
						for (int p = 0; p < 3; p++) {
							for (int q = 0; q < 3; q++) {
								int x = cubex * 3 + p;
								int y = cubey * 3 + q;
								if (board[x][y] == '.') tmp[x][y] = ',';
							}
						}
					}
				}
			}

			for (int a = 0; a < 9; a++) {
				if (a % 3 == 0) cout << endl;
				for (int b = 0; b < 9; b++) {
					if (b % 3 == 0) cout << ' ';
					cout << tmp[a][b] << ' ';

				}
				cout << endl;
			}
			cout << endl << endl << endl << endl;

			for (int i = 0; i < 9; i++) {
				int numofdotl = 0;
				int locofdot = 0;
				for (int j = 0; j < 9; j++) {
					if (tmp[i][j] == '.') {
						numofdotl++;
						locofdot = j;
					}
				}
				if (numofdotl == 1) {
					tmp[i][locofdot] = '0' + n;
					board[i][locofdot] = '0' + n;

					for (int tmpi = 0; tmpi < 9; tmpi++) {
						if (tmp[i][tmpi] == '.') {
							tmp[i][tmpi] = ',';
						}
						if (tmp[tmpi][locofdot] == '.') {
							tmp[tmpi][locofdot] = ',';
						}
					}
					int tmpx = i / 3;
					int tmpy = locofdot / 3;
					for (int tmpi = 0; tmpi < 3; tmpi++) {
						for (int tmpj = 0; tmpj < 3; tmpj++) {
							int x = tmpx * 3 + tmpi;
							int y = tmpy * 3 + tmpj;
							if (tmp[x][y] == '.') {
								tmp[x][y] = ',';
							}
						}
					}
					for (int a = 0; a < 9; a++) {
						if (a % 3 == 0) cout << endl;
						for (int b = 0; b < 9; b++) {
							if (b % 3 == 0) cout << ' ';
							cout << tmp[a][b] << ' ';

						}

						cout << endl;
					}
					cout << i << ' ' << locofdot << ' ' << n << ' ' << '1' << endl;
					numofdot--;
				}
			}
			for (int i = 0; i < 9; i++) {
				int numofdotl = 0;
				int locofdot = 0;
				for (int j = 0; j < 9; j++) {
					if (tmp[j][i] == '.') {
						numofdotl++;
						locofdot = j;
					}
				}
				if (numofdotl == 1) {
					tmp[locofdot][i] = '0' + n;
					board[locofdot][i] = '0' + n;

					for (int tmpi = 0; tmpi < 9; tmpi++) {
						if (tmp[i][tmpi] == '.') {
							tmp[i][tmpi] = ',';
						}
						if (tmp[locofdot][tmpi] == '.') {
							tmp[locofdot][tmpi] = ',';
						}
					}
					int tmpy = i / 3;
					int tmpx = locofdot / 3;
					for (int tmpj = 0; tmpj < 3; tmpj++) {
						for (int tmpi = 0; tmpi < 3; tmpi++) {
							int x = tmpx * 3 + tmpi;
							int y = tmpy * 3 + tmpj;
							if (tmp[x][y] == '.') {
								tmp[x][y] = ',';
							}
						}
					}
					for (int a = 0; a < 9; a++) {
						if (a % 3 == 0) cout << endl;
						for (int b = 0; b < 9; b++) {
							if (b % 3 == 0) cout << ' ';
							cout << tmp[a][b] << ' ';

						}

						cout << endl;
					}
					cout << locofdot << ' ' << i << ' ' << n << ' ' << '2' << endl;
					numofdot--;
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int numofdotl = 0;
					int locofdotx = 0;
					int locofdoty = 0;
					for (int p = 0; p < 3; p++) {
						for (int q = 0; q < 3; q++) {
							int x = i * 3 + p;
							int y = j * 3 + q;
							if (tmp[x][y] == '.') {
								numofdotl++;
								locofdotx = x;
								locofdoty = y;
							}

						}
					}
					if (numofdotl == 1) {
						tmp[locofdotx][locofdoty] = '0' + n;
						board[locofdotx][locofdoty] = '0' + n;

						for (int tmpi = 0; tmpi < 9; tmpi++) {
							if (tmp[locofdotx][tmpi] == '.') {
								tmp[locofdotx][tmpi] = ',';
							}
							if (tmp[tmpi][locofdoty] == '.') {
								tmp[tmpi][locofdoty] = ',';
							}
						}
						int tmpx = locofdotx / 3;
						int tmpy = locofdoty / 3;
						for (int tmpi = 0; tmpi < 3; tmpi++) {
							for (int tmpj = 0; tmpj < 3; tmpj++) {
								int x = tmpx * 3 + tmpi;
								int y = tmpy * 3 + tmpj;
								if (tmp[x][y] == '.') {
									tmp[x][y] = ',';
								}
							}
						}
						for (int a = 0; a < 9; a++) {
							if (a % 3 == 0) cout << endl;
							for (int b = 0; b < 9; b++) {
								if (b % 3 == 0) cout << ' ';
								cout << tmp[a][b] << ' ';

							}

							cout << endl;
						}
						cout << locofdotx << ' ' << locofdoty << ' ' << n << ' ' << '3' << endl;
						numofdot--;
					}
				}
			}

		}

		if ((numofdot == numofdotbe) && (bakboard.size() == 0)) {
			guess = 1;
			bakboard = board;
			int i = 0;
			bool flag = false;
			while (i<9) {
				int j = 0;
				while (j<9) {
					if (board[i][j] == '.') {
						bakx = i;
						baky = j;
						board[i][j] = '0' + guess;
						while (isValidSudoku(board) == false) {
							guess++;
							board[i][j] = '0' + guess;
						}
						flag = true;
						break;
					}
					else j++;
				}
				if (flag == true)break;
				else i++;
			}
			baknum = numofdot;
			numofdot--;
		}
		else if ((numofdot == numofdotbe) && (bakboard.size() != 0)) {
			board = bakboard;
			numofdot = baknum - 1;
			guess++;
			board[bakx][baky] = '0' + guess;
			while (isValidSudoku(board) == false) {
				guess++;

				board[bakx][baky] = '0' + guess;
			}

		}
		else if (isValidSudoku(board) == false) {
			board = bakboard;
			numofdot = baknum - 1;
			while (isValidSudoku(board) == false) {
				guess++;

				board[bakx][baky] = '0' + guess;
			}
		}

		else numofdotbe = numofdot;
	}
	return 0;
}