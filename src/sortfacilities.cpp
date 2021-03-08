#include "sortfacilities.h"
#include "vecfacilities.h"
#include "uint.h"

#include <utility>
using std::swap;

#include <vector>
using std::vector;

#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration;

double time_sort(void (*sort_fun)(vector<uint>&), vector<uint> &vec) {
    auto t0 = high_resolution_clock::now();
    sort_fun(vec);
    auto t1 = high_resolution_clock::now();
    duration<double, std::milli> dt = t1 - t0;
    return dt.count();
}

double time_sorts_mean(
        void         (*sort_fun)(vector<uint>&),
        vector<uint> (*vec_gen)(int),
        int          vec_size,
        int          run_count) {
    double mean = 0;
    for (int i = 1; i <= run_count; i++) {
        vector<uint> vec = vec_gen(vec_size);
        double dt = time_sort(sort_fun, vec);
        mean += (dt - mean) / i;
    }
    return mean;
}

void selection_sort(vector<uint> &vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        auto    elem_min  = vec[i];
        size_t  index_min = i;
        for (size_t j = i; j < vec.size(); j++) {
            if (vec[j] < elem_min) {
                elem_min  = vec[j];
                index_min = j;
            }
        }
        swap(vec[i], vec[index_min]);
    }
    return;
}

void insertion_sort(vector<uint> &vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (vec[j] < vec[j-1]) {
                swap(vec[j], vec[j-1]);
            } else {
                break;
            }
        }
    }
    return;
}

void bubble_sort(vector<uint> &vec) {
    for (int i = vec.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
            }
        }
    }
    return;
}
