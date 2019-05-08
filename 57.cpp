#include<iostream>
#include<vector>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

};

int main()
{
	vector<Interval>intervals;
	Interval ini1(4, 5);
	Interval ini2(2, 4);
	Interval ini3(4, 6);
	Interval ini4(3, 4);
	Interval ini5(0, 0);
	Interval ini6(1, 1);
	Interval ini7(3, 5);
	Interval ini8(2, 2);
	intervals.push_back(ini1);
	intervals.push_back(ini2);
	intervals.push_back(ini3);
	intervals.push_back(ini4);
	intervals.push_back(ini5);
	intervals.push_back(ini6);
	intervals.push_back(ini7);
	intervals.push_back(ini8);

	Interval newInterval(2, 5);
	intervals.push_back(newInterval);
	vector<int> output;
	vector<Interval>result;
	if (intervals.size()<2) return 0;
	else {
		output.push_back(intervals[0].start);
		output.push_back(intervals[0].end);
		int i = 1;
		while (i<intervals.size()) {
			Interval tmp = intervals[i];
			int j = 0;
			int locstart = output.size();
			int locend = output.size();
			if (!(output[0] < tmp.start)) locstart = 0;
			if (output[0] > tmp.end) locend = 0;
			while (j<output.size() - 1) {
				if (output[j]<tmp.start && ((output[j + 1] == tmp.start) || (output[j + 1]>tmp.start))) {
					locstart = j + 1;
				}
				if (output[j + 1]>tmp.end && ((output[j] == tmp.end) || (output[j]<tmp.end))) {
					locend = j + 1;
				}
				if (locstart != output.size() && locend != output.size()) {
					break;
				}
				j++;
			}
			if (locstart % 2 == 1 && locend % 2 == 1) {
				if (locstart != locend) {
					output.erase(output.begin() + locstart, output.begin() + locend);
				}

			}
			else if (locstart % 2 == 1 && locend % 2 == 0) {
				output.insert(output.begin() + locend, tmp.end);
				output.erase(output.begin() + locstart, output.begin() + locend);
			}
			else if (locstart % 2 == 0 && locend % 2 == 1) {
				output.insert(output.begin() + locstart, tmp.start);
				output.erase(output.begin() + locstart + 1, output.begin() + locend + 1);
			}
			else {
				output.insert(output.begin() + locstart, tmp.start);
				output.insert(output.begin() + locend + 1, tmp.end);
				if (locend != locstart) {
					output.erase(output.begin() + locstart + 1, output.begin() + locend + 1);
				}

			}
			i++;
		}
	}
	int i = 0;
	while (i<output.size() - 1) {
		Interval ins(output[i], output[i + 1]);
		result.push_back(ins);
		i += 2;
	}
	return 0;

}