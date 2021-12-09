#include <iostream>
#include <exception>
#include <utility>
#include <map>

using namespace std;

template <typename First, typename Second>
Second& GetRefStrict( map<First, Second>& m, First key) {
	if (m.count(key) == 0) {
		throw runtime_error("There is no element by this key");
	}
	Second& val = m.at(key);
	return val;
}

int main()
{
	try {
		map<int, string> m = { {0, "zero string"} };
		string& item = GetRefStrict(m, 0);
		item = "new_value";
		cout << m[0] << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	
}
