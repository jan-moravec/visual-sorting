#include <fmt/format.h>
#include <iostream>
#include <sorting/sorting.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **args)
{
    std::vector<int> data{ 10, 1, 5 };
    sorting::sort(data);
    fmt::print("{}", fmt::join(data, ", "));
}
