#include<iostream>
#include<vector>
using namespace std;
bool comb(vector<int>& tmp, vector<vector<int>>& result, vector<int>&candidates, int target)
{
	vector<int>copytmp = tmp;
	vector<int>copycan = candidates;
	int copytarget = target;
	bool comp = true;
	if (target == 0) {
		return true;
	}
	else if (candidates.size() == 0) return false;
	else if (candidates[0] > target) return false;
	else {
		int n = target / candidates[0];
		int i = 0;
		candidates.erase(candidates.begin());
		while (!(i>n)) {
			if (i != 0) {
				copytmp.push_back(copycan[0]);
				copytarget -= copycan[0];
				
			}
			tmp = copytmp;
			target = copytarget;
			candidates = copycan;
			candidates.erase(candidates.begin());
			comp = comb(tmp, result, candidates, target);
			if (comp == true&&target==0) {
				result.push_back(tmp);
			}
			i++;
		}
		return true;
	}
	
}
//vector<vector<int>> combination(vector<int>& candidates, int target)
//{
//	vector<vector<int>>result;
//	vector<int>tmp;
//	
//
//}

int main()
{
	vector<int> candidates = { 8,7,4,3 };
	int target = 11;
	vector<vector<int>>result;
	vector<int>tmp;
	bool comp = comb(tmp, result, candidates, target);
	//result=combination(candidates, target);
	return 0;
}