#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int N, k;
	cin >> N;
	cin >> k;

	vector<vector<int>>nums;
	for (int i = 0; i<N; i++) {
		vector<int>tmp;
		for (int j = 0; j<k; j++) {
			int p;
			cin >> p;
			tmp.push_back(p);
		}
		nums.push_back(tmp);
	}

	if (N<2) {
		cout << "[";
		for (int i = 0; i<N; i++) {
			cout << "[";
			for (int j = 0; j<k; j++) {
				if (j != k - 1) {
					cout << nums[i][j] << "," << " ";
				}
				else cout << nums[i][j];
			}
			if (i != N - 1) cout << "]" << "," << " ";
			else cout << "]";
		}
		cout << "]";
	}
	else if (k<2) {
		cout << "[";
		for (int i = 0; i<N; i++) {
			cout << "[";
			for (int j = 0; j<k; j++) {
				if (j != k - 1) {
					cout << nums[i][j] << "," << " ";
				}
				else cout << nums[i][j];
			}
			if (i != N - 1) cout << "]" << "," << " ";
			else cout << "]";
		}
		cout << "]";
	}
	vector<int> order;
	for (int i = 0; i<N; i++) {
		int count = 0;
		for (int j = 0; j<k - 1; j++) {
			if (nums[i][j]>nums[i][j + 1]) count++;
		}
		order.push_back(count);
	}
	multimap<int, int> indexmap;
	for (int i = 0; i<N; i++) {
		indexmap.insert(pair<int, int>(order[i], i));
	}
	sort(order.begin(), order.end());
	for (int i = 0; i<N; i++) {
		cout << "[";
		int ncou = indexmap.count(order[i]);
		auto iter = indexmap.find(order[i]);
		for (int l = 0; l<ncou; l++, iter++) {
			cout << "[";
			for (int j = 0; j<k; j++) {
				if (j != k - 1) cout << nums[(*iter).second][j] << "," << " ";
				else cout << nums[(*iter).second][j];
			}
			cout << "]";

		}
		if (i != N - 1) {
			cout << "," << " ";
		}
		else cout << "]";
	}

	/*for(int i=0;i<nums.size();i++){
	for (int j=0;j<nums[0].size();j++){
	cout<<nums[i][j];
	}
	cout<<endl;
	}*/
	return 0;
}