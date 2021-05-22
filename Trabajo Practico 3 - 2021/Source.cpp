#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
    std::vector<std::string> v = { "a", "ab", "abc" };
    std::vector<std::size_t> l;
    transform(v.begin(), v.end(), std::back_inserter(l),
        std::mem_fn(&std::string::size));
    for (std::size_t n : l)
        std::cout << n << ' ';
}