#include <catch2/catch.hpp>

#include <sorting/sorting.h>

TEST_CASE("Simple test", "[single-file]")
{
    std::vector<int> data{ 10, 1, 5 };
    sorting::sort(data);
    REQUIRE(data == std::vector<int>{ 1, 5, 10 });
}
