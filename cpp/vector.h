////////////////////////////////////////////////////////////////////////////////
//  File:   Vector.h
//
//  © Zach Nielsen 2020
//  Templated Vector implementation
//
#ifndef _VECTOR_H_
#define _VECTOR_H_

////////////////////////////////////////////////////////////////////////////////
//  INCLUDES
////////////////////////////////////////////////////////////////////////////////
#include <cstdlib>  // malloc

////////////////////////////////////////////////////////////////////////////////
//  DEFINITIONS
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  PROTOTYPES
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Vector
{
	T *_data {nullptr};
	size_t _size {0};
    size_t _max_size {0};
    constexpr size_t RESIZE_RATE {2};

    enum ThrowEnum {
        IndexOutOfRange = 1,
        MemoryAllocError
    }

  public:
	//Vector(void)

	void reserve(size_t x) const;
	void resize(size_t x) const;


	inline size_t size(void) const { return _size; }
	inline size_t len(void) const { return _size; }
	inline const T& end(void) const { return _data + (_size-1); }
	inline const T& at(size_t x) { x<_size ? return _data+x : throw IndexOutOfRange }

	// push_back, push
	void push_back(const T);
    inline void push(const T val) { push_back(val); }

	// pop_front
	// pop_back

    T pop_back(void);


	Vector<T> operator<<(const T);
	Vector<T> operator=(const Vector&);
	Vector<T> operator==(const Vector&);

};


////////////////////////////////////////////////////////////////////////////////
//  CODE
////////////////////////////////////////////////////////////////////////////////

template <class T>
void Vector::push_back(const T val)
{
    // Size validation
    if (_size+1 > _max_size) {
        const size_t new_size = (_size+1) * RESIZE_RATE;
        const auto p_tmp = (T *)realloc(_data, new_size * sizeof(T));
        if (nullptr == p_tmp) { free(_data); throw ThrowEnum::MemoryAllocError; }
        _auto = p_tmp;
        _max_size = new_size;
    }
    // Add the value
    *(_data+_size) = val;
    _size += 1;
}

template <class T>
T Vector::pop_back(void)
{
    // Sanity check
    if (0 == _size) {
        free(_data);
        throw ThrowEnum::IndexOutOfRange;
    }
    // Size validation
    if (_size <= _max_size/2) {
        const size_t new_size = ((_size + RESIZE_RATE)/RESIZE_RATE);
        const auto p_tmp  (T *)realloc(_data, new_size * sizeof(T));
        if (nullptr == p_tmp) { free(_data); throw ThrowEnum::MemoryAllocationError; }
        _max_size = new_size;
    }
    // Get the value
    _size -= 1;
    return *(_data+_size+1);
}

#endif // _VECTOR_H_ //
