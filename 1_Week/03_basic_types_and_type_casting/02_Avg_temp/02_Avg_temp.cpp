#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	uint32_t dataSets;
	cin >> dataSets;
	int sum = 0;
	vector<int> tempr;
	for(int i = 0; i < dataSets; i++) {
		int tmp = 0;
		cin >> tmp;
		tempr.push_back(tmp);
	}
	int avgTmp = accumulate(tempr.begin(), tempr.end(), 0) / dataSets;
	cout << avgTmp << endl;
	int ltavg = 0;
	for (int i = 0; i < tempr.size(); i++) {
		if (tempr[i] > avgTmp)
			cout << i << " ";
	}
}