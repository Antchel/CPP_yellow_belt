#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template< typename T>
void RemoveDuplicates(vector<T>& elements) {
	sort(elements.begin(), elements.end());
	auto it = unique(elements.begin(), elements.end());
	elements.erase(it, elements.end());
}

int main()
{
	vector<int> v1 = { 6,4,7,6,4,4,0,1 };
	RemoveDuplicates(v1);
	for (int& x : v1) {
		cout << x << " ";
	}
	cout << endl;
	vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
	RemoveDuplicates(v2);
	for (const string& s : v2) {
		cout << s << " ";
	}
	cout << endl;

}
