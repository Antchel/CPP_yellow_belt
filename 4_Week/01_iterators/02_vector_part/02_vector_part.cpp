#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto it = find_if(numbers.begin(), numbers.end(), [](const int& a) { return a < 0; });
	if (it != numbers.begin())it--;
	else return;
	
	for (; it != numbers.begin(); it--) {
		cout << *it << " ";
	}
	cout << *it << endl;
}

int main()
{
	vector<int> vec{6,1,8,5,4};
	PrintVectorPart(vec);
	vector<int> vec1{ -6,1,8,5,4 };
	PrintVectorPart(vec1);
	vector<int> vec2{ 6,1,8,-5,4 };
	PrintVectorPart(vec2);
}