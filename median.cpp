#include <algorithm> // sort
#include <stdexcept>
#include <vector>

#include "median.h"

double median (std::vector<double> vec){
    typedef std::vector<double>::size_type vec_sz;

    vec_sz size = vec.size();

    if (size == 0)
        throw std::domain_error("Cannot take the median of an empty list");

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];

}

