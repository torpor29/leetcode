#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> matrix;
	vector<int>ini1 = { 1,2,3 };
	vector<int>ini2 = { 5,6,7 };
	vector<int>ini3 = { 9,10,11 };
	vector<int>ini4 = { 13,14,15 };
	//matrix.push_back(ini1);
	//matrix.push_back(ini2);
	//matrix.push_back(ini3);
	//matrix.push_back(ini4);
	
	int i = 0;
	int ver = matrix.size() - 1;
	int hor = matrix[0].size() - 1;
	if (ver < 0 || hor < 0) return 0;
	vector<int> output;
	while ((ver - i>i) && (hor - i>i)) {
		int tmpi = i;
		int tmpj = i;
		for (tmpj = i; tmpj<hor - i + 1; tmpj++) {
			output.push_back(matrix[tmpi][tmpj]);
		}
		tmpj--;
		for (tmpi = i + 1; tmpi<ver - i + 1; tmpi++) {

			output.push_back(matrix[tmpi][tmpj]);
		}
		tmpi--;
		for (tmpj = tmpj - 1; tmpj>i - 1; tmpj--) {
			output.push_back(matrix[tmpi][tmpj]);
		}
		tmpj++;
		for (tmpi = tmpi - 1; tmpi>i; tmpi--) {
			output.push_back(matrix[tmpi][tmpj]);
		}
		i++;
	}
	if (ver - i == i) {
		int tmpi = i;
		int tmpj = i;
		for (tmpj = i; tmpj<hor - i + 1; tmpj++) {
			output.push_back(matrix[tmpi][tmpj]);
		}
	}
	else if (hor - i == i) {
		int tmpi = i;
		int tmpj = i;
		for (tmpi = i; tmpi<ver - i + 1; tmpi++) {
			output.push_back(matrix[tmpi][tmpj]);
		}
	}
	return 0;
}