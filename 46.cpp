#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> solve(vector<int>& nums)
{
	vector<vector<int>>output;
	if (nums.size() == 1) {
		output.push_back(nums);
		return output;
	}
	else if (nums.size() == 2) {
		vector<int>exnums;
		exnums.push_back(nums[1]);
		exnums.push_back(nums[0]);
		output.push_back(nums);
		output.push_back(exnums);
		return output;
	}
	else {
		vector<vector<int>> premutenum;
		vector<int>subnums;
		int i = 0;
		while (i < nums.size() - 1) {
			subnums.push_back(nums[i]);
			i++;
		}
		premutenum = solve(subnums);
		int p = 0;
		while (p<premutenum.size())
		{
			int q = 0;
			while (q < premutenum[p].size() + 1) {
				vector<int>add;
				for (int m = 0; m < q; m++) {
					add.push_back(premutenum[p][m]);
				}
				add.push_back(nums[nums.size() - 1]);
				for (int n = q; n < premutenum[p].size();n++) {
					add.push_back(premutenum[p][n]);
				}
				output.push_back(add);
				q++;
			}
			p++;
		}
	}
	return output;
}

int main()
{
	vector<int> nums = { 1,2,3,4 };
	vector<vector<int>>output;
	output = solve(nums);
	return 0;

}