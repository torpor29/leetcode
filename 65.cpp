#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isnum(string s) {
	vector<char> snew;
	int l = 0;
	while (l<s.length()) {
		snew.push_back(s[l]);
		l++;
	}
	if (snew.size() == 0) return false;
	while (snew[0] == ' ') {
		snew.erase(snew.begin());
		if (snew.size() == 0) return false;
	}
	while (snew[snew.size() - 1] == ' ') {
		snew.erase(snew.begin() + snew.size() - 1);
		if (snew.size() == 0) return false;
	}
	bool symflag = false;
	bool dotflag = false;
	bool eflag = false;
	vector<char> zhishu;
	if (snew.size() == 0) return false;
	if (snew[0] == '-' || snew[0] == '+') {
		symflag = true;
		snew.erase(snew.begin() + 0);
	}
	int i = 0;
	while (i<snew.size()) {
		if (snew[i] == 'e') {
			eflag = true;
			break;
		}

		else i++;

	}
	if (i != snew.size()) {
		snew.erase(snew.begin() + i);
		if (snew.size() == 0) return false;
		else {
			while (i<snew.size()) {
				zhishu.push_back(snew[i]);
				snew.erase(snew.begin() + i);
			}
		}
		
	}
	
	int p = 0;
	if (snew.size() == 0) return false;
	while (p<snew.size()) {
		if (snew[p] == '-' || snew[p] == '+') return false;
		else if (snew[p] == '.') {
			if (dotflag == false && snew.size()>1) dotflag = true;
			else return false;
		}
		else if (snew[p]>'9' || snew[p]<'0') return false;
		p++;
	}
	int q = 0;
	if (eflag == true&& zhishu.size() == 0) return false;
	else if (zhishu.size() == 0 && eflag == false) return true;

	if (zhishu[0] == '-' || zhishu[0] == '+') {
		zhishu.erase(zhishu.begin());
		if (zhishu.size() == 0) return false;
	}
	bool zhidotflag = false;
	while (q<zhishu.size()) {
		if (zhishu[q] == '-' || zhishu[q] == '+') {
			return false;
		}
		else if (zhishu[q] == '.') {
			return false;

		}
		else if (zhishu[q]>'9' || zhishu[q]<'0') return false;
		q++;

	}
	return true;
}

int main()
{
	string s = "4e+";
	bool result = isnum(s);
	return 0;
}