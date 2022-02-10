#include <string>
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;


int main() {
	deque<string> s;
	int start_, n;
	cin >> start_ >> n;
	s.push_back(to_string(start_));
	string op, val;
	bool isLowPrior = true;
	for (int i = 1; i <= n; i++) {
		cin >> op >> val;
		if (!isLowPrior && (op == "/" || op == "*")) {
			s.push_front("(");
			s.push_back(")");
			isLowPrior = true;
		}
		if (op == "-" || op == "+") isLowPrior = false;
		s.push_back(" " + op + " " + val);
	}
	stringstream ss;
	for (auto s_ : s) {
		ss << s_;
	}
	cout << ss.str() << endl;
	cout << true << endl;
}