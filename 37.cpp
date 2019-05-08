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

bool solve(vector<vector<char>>& board) {
	bool result;
	bool tmp;
	int numofdot = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') numofdot++;
		}
	}
	int numofdotbe = 0;
	int guess = 1;
	int bakx;
	int baky;
	vector<vector<char>> bakboard;
	int baknum;
	while (numofdot != numofdotbe)
	{
		numofdotbe = numofdot;
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
						if (tmp[tmpi][i] == '.') {
							tmp[tmpi][i] = ',';
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
	}
	result = isValidSudoku(board);
	if ((result == true) && (numofdot != 0)) {

		cout << "insert" << endl;
		bakboard = board;
		baknum = numofdot;
		int i = 0;
		while (i<9)
		{
			int j = 0;
			bool flag = false;
			while (j<9)
			{
				if (board[i][j] == '.') {
					board[i][j] = '0' + guess;
					bakx = i;
					baky = j;
					flag = true;
					break;
				}
				else j++;
			}
			if (flag == true) break;
			else i++;
		}
		numofdot--;
		tmp=solve(board);
		while ((tmp == false) && (guess < 9)) {
			cout << "xiugai" << bakx << ' ' << baky << ' ' << guess << endl;
			board = bakboard;
			guess++;
			board[bakx][baky] ='0'+ guess;
			tmp = solve(board);
		}
		if (tmp == false) {
			return false;
		}
		else return true;
	}
	else if (result == false) return false;
	else return true;
	
	

}

int main()
{
	vector<char> ini1 = { '1','.','.','.','7','.','.','3','.' };
	vector<char> ini2 = { '8','3','.','6','.','.','.','.','.' };
	vector<char> ini3 = { '.','.','2','9','.','.','6','.','8' };
	vector<char> ini4 = { '6','.','.','.','.','4','9','.','7' };
	vector<char> ini5 = { '.','9','.','.','.','.','.','5','.' };
	vector<char> ini6 = { '3','.','7','5','.','.','.','.','4' };
	vector<char> ini7 = { '2','.','3','.','.','9','1','.','.' };
	vector<char> ini8 = { '.','.','.','.','.','2','.','4','3' };
	vector<char> ini9 = { '.','4','.','.','8','.','.','.','9' };
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
	bool result;

	result=solve(board);
	return 0;
}