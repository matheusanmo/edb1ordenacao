#ifndef VECFACILITIES_H
#define VECFACILITIES_H

#include "uint.h"

#include <vector>
using std::vector;

vector<uint> gen_random_uniform        (const int n);
vector<uint> gen_random_non_increasing (const int n);
vector<uint> gen_random_non_decreasing (const int n);
vector<uint> gen_random_preordered     (const int n, double p);
template <typename T>
void         print_vector              (vector<T> const &vec);

#endif
