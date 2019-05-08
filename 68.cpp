#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<string>words = { "This","is","an","example","of","text","justification." };
	int maxWidth = 16;
	vector<string> result;
	vector<string>tmp;
	int i = 0;
	int count = 0;
	string strtmp;
	while (i<words.size())
	{
		
		strtmp = words[i];
		count += strtmp.length();
		if ((count+strtmp.size()-1) > maxWidth) {
			int slots = maxWidth - count+strtmp.length();
			int numoftmp = tmp.size()-1;
			if (numoftmp == 0) {
				result.push_back(tmp[0]);
				count = strtmp.length();
				tmp.clear();
				tmp.push_back(strtmp);
			}
			else {
				int slot1 = slots / numoftmp;
				int slot2 = slots%numoftmp;
				string strins = "";
				for (int i = 0; i < tmp.size(); i++) {
					strins = strins + tmp[i];
					if (i < tmp.size() - 1) {
						if (i < slot2) {
							for (int j = 0; j < slot1 + 1; j++) {
								strins = strins + " ";
							}
						}
						else {
							for (int j = 0; j < slot1; j++) {
								strins = strins + " ";
							}
						}
					}
				}
				result.push_back(strins);
				count = strtmp.length();
				tmp.clear();
				tmp.push_back(strtmp);
			}
			
		}
		else {
			tmp.push_back(strtmp);
		}
		i++;
	}
	if (tmp.size() > 1) {
		int slots = maxWidth - count;
		int numoftmp = tmp.size() - 1;
		int slot1 = slots / numoftmp;
		int slot2 = slots%numoftmp;
		string strins = "";
		for (int i = 0; i < tmp.size(); i++) {
			strins = strins + tmp[i];
			if (i < tmp.size() - 1) {
				if (i < slot2) {
					for (int j = 0; j < slot1 + 1; j++) {
						strins = strins + " ";
					}
				}
				else {
					for (int j = 0; j < slot1; j++) {
						strins = strins + " ";
					}
				}
			}
		}
		result.push_back(strins);
		count = strtmp.length();
		tmp.clear();
	}
	else {
		result.push_back(tmp[0]);
	}
	return 0;

}