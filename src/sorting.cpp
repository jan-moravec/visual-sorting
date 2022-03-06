#include <sorting/sorting.h>

#include <algorithm>


void sorting::SelectionSort(std::vector<int> &data)
{
    constexpr size_t MINIMAL_SORTABLE_SIZE = 2;
    if (data.size() < MINIMAL_SORTABLE_SIZE) {
        return;
    }

    for (size_t i = 0; i < data.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < data.size(); ++j) {
            if (data[minIndex] > data[j]) {
                minIndex = j;
            }
        }
        std::swap(data[i], data[minIndex]);
    }
}

void sorting::InsertSort(std::vector<int> &data)
{
    std::sort(data.begin(), data.end());
}

void sorting::BubbleSort(std::vector<int> &data)
{
    std::sort(data.begin(), data.end());
}
