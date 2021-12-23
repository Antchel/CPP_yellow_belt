#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
ostream& operator << (ostream& stream ,const vector<T>& data) {
    for (const auto& x : data) {
        stream << x << " ";
    }
    return stream;
}

template <typename T>
vector<T> FingGreaterElements(const set<T>& elements, T to_find) {
    auto it = find(elements.begin(), elements.end(), to_find);
    if (it != elements.end()) {
        return vector<T>(++it, elements.end());
    }
    return {};
}

int main()
{
    for (int x : FingGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FingGreaterElements(set<string> {"C", "C++"}, to_find).size() << endl;
}
