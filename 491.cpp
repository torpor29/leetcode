#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> strs = { "eat","","tea","","ate","" };
	vector<vector<string>> output;
	unordered_map<string, vector<string>> unorderedmap;
	int i = 0;
	while (i<strs.size())
	{
		string tmp = strs[i];

		sort(tmp.begin(), tmp.end());
		unorderedmap[tmp].push_back(strs[i]);
		i++;
	}
	for (auto iter = unorderedmap.begin(); iter != unorderedmap.end(); iter++) {
		output.push_back(iter->second);
	}
	return 0;
}