////////////////////////////////////////////////////////////////////////////////
//  File:   quicksort.h
//
//  © Zach Nielsen 2020
//  Templatized implementation of quicksort
//
#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

////////////////////////////////////////////////////////////////////////////////
//  INCLUDES
////////////////////////////////////////////////////////////////////////////////
// Switch to my vector when implemented
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
size_t quicksort_sorter(std::vector<T> &vec, size_t lo, const size_t hi)
{
	for (auto idx=lo; idx<hi; idx++) {
		if (vec.at(idx) < vec.at(hi)) {
			// Move this value towards the front
			const auto tmp = vec.at(lo);
			vec[lo] = vec.at(idx);
			vec[idx] = tmp;
			lo += 1;
		}
	}

	// Move our pivot val to the top of the "below" range
	const auto tmp = vec.at(lo);
	vec[lo] = vec.at(hi);
	vec[hi] = tmp;

	return lo;
}

template <typename T>
void quicksort_helper(std::vector<T> &vec, const size_t lo, const size_t hi)
{
	if (lo < hi) {
		const auto mid = quicksort_sorter(vec, lo, hi);
		// Med is now in the index where it should be, leave it alone
        if (mid > 0) { quicksort_helper(vec, lo, mid-1); }
        if (mid < vec.size()) { quicksort_helper(vec, mid+1, hi);}
	}
}

template <typename T>
void quicksort(std::vector<T> &vec)
{
	return quicksort_helper(vec, 0, vec.size()-1);
}

#endif // _QUICKSORT_H_ //
