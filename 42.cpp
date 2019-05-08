#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int ini[12] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int>height(ini, ini + 12);
	if (height.size()<2) return 0;
	int head, tail;
	int leftwall = height[0];
	int rightwall = height[height.size()-1];

	head = 0;
	tail = height.size()-1;
	int result=0;
	while (head != tail) {
		if (leftwall < rightwall) {
			if (height[head] < leftwall) {
				result = result + leftwall - height[head];
				head++;
			}
			else if (height[head] == leftwall) {
				head++;
			}
			else {
				leftwall = height[head];
			}
		}
		else {
			if (height[tail] < rightwall) {
				result = result + rightwall - height[tail];
				tail--;
			}
			else if (height[tail] == rightwall) {
				tail--;
			}
			else {
				rightwall = height[tail];
			}
		}
	}
	return 0;
}