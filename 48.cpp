#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<vector<int>> matrix;
	vector<int>ini0 = { 5,1,9,11 };
	vector<int>ini1 = { 2,4,8,10 };
	vector<int>ini2 = { 13,3,6,7 };
	vector<int>ini3 = { 15,14,12,16 };
	matrix.push_back(ini0);
	matrix.push_back(ini1);
	matrix.push_back(ini2);
	matrix.push_back(ini3);
	int n = matrix.size();
	float cen = (n-1)/2.0;
	int brei = n / 2 ;
	int i = 0;
	while (i<brei)
	{
		for (int j = i; j < n - 1 - i; j++) {
			int oldi = i;
			int oldj = j;
			float tmpi = oldj;
			float tmpj = 2 * cen - oldi;
			int tmp = matrix[tmpi][tmpj];
			int tmpold= matrix[oldi][oldj];
			matrix[tmpi][tmpj] = tmpold;


			oldi = tmpi;
			oldj = tmpj;
			tmpi = oldj;
			tmpj = 2 * cen - oldi;
			tmpold = tmp;
			tmp = matrix[tmpi][tmpj];
			matrix[tmpi][tmpj] = tmpold;


			oldi = tmpi;
			oldj = tmpj;
			tmpi = oldj;
			tmpj = 2 * cen - oldi;
			tmpold = tmp;
			tmp = matrix[tmpi][tmpj];
			matrix[tmpi][tmpj] = tmpold;

			matrix[i][j] = tmp;

			for (int p = 0; p < n; p++) {
				for (int q = 0; q < n; q++) {
					cout << matrix[p][q] << ' ';
				}
				cout << endl;

			}
			cout << endl;
		}
		i++;
	}

	return 0;
}