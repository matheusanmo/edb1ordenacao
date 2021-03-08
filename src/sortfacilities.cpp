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

#include <algorithm>
using std::reverse;

int exponent(int a, int b) {
    int accum = 1;
    for (int i = 0; i < b; i++) {
        accum *= a;
    }
    return accum;
}

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

void shell_sort(vector<uint> &vec, vector<uint> gaps_sequence) {
    // gaps_sequence deve ser decrescente
    if (gaps_sequence.size() == 0) {
        // A000225
        // sequencia na forma 2^k - 1 garante complexidade OMEGA(N^3/2)
        // https://dl.acm.org/doi/10.1145/366552.366557
        int k = 1;
        while ((uint)exponent(2, k) < vec.size()) {
            gaps_sequence.push_back((uint)exponent(2, k));
            k++;
        }
        reverse(gaps_sequence.begin(), gaps_sequence.end());
    }
    for (uint gap : gaps_sequence) {
        for (uint i = 0; i + gap < vec.size(); i++) {
            if (vec[i+gap] < vec[i]) {
                swap(vec[i+gap], vec[i]);
            }
        }
    }
    return;
}
