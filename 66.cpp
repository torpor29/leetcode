#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>digits = { 9,9 };
	int quo = 0;
	int rem = 0;
	int i = digits.size() - 1;
	quo = (digits[i] + 1) / 10;
	rem = (digits[i] + 1) % 10;
	digits[i] = rem;
	i--;
	while (i>0) {
		rem = (digits[i] + quo) % 10;
		quo = (digits[i] + quo) / 10;
		digits[i] = rem;
		i--;
	}
	if (quo != 0) {
		digits.insert(digits.begin(), quo);
	}
	return 0;
}