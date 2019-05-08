#include<iostream>
#include<vector>
#include<string>
using namespace std;

string solve(string s)
{
	string result="";
	int n = s.length();
	char tmp;
	int num = 0;
	int i = 0;
	while (i<n)
	{
		if (i == 0) {
			tmp = s[i];
			num = 1;
			i++;
		}
		else {
			if (s[i] == tmp) {
				num++;
				i++;
			}
			else {
				result = result + to_string(num);
				result = result + tmp;
				tmp = s[i];
				num = 1;
				i++;
			}
		}
	}
	result = result + to_string(num);
	result = result + tmp;
	return result;
}

int main()
{
	int n = 7;
	string s ;
	string result;
	if (n == 0) s="";
	else if (n == 1) {
		s = "1";
	}
	else {
		s = "1";
		int i = 1;
		while (i < n) {
			result = solve(s);
			s = result;
			i++;
		}
	}
	return 0;
}