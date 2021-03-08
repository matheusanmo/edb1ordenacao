#include "vecfacilities.h"
#include "uint.h"

#include <algorithm> // std::sort, std::shuffle
#include <random> // std::default_random_engine, std::uniform_int_distribution
#include <chrono> // std::chrono::system_clock

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
void swap(T &a, T &b) {
    auto tmp = a;
    a = b;
    b = tmp;
    return;
}

/**
 * Gera `unsigned int` a partir do horario atual. Útil para servir de __seed__ para 
 * geradores pseudo-aleatorios do `<random>`.
 */
uint gen_seed() {
    return std::chrono::system_clock::now().time_since_epoch().count();
}

/**
 * Retorna `false` quando um dos elementos de `vec` é estritamente menor que o anterior.
 */
template <typename T>
bool is_increasing(vector<T> const &vec) {
    if (vec.size() == 0) {
        return true;
    }
    auto x0 = vec[0];
    for (auto const &x : vec) {
        if (x < x0) {
            return false;
        }
    }
    return true;
}

/**
 * Retorna `false` quando um dos elementos de `vec` é estritamente maior que o anterior.
 */
template <typename T>
bool is_decreasing(vector<T> const &vec) {
    if (vec.size() == 0) {
        return true;
    }
    auto x0 = vec[0];
    for (auto const &x : vec) {
        if (x0 < x) {
            return false;
        }
    }
    return true;
}

/**
 * Cria `vector` contendo `n` `uints` gerados aleatoriamente seguindo uma distribuição
 * uniforme.
 */
vector<uint> gen_random_uniform(const int n) {
    if (n == 0) {
        return vector<uint>();
    }
    vector<uint> new_vec (n);

    std::default_random_engine generator (gen_seed());
    std::uniform_int_distribution<uint> distribution;

    for (int i = 0; i < n; i++) {
        new_vec[i] = distribution(generator);
    }
    return new_vec;
}

/**
 * Cria `vector` garantidamente não crescente. 
 */
vector<uint> gen_random_non_increasing(const int n) {
    vector<uint> new_vec = gen_random_uniform(n);
    if (is_increasing(new_vec)) {
        return gen_random_non_increasing(n);
    } else {
        return new_vec;
    }
}

/**
 * Cria `vector` garantidamente não decrescente.
 */
vector<uint> gen_random_non_decreasing(const int n) {
    vector<uint> new_vec = gen_random_uniform(n);
    if (is_decreasing(new_vec)) {
        return gen_random_non_decreasing(n);
    } else {
        return new_vec;
    }

}

/**
 * Cria `vector` de `n` elementos, dos quais `p*100`% já estão na casa em que estariam caso
 * o vetor estivesse ordenado.
 *
 * @param   p   real pertencente a `[0,1]` indicando qual proporção do vetor deve estar ordenado
 */
vector<uint> gen_random_preordered(const int n, double p) {
    if (n == 0) {
        return vector<uint>();
    }
    vector<uint> new_vec = gen_random_uniform(n);
    std::sort(new_vec.begin(), new_vec.end());

    vector<int> index_vec (n);
    for (int i = 0; i < n; i++) {
        index_vec[i] = i;
    }
    std::default_random_engine generator (gen_seed());
    shuffle (index_vec.begin(), index_vec.end(), generator);

    int swap_count = ceil(((1.0 - p) * n) / 2);
    for (int i = 0; i <= swap_count; i += 2) {
        swap(new_vec[index_vec[i]], new_vec[index_vec[i+1]]);
    }
    return new_vec;
}

/**
 * Facilidade para printar vetores.
 */
template <typename T>
void print_vector(vector<T> const &vec) {
    for (auto const &x : vec) {
        cout << x << endl;
    }
    cout << vec.size() << " elementos" << endl;
    return;
}

