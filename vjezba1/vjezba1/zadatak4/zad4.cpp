#include <iostream>

int& at(int niz[], int i) {
	return niz[i];
}

int main() {
	int niz[] = { 1,2,3,4,5,6 };
	int i = 2;

	at(niz, i) = at(niz, i) + 1;

	std::cout << "Element na indeksu " << i << " sada je: " << niz[i] << std::endl;
		return 0;
}