#include <catch2/catch.hpp>

#include <algorithm>
#include <sorting/sorting.h>

TEST_CASE("Simple test", "[single-file]")
{
    const std::vector<int> DATA{ 10, 1, 5 };

    std::vector<int> expected = DATA;
    std::vector<int> tested = DATA;

    std::sort(expected.begin(), expected.end());
    sorting::SelectionSort(tested);

    REQUIRE(expected == tested);
}
