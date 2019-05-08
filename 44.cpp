#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
bool solve(string s, string p)
{
	cout << s << endl << p << endl << endl;
	int i = 0;
	bool tmp;
	string record;
	while (i<p.size()&&i<s.size())
	{
		if (p[i] == '?') {
			i++;
		}
		else if (p[i] == '*') break;
		else {
			if (p[i] == s[i]) i++;
			else return false;
		}
	}
	if (i == p.size() && i == s.size()) return true;
	else if (i == p.size() && i != s.size())return false;
	else if (i != p.size() && i == s.size()) {
		int tmpi = i;
		while (tmpi < p.size()) {
			if (p[tmpi] != '*')return false;
			else tmpi++;
		}
		return true;
	}
	else {
		int tmpi = i;
		int tmpj = i;
		while (tmpi < p.size()) {
			if (p[tmpi] == '*')tmpi++;
			else break;
		}
		if (tmpi == p.size()) return true;
		else {
			
			tmp = solve(s.substr(tmpj, s.size() - tmpj), p.substr(tmpi, p.size() - tmpi));
			if (tmp == false) {
				tmpj++;
				while (tmp==false&&tmpj<s.size())
				{
					tmp= solve(s.substr(tmpj, s.size() - tmpj), p.substr(tmpi, p.size() - tmpi));
					tmpj++;

				}
				if (tmp == false)return false;
				else return true;
			}
			else return true;
		}
	}
}

int main()
{
	string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
	string p = "**aa*****ba*a*bb**aa";
	bool result;
	result = solve(s, p);
	return 0;
}