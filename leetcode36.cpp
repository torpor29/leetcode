#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<char> ini1 = { '8','3','.','.','7','.','.','.','.' };
	vector<char> ini2 = { '6','.','.','1','9','5','.','.','.' };
	vector<char> ini3 = { '.','9','8','.','.','.','.','6','.' };
	vector<char> ini4 = { '8','.','.','.','6','.','.','.','3' };
	vector<char> ini5 = { '4','.','.','8','.','3','.','.','1' };
	vector<char> ini6 = { '7','.','.','.','2','.','.','.','6' };
	vector<char> ini7 = { '.','6','.','.','.','.','2','8','.' };
	vector<char> ini8 = { '.','.','.','4','1','9','.','.','5' };
	vector<char> ini9 = { '.','.','.','.','8','.','.','7','9' };
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
	return 0;
	
}