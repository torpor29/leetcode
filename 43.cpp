#include<iostream>
#include<vector>
#include<string>
using namespace std;

string add(string s1, string s2)
{
	string result;
	s1 = s1 + "0";
	int num0=0;
	int num1=0;
	int i = s1.length() ;
	int j = s2.length() ;
	while (i!=0&&j!=0)
	{
		i--;
		j--;
		num0 = (s1[i] - '0' + s2[j] - '0'+num1) % 10;
		num1 = (s1[i] - '0' + s2[j] - '0'+num1) / 10;
		char tmp =  '0'+num0;
		result =tmp+result;
		
	}
	if (j == 0) {
		while (i!=0) {
			i--;
			num0 = (s1[i] - '0' + num1) % 10;
			num1 = (s1[i] - '0' + num1) / 10;
			char tmp = '0' + num0;
			result = tmp + result;
		}
	}
	if (num1 != 0) {
		char tmp = '0' + num1;
		result = tmp + result;
	}
	return result;

}

string times(string s1, char num)
{
	string result;
	int num0=0;
	int num1 = 0;
	int i = s1.length();
	while (i!=0)
	{
		i--;
		num0 = ((num - '0')*(s1[i] - '0') + num1)%10;
		num1 = ((num - '0')*(s1[i] - '0') + num1) / 10;
		char tmp = '0' + num0;
		result = tmp + result;
	}
	if (num1 != 0) {
		char tmp = '0' + num1;
		result = tmp + result;
	}
	return result;
}

int main()
{
	string num1 = "999";
	string num2 = "999";

	int i = 0;
	string result;
	//result = times(num1, num2[0]);
	string record;
	string tmp;
	while (i<num2.length())
	{
		tmp = times(num1, num2[i]);
		if (i == 0) {
			result = tmp;
		}
		else {
			result = add(result, tmp);
		}
		i++;
	}



	return 0;

}