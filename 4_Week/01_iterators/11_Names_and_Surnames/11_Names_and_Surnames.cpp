#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person
{
public:
	void ChangeFirstName(int year, const string& first_name) {
		this->first_name[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		this->second_name[year] = last_name;
	}

	string GetFullName(int year) {
		string name;
		name = first_name[year] + " " + second_name[year];
		return name;
	}
private:
	map<int, string> first_name;
	map<int, string> second_name;
};

int main()
{
	Person person;
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}
	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
			cout << person.GetFullName(year) << endl;
	}
	return 0;
}
