
#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

template <typename T>
T Sqr(T val) {
    return val * val;
}

template <typename F, typename S>
pair<F, S> Sqr(pair<F, S> p) {
    return make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename F, typename S>
map<F, S> Sqr(map<F,S>& m) {
    for (const auto& x : m) {
        m[x.first] = Sqr(x.second);
    }
    return m;
}

template <typename T>
vector<T> Sqr(vector<T>& v) {
    for (auto& x : v) {
        x = Sqr(x);
    }
    return v;
}

int main()
{
    vector<int> v = { 1,2,3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 3}},
        {7, {4,3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs))
    {
        cout << x.first << ' ' << x.second.first <<
            ' ' << x.second.second << endl;
    }
}