#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> strs = { "eat","","tea","","ate","" };
	vector<vector<string>> output;
	while (strs.size() != 0)
	{
		string tmp = strs[0];
		vector<string>add;
		add.push_back(tmp);
		strs.erase(strs.begin());
		int i = 0;
		if (tmp == "") {
			while (i < strs.size()) {
				if (strs[i] == "") {
					add.push_back("");
					strs.erase(strs.begin() + i);
				}
				else i++;
			}
			output.push_back(add);
		}
		else {
			while (i < strs.size())
			{
				vector<char>com;
				for (int j = 0; j < strs[i].size(); j++) {
					com.push_back(strs[i][j]);
				}
				if (com.size()!=tmp.length())
				{
					i++;
				}
				else {
					int k = 0;
					while (k < tmp.size())
					{
						vector<char>::iterator iter;
						iter = find(com.begin(), com.end(), tmp[k]);
						if (iter == com.end()) {
							break;
						}
						else {
							com.erase(iter);
							k++;
						}
					}
					if (com.size() == 0) {
						add.push_back(strs[i]);
						strs.erase(strs.begin() + i);
					}
					else i++;
				}
				
			}
			output.push_back(add);
		}
		
	}
	return 0;
}