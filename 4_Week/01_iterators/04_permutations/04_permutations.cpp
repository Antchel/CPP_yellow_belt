#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

template<class T>
void PrintVector(const vector<T>& dst) {
	for (const T& el : dst) {
		cout << el << " ";
	}
	cout << endl;
}

int main()
{
	int digit;
	cin >> digit;
	vector<int> v(digit);
	iota(v.rbegin(), v.rend(), 1);
	do {
		PrintVector(v);
	} while (prev_permutation(begin(v), end(v)));
}
