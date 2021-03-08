#ifndef SORTFACILITIES_H
#define SORTFACILITIES_H

#include "uint.h"

#include <vector>
using std::vector;


double time_sorts_mean(
        void         (*sort_fun)(vector<uint>&),
        vector<uint> (*vec_gen)(int),
        int          vec_size,
        int          run_count);
void selection_sort(vector<uint> &vec);

#endif

