#include <iostream>

int* funkcija(int n) {
	int* niz = new int[n];
	niz[0] = 1;
	niz[1] = 1;

	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;

}



int main() {

	int n = 8;
	int* noviniz = funkcija(n);
	std::cout << "fibonacci niz: ";

	for (int i = 0; i < n; i++) {
		std::cout << noviniz[i];
	}

	delete[] noviniz;
	return 0;
}