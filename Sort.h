#pragma once
#include "Library.h"

template<typename T>
struct compare {
    bool operator()(const T& a, const T& b) {
        return (a > b);
    }
};

template<typename T, typename compare>
void sort(Vector <T>& arr, compare cmp) {
    for (int i = 0; i < arr.size(); i++) {
        int cur = i;
        while (cur > 0 && cmp(arr[cur - 1], arr[cur])) {
            arr.swap(cur - 1,cur);
            cur--;
        }
    }
}

