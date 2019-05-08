#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(int n, int index, vector<string>addold,vector<vector<string>>& output)
{
	bool found = false;
	vector<string>add;
	for (int j = 0; j < n; j++) {
		add = addold;
		if (add[index][j] == ',') {
			found = true;
			add[index][j] = 'Q';
			if (index == n - 1) {
				output.push_back(add);
				int i = 0;
				while (i<n)
				{
					cout << add[i] << endl;
					i++;

				}
				cout << endl;
			}
			else {
				int i = 1;
				while (!((index-i)<0||(j-i)<0))
				{
					if (add[index - i][j - i] == ',') {
						add[index - i][j - i] = '.';
					}
					i++;
				}
				i = 1;
				while (!(index-i<0))
				{
					if (add[index - i][j] == ',') {
						add[index - i][j] = '.';
					}
					i++;
				}
				i = 1;
				while ((!(index-i<0))&&j+i<n)
				{
					if (add[index - i][j + i] == ',') {
						add[index - i][j + i] = '.';
					}
					i++;
				}
				i = 1;
				while (!(j-i<0))
				{
					if (add[index][j - i] == ',') {
						add[index][j - i] = '.';
					}
					i++;
				}
				i = 1;
				while (j+i<n)
				{
					if (add[index ][j + i] == ',') {
						add[index ][j + i] = '.';
					}
					i++;
				}
				i = 1;
				while (index+i<n&&(!(j-i<0)))
				{
					if (add[index + i][j - i] == ',') {
						add[index + i][j - i] = '.';
					}
					i++;
				}
				i = 1;
				while (index+i<n)
				{
					if (add[index + i][j ] == ',') {
						add[index + i][j ] = '.';
					}
					i++;
				}
				i = 1;
				while (index+i<n&&j+i<n)
				{
					if (add[index + i][j + i] == ',') {
						add[index + i][j + i] = '.';
					}
					i++;
				}
				
				i = 0; 
				while (i<n)
				{
					cout << add[i] << endl;
					i++;

				}
				cout << endl;
				solve(n, index+1, add, output);
			}
		}
	}
	
}

int main()
{
	int n = 4;
	string ini ;
	vector<vector<string>> output;
	vector<string>add;
	for (int i = 0; i < n; i++) {
		ini = ini + ",";
	}
	for (int i = 0; i < n; i++) {
		add.push_back(ini);
	}
	solve(n, 0, add, output);
	return 0;

}