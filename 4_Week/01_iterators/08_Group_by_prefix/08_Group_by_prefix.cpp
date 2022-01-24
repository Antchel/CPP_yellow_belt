#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, string substr)
{
    auto itr = std::equal_range(range_begin, range_end, substr,
        [&substr](const std::string& x, const std::string& y)
        {
            return x.substr(0, substr.length()-1) < y.substr(0, substr.length() - 1);
        });
    return std::make_pair(itr.first, itr.second);
}

int main()
{
    const std::vector<std::string> sorted_strings = { "moscow", "murmansk", "vologda", "voronezh" };

    const auto m_result = FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), "vo");

    for (auto it = m_result.first; it != m_result.second; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const auto p_result = FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), "mu");
    std::cout << (p_result.first - std::begin(sorted_strings)) << " "
        << (p_result.second - std::begin(sorted_strings)) << std::endl;

    const auto z_result = FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), "xu");
    std::cout << (z_result.first - std::begin(sorted_strings)) << " "
        << (z_result.second - begin(sorted_strings)) << std::endl;

    return 0;
}