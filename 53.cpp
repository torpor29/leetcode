#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
	int n = nums.size();
	int *dp = new int[n];
	dp[0] = nums[0];
	int output;
	output = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
		if (dp[i] > output) output = dp[i];
	}

	return 0;
}