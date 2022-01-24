
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	if (numbers.empty()) return numbers.end();
	if (numbers.find(border) != numbers.end()) return numbers.find(border);
	set<int>::const_iterator prev_it = numbers.end();
	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		if (border == *it) return it;
		else if (border < *it) {
			if (prev_it != numbers.end()) {
				if (border - *prev_it < *it - border) return prev_it;
				else return it;
			}
		}
		prev_it = it;
	}
	return prev(numbers.end());
}

int main()
{
	set<int> numbers = { 1,4,6 };
	cout << *FindNearestElement(numbers, 0) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 4) << " " <<
		*FindNearestElement(numbers, 5) << " " <<
		*FindNearestElement(numbers, 100) << endl;
	set<int> empty_set;
	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
}