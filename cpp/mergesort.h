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
std::vector<T> mergesort(const std::vector<T> vec) {
	const auto s = mergesort_helper(vec, 0, vec.size()-1);
	std::vector<T> ret{};
	while (!s.empty()) {
		ret.push_back(s.top());
		s.pop();
	}
	return ret;
}

template <typename T>
std::queue<T> mergesort_helper(std::vector<T> &v, const uint left, const uint right) {
    if (left == right) {
        return v.at(right);
    }
    auto low  = mergesort_helper(v, left, (right-left)/2);
    auto high = mergesort_helper(v, ((right-left)/2)+1, right);
    auto ret = std::queue<T>{};
    while (!low.empty() && !high.empty()) {
        if (low.top() <= high.top()) {
            ret.push(low.top());
            low.pop();
        }
        else {
            ret.push(high.top());
            high.pop();
        }
    }

    // Clean up if one is empty
    while (!low.empty()) {
    	ret.push(low.top());
    	low.pop();
    }
    while (!high.empty()) {
    	ret.push(high.top());
    	high.pop();
    }
    return ret;
}

#endif // _MERGESORT_H_ //
