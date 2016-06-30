#include <iostream>
#include <vector>
#include <stdlib.h>

int n;
std::vector<std::vector<size_t>> lists;

size_t find(std::vector<size_t> &list, size_t start, size_t end, size_t val)
{
    size_t i = start + (end - start) / 2;
    
    /*size_t diff = size_t(-1);
    size_t res = size_t(-1);
    for (auto v : list)
        if ((size_t)abs(val - v) < diff) {
            diff = abs(val - v);
            res = v;
        }
    return res;*/

    if (end - start == 0) {
        std::cout << "end-start=0 " << start << std::endl;
        i = (start == list.size()) ? start - 1 : start;
        return list[i];
    }
    if (end - start == 1) {
        std::cout << "end-start=1 " << start << std::endl;
        if (end == list.size())
            return list[start];
        auto d1 = abs(list[start] - val);
        auto d2 = abs(list[end] - val);
        return d1 < d2 ? list[start] : list[end];
    }

    if (list[i] < val)
        return find(list, i+1, end, val);
    else
        return find(list, start, i-1, val);
}

std::pair<size_t, size_t> findSmallestRange()
{
    std::vector<size_t> firstList = lists.back();
    size_t smallestRange = (size_t) -1;
    std::pair<size_t, size_t> range;
        
    lists.pop_back();
    for (auto v : firstList) {
        size_t min = v;
        size_t max = v;
        
        for (auto list : lists) {
            auto val = find(list, 0, list.size(), v);
            min = std::min(val, min);
            max = std::max(val, max);
        }
        if (max - min < smallestRange) {
            smallestRange = max - min;
            range = {min, max};
        }
    }
    return range;
}

int main(int argc, char *argv[])
{
    size_t n;
    std::cin >> n;
    
    for (size_t i = 0; i < n; i++) {
        size_t numElements;
        std::vector<size_t> list;
    
        std::cin >> numElements;
        for (size_t j = 0; j < numElements; j++) {
            size_t v;
            
            std::cin >> v;
            list.push_back(v);
        }
        lists.push_back(list);
    }
    
    auto range = findSmallestRange();
    std::cout << range.first << " " << range.second << std::endl;
    return 0;
}
