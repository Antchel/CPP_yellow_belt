#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt begin_it, RandomIt end_it) {
	if (end_it - begin_it < 2) return;
	vector<typename RandomIt::value_type> elements(begin_it, end_it);
	auto mid = elements.begin() + (elements.end() - elements.begin()) / 2;
	MergeSort(elements.begin(), mid);
	MergeSort(mid, elements.end());
	std::merge(elements.begin(), mid, mid, elements.end(), begin_it);
}

int main()
{
	vector<int> v = { 6,4,7,6,4,4,0,1 };
	MergeSort(v.begin(), v.end());
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}