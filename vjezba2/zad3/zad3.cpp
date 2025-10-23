#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

double** alocirajMatricu(int m, int n) {
    double** mat = new double* [m];
    for (int i = 0; i < m; i++)
        mat[i] = new double[n];
    return mat;
}

void dealocirajMatricu(double** mat, int m) {
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;
}

void unesiMatricu(double** mat, int m, int n) {
    cout << "Unesite elemente matrice (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "mat[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
    }
}

void generirajMatricu(double** mat, int m, int n, double a, double b) {
    srand(time(nullptr));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double r = (double)rand() / RAND_MAX;
            mat[i][j] = a + r * (b - a);
        }
    }
}

void ispisiMatricu(double** mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << fixed << setprecision(4) << mat[i][j];
        }
        cout << endl;
    }
}

double** saberiMatrice(double** A, double** B, int m, int n) {
    double** C = alocirajMatricu(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double** oduzmiMatrice(double** A, double** B, int m, int n) {
    double** C = alocirajMatricu(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double** pomnoziMatrice(double** A, double** B, int m, int n, int p) {
    double** C = alocirajMatricu(m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

double** transponirajMatricu(double** A, int m, int n) {
    double** T = alocirajMatricu(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}

int main() {
    int m, n;
    cout << "Unesite dimenzije matrice (m n): ";
    cin >> m >> n;

    double** A = alocirajMatricu(m, n);
    double** B = alocirajMatricu(m, n);

    cout << "Generiranje matrica A i B";
    generirajMatricu(A, m, n, -5.0, 5.0);
    generirajMatricu(B, m, n, -5.0, 5.0);

    cout << "Matrica A:";
    ispisiMatricu(A, m, n);

    cout << "\nMatrica B:\n";
    ispisiMatricu(B, m, n);

    cout << "\nSabiranje matrica\n";
    double** C = saberiMatrice(A, B, m, n);
    ispisiMatricu(C, m, n);
    dealocirajMatricu(C, m);

    cout << "\nOduzimanje matrica\n";
    C = oduzmiMatrice(A, B, m, n);
    ispisiMatricu(C, m, n);
    dealocirajMatricu(C, m);

    if (m == n) {
        cout << "\nMnoženje matrica\n";
        C = pomnoziMatrice(A, B, m, n, n);
        ispisiMatricu(C, m, n);
        dealocirajMatricu(C, m);
    }

    cout << "\nTransponirana matrica A\n";
    double** T = transponirajMatricu(A, m, n);
    ispisiMatricu(T, n, m);

    dealocirajMatricu(A, m);
    dealocirajMatricu(B, m);
    dealocirajMatricu(T, n);

    return 0;
}
