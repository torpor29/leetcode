#include<iostream>
#include<vector>
#include<string>
using namespace std;
int fac(int n) {
	int result = 1;;
	for (int i = 1; i<n + 1; i++) {
		result *= i;
	}
	return result;
}

int main()
{
	int n = 3;
	int k = 5;
	string result = "";
	vector<int> nums;
	for (int i = 1; i<n + 1; i++) {
		nums.push_back(i);
	}
	int i = 0;
	int quo;
	int rem;
	while (i<n) {
		if (i == n - 1) {
			char tmp;
			tmp = '0' + nums[0];
			result = result + tmp;
			break;

		}
		int fact = fac(n - 1 - i);
		quo = k / fact;
		rem = k%fact;
		if (rem == 0) {
			char tmp;
			tmp = '0' + nums[quo - 1];
			result = result + tmp;
			nums.erase(nums.begin() + quo - 1);
		}
		else {
			char tmp;
			tmp = '0' + nums[quo];
			result = result + tmp;
			nums.erase(nums.begin() + quo);
		}
		k = k - fact*quo;
		if (k == 0) k = fact;
		i++;
	}
	int t = 0 % 2;

	return 0;
}