#include <iostream>

int limit(int value, int low = 0, int high = 100) {
    if (value < low) return low;
    if (value > high) return high;
    return value;
}

double limit(double value, double low = 0.0, double high = 100.0) {
    if (value < low) return low;
    if (value > high) return high;
    return value;
}

int main() {
    std::cout << limit(120) << std::endl;       
    std::cout << limit(-5) << std::endl;   
    std::cout << limit(2.5) << std::endl;
          
}
