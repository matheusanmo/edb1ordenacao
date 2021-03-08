#ifndef SORTFACILITIES_H
#define SORTFACILITIES_H

#include <vector>
using std::vector;


template <typename T>
int time_sort(void (*sort_fun)(vector<T>&), vector<T> &vec);

template <typename T>
void selection_sort(vector<T> &vec);

#endif

