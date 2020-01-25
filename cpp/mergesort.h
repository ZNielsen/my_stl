////////////////////////////////////////////////////////////////////////////////
//  File:   mergesort.h
//
//  © Zach Nielsen 2020
//  Templatized implementation of merge sort
//
#ifndef _MERGESORT_H_
#define _MERGESORT_H_

////////////////////////////////////////////////////////////////////////////////
//  INCLUDES
////////////////////////////////////////////////////////////////////////////////
// Replace with my vector and queue when implemented
#include <queue>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
//  DEFINITIONS
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  PROTOTYPES
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  CODE
////////////////////////////////////////////////////////////////////////////////

template <typename T>
std::queue<T> mergesort_helper(const std::vector<T> &v, const size_t left, const size_t right) {
    std::queue<T> ret {};
    if (left >= right) {
        ret.push(v.at(left));
        return ret;
    }
    const size_t mid = (right+left)/2;
    auto low  = mergesort_helper<T>(v, left, mid);
    auto high = mergesort_helper<T>(v, mid+1, right);
    while (!low.empty() && !high.empty()) {
        if (low.front() <= high.front()) {
            ret.push(low.front());
            low.pop();
        }
        else {
            ret.push(high.front());
            high.pop();
        }
    }

    // Clean up if one is empty
    while (!low.empty()) {
    	ret.push(low.front());
    	low.pop();
    }
    while (!high.empty()) {
    	ret.push(high.front());
    	high.pop();
    }
    return ret;
}

template <typename T>
std::vector<T> mergesort(const std::vector<T> &vec) {
	std::queue<T> s {mergesort_helper<T>(vec, 0, vec.size()-1ul)};
	std::vector<T> ret{};
	while (!s.empty()) {
		ret.push_back(s.front());
		s.pop();
	}
	return ret;
}

#endif // _MERGESORT_H_ //
