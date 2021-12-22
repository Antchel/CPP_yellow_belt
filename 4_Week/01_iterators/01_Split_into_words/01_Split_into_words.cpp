#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> result;
	auto begin_it = begin(s);
	for (auto it = find(begin(s), end(s), ' ');
		it != end(s);
		it = find(next(it), end(s), ' ')) {
		if (*it != 0) {
			result.push_back(string(begin_it, it));
			begin_it = ++it;
		}
	}
	result.push_back(string(begin_it, end(s)));

	return result;
}

int main()
{
	string s = "C C++ Java Python C#";
	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " " << endl;

	for (vector<string>::iterator it = begin(words); it != end(words); it++) {
		if (it != begin(words))
			cout << "/";
		cout << *it;
	}
	cout << endl;
	return 0;
}