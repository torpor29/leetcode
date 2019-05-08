#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> nums = { 4,1,1,3,1,1,1};
	int result = 0;
	int index = 0;
	int n = nums.size();
	while (index < n-1) {
		if ((index + nums[index] == n-1) || (index + nums[index] > n-1)) {
			result++;
			break;
		}
		else {
			int tmpmax = nums[index+1]+index+1;
			int tmprec=index+1;
			for (int i = index + 1; i < index + nums[index] + 1; i++) {
				if (!((nums[i]+i) < tmpmax)) {
					tmpmax = nums[i]+i;
					tmprec = i;
				}
			}
			index = tmprec;
			result++;
		}
	}
	return 0;
}