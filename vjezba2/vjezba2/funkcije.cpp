#include "vector.h"
#include <iostream>
Vector vector_new(int init_capacity) {
    Vector v;
    v.data = new int[init_capacity];
    v.size = 0;
    v.capacity = init_capacity;
    return v;
}

void vector_delete(Vector& v) {
    delete[] v.data;
    v.data = nullptr;
    v.size = 0;
    v.capacity = 0;
}

void vector_push_back(Vector& v, int value) {
    if (v.size >= v.capacity) {
        int new_capacity = v.capacity * 2;
        int* new_data = new int[new_capacity];
        for (int i = 0; i < v.size; i++)
            new_data[i] = v.data[i];
        delete[] v.data;
        v.data = new_data;
        v.capacity = new_capacity;
    }
    v.data[v.size] = value;
    v.size++;
}

void vector_pop_back(Vector& v) {
    v.size--;
}

int vector_front(const Vector& v) {
    return v.data[0];
}

int vector_back(const Vector& v) {
    return v.data[v.size - 1];
}

int vector_size(const Vector& v) {
    return v.size;
}

void print_vector(const Vector& v) {
    for (int i = 0; i < v.size; i++)
        std::cout << v.data[i] << " ";
    std::cout << std::endl;
}
