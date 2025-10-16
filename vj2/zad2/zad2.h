#include <cstddef>
#include <iostream>


struct Vector {
	int *data;
	int size;
	int capacity;
};
Vector vector_new(int init_capacity) {
	Vector v;
	v.data = new int[init_capacity];
	v.size = 0;
	v.capacity = init_capacity;
	return v;
}

