#include "vector.h"
#include <iostream>

int main() {
    Vector v = vector_new(2);

    vector_push_back(v, 10);
    vector_push_back(v, 20);
    vector_push_back(v, 30);
    vector_push_back(v, 40);

    std::cout << "Vektor: ";
    print_vector(v);

    std::cout << "Prvi element: " << vector_front(v) << std::endl;
    std::cout << "Zadnji element: " << vector_back(v) << std::endl;
    std::cout << "Velicina: " << vector_size(v) << std::endl;
    std::cout << "Kapacitet: " << v.capacity << std::endl;

    vector_pop_back(v);
    std::cout << "Nakon pop_back: ";
    print_vector(v);

    vector_delete(v);
    return 0;
}
