#include<iostream>
#include<vector>
using namespace std;

bool solve( vector<int>nums)
{
	bool flag = false;
	int n = nums.size();
	if (n < 2) return true;
	else if (n == 2) {
		if (nums[0] > 0) return true;
		else return false;
	}
	else {
		if (nums[0] == 0) return false;
		int m = nums[0];
		int i = 1;
		vector<int>tmp;
		for (int j = i; j < n; j++) {
			tmp.push_back(nums[j]);
		}
		flag = solve(tmp);
		i++;
		while (flag==false&&i < m + 1) {
			vector<int>tmp;
			for (int j = i; j < n; j++) {
				tmp.push_back(nums[j]);
			}
			flag = solve(tmp);
			if (flag == true) break;
			else i++;
		
		}
		
		return flag;
	}
}

int main()
{
	vector<int> nums = { 8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5 };
	bool result=true;
	int i = 0;
	int bef;
	vector<int>tmp;
	//tmp.push_back(nums[0]);
	vector<vector<int>>baktmp;
	while (i<nums.size())
	{
		if (nums[i] == 0) {
			if (i + 1 == nums.size()) {
				result = true;
				break;
			}
			while (i<nums.size()-1)
			{
				if (nums[i] == 0) {
					tmp.push_back(nums[i]);
					i++;
				}
				else break;
				
			}
			tmp.push_back(nums[i]);
			result = solve(tmp);
			if (result == false) {
				vector<vector<int>>baktmptmp=baktmp;
				vector<int>tmp1 = tmp;
				while (baktmptmp.size()>0)
				{
					vector<int>c=baktmptmp[baktmptmp.size()-1];
					baktmptmp.pop_back();
					vector<int>rec;
					for (int i = 0; i < c.size()-1; i++) {
						rec.push_back(c[i]);
					}
					for (int i = 0; i < tmp.size(); i++) {
						rec.push_back(tmp[i]);
					}
					tmp = rec;
					result = solve(tmp);
					if (result == true) break;

				}
				if (result == true) {
					baktmp.push_back(tmp1); 
					tmp.clear();
				}
				else {
					break;
				}
			}
			else {
				baktmp.push_back(tmp);
				//bef = i;
				tmp.clear();

			}
		}
		else {
			tmp.push_back(nums[i]);
			
			i++;
		}
	}
	//result = solve(nums);
	return 0;
}