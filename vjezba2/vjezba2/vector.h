#pragma once
#include <iostream>


struct Vector {
    int* data;
    int size;
    int capacity;
};

Vector vector_new(int init_capacity);
void vector_delete(Vector& v);
void vector_push_back(Vector& v, int value);
void vector_pop_back(Vector& v);
int vector_front(const Vector& v);
int vector_back(const Vector& v);
int vector_size(const Vector& v);
void print_vector(const Vector& v);