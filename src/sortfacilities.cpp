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

#include <algorithm> // std::reverse
#include <iterator>  // std::next

uint exponent(uint a, uint b) {
    uint accum = 1;
    for (uint i = 0; i < b; i++) {
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

/**
 * Usa insertion sort para h-ordenar o vetor
 */
void shell_sort(vector<uint> &vec, vector<uint> gaps_sequence) {
    // gaps_sequence deve ser decrescente
    if (gaps_sequence.size() == 0) {
        // sequencia da forma 2^k - 1 garante complexidade pior caso perto de N^5/4
        // https://dl.acm.org/doi/10.1145/366552.366557
        // knuth pag.95
        uint k = 1;
        while (exponent(2, k) - 1 < vec.size()) {
            gaps_sequence.push_back(exponent(2, k) - 1);
            k++;
        }
        std::reverse(gaps_sequence.begin(), gaps_sequence.end());
    }
    for (uint gap : gaps_sequence) {
        for (uint offset = 0; offset < gap; offset++) {
            // gap-sortear o array usando insertion sort
            for (uint i = gap + offset; i < vec.size(); i += gap) {
                for (uint j = i; j >= gap; j -= gap) {
                    if (vec[j] < vec[j-gap]) {
                        swap(vec[j], vec[j-gap]);
                    } else  {
                        break;
                    }
                }
            }
        }
    }
    return;
}

void merge(vector<uint> &vec, uint p, uint q, uint r) {
    // copiando vec[p..r] na memoria
    auto p_iterator = std::next(vec.begin(), p);
    auto q_iterator = std::next(vec.begin(), q);
    auto r_iterator = std::next(vec.begin(), r);
    vector<uint> vec_l (p_iterator, q_iterator);
    vector<uint> vec_r (q_iterator, r_iterator);

    auto li = vec_l.begin();
    auto ri = vec_r.begin();
    for (uint i = p; i < r; i++) {
        if (li == vec_l.end()) {
            while (ri != vec_r.end()) {
                vec[i] = *ri++;
                i++;
            }
            break;
        }
        if (ri == vec_r.end()) {
            while (li != vec_l.end()) {
                vec[i] = *li++;
                i++;
            }
            break;
        }
        if (*li <= *ri) {
            vec[i] = *li++;
        } else {
            vec[i] = *ri++;
        }
    }
    return;
}

void merge_sort_worker(vector<uint> &vec, uint p, uint r) {
    if (r - p < 2) { // caso base
        return;
    }
    uint q = (p + r) / 2;
    merge_sort_worker(vec, p, q);
    merge_sort_worker(vec, q, r);
    merge(vec, p, q, r);
    return;
}

// cormen adaptado sem sentineles
void merge_sort(vector<uint> &vec) {
    return merge_sort_worker(vec, 0, vec.size());
}

