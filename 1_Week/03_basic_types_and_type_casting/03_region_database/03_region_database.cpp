
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>


using namespace std;

enum class Lang {
	DE, FR, IT
};

struct Region
{
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

bool operator <(Region lhr, Region rhr) {
	return tie(lhr.std_name, lhr.parent_std_name, lhr.names, lhr.population)
		< tie(rhr.std_name, rhr.parent_std_name, rhr.names, rhr.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	if (regions.size() == 0) {
		return 0;
	}
	map<Region, int> regions_count;
	int maxRepetion = 0;
	for (Region reg : regions) {
		regions_count[reg]++;
		maxRepetion = max(regions_count[reg], maxRepetion);
	}
	return maxRepetion;
}

int main()
{
	cout << FindMaxRepetitionCount({ { "Moscow",
		"Russia",
		{{Lang::DE, "Moscau"}, {Lang::FR, "Moscou"},{Lang::IT, "Moscuie"}},
		89
		}, {"Moscow",
		"Russia",
		{{Lang::DE, "Moscau"}, {Lang::FR, "Moscou"},{Lang::IT, "Moscuie"}},
		89
		}, {"Russia",
		"Eurasia",
		{{Lang::DE, "Moscau"}, {Lang::FR, "Moscou"},{Lang::IT, "Moscuie"}},
		89
		}, {"Moscow",
		"Russia",
		{{Lang::DE, "Moscau"}, {Lang::FR, "Moscou"},{Lang::IT, "Moscuie"}},
		89
		}, {"Russia",
		"Eurasia",
		{{Lang::DE, "Moscau"}, {Lang::FR, "Moscou"},{Lang::IT, "Moscuie"}},
		89
		} }) << endl;
}
