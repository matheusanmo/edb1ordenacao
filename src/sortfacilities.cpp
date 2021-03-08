#include "sortfacilities.h"

#include <utility>
using std::swap;

#include <vector>
using std::vector;

#include <chrono>
using std::chrono::milliseconds;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;

template <typename T>
int time_sort(void (*sort_fun)(vector<T>&), vector<T> &vec) {
    auto t0 = high_resolution_clock::now();
    sort_fun(vec);
    auto t1 = high_resolution_clock::now();
    return duration_cast<milliseconds>(t1 - t0).count();
}

template <typename T>
void selection_sort(vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        auto elem_min  = vec[i];
        int  index_min = i;
        for (int j = i; j < vec.size(); j++) {
            if (vec[j] < elem_min) {
                elem_min  = vec[j];
                index_min = j;
            }
        }
        swap(vec[i], vec[index_min]);
    }
    return;
}

