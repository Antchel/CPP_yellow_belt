#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> words;
	auto it = begin(s);
	while (it != end(s)) {
		auto tmp = find(it, end(s), ' ');
		string word;
		if (tmp != end(s)) {
			while (it != tmp) {
				word += *it;
				it++;
			}
			words.push_back(word);
			it = ++tmp;
		}
		else
		{
			break;
		}
	}
	return words;
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