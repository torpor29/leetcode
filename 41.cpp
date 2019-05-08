#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int ini[3] = {1,3,3 };
	vector<int> nums(ini, ini + 3);
	int min = nums[0];
	int max = nums[0];
	int result=0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < min) min = nums[i];
		else if (nums[i] > max) max = nums[i];
	}
	if (max < 0||min>1||max==0) result=1;
	else {
		vector<int>record(max);
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i]>0&&nums[i]!=max)
			record[nums[i]] = 1;
		

		}
		int i = 1;
		while (i<record.size() )
		{
			if (record[i] == 0) {
					result = i;
					break;
			}
			i++;
		}
		if (result == 0) result = max + 1;
	}
	
	return 0;
}