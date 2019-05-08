#include<ostream>
#include<vector>
using namespace std;

int main()
{
	int ini[4] = { 1,3,5,6 };
	vector<int>nums(ini, ini + 4);
	int target = 0;
	int result;
	int n = nums.size();
	int i = 0;
	while (i<n)
	{
		if (nums[i] < target) {
			i++;
		}
		else {
			result = i;
			break;
		}
	}
	if (i == n) result = n;
	return 0;

}