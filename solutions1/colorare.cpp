#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

#define MOD ((int)1e9 + 7)

unsigned long long mod(unsigned long long x) {
    return ((x % MOD) + MOD) % MOD;
}

// calculez puterea folosind modulul
unsigned long long Pow(unsigned long long base, unsigned long long exp) {
    if (exp == 0) return 1LL;
    if (exp == 1) return mod(base);
    unsigned long long result = 1LL;
    while (exp) {
        if (exp % 2) {
            result = mod(result * base);
        }
        base = mod(base * base);
        exp /= 2;
    }
    return result % MOD;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    int k;
    fin >> k;
    vector<unsigned long long> numbers(k);
    vector<char> positions(k);
    for (int i = 0; i < 2 * k; i++) {
        fin >> numbers[i];
        fin.ignore();
        fin >> positions[i];
        fin.ignore();
    }
    unsigned long long produs  = 1;
    vector<unsigned long long> results(k);
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            if (positions[i] == 'H') {
                results[i] = (2 * Pow(3, numbers[i])) % MOD;
            } else if (positions[i] == 'V') {
                results[i] = (3 * Pow(2, numbers[i] - 1)) % MOD;
            }
        } else {
            if (positions[i] == 'H' && positions[i - 1] == 'H') {
                results[i] = Pow(3, numbers[i]);
            } else if (positions[i] == 'H' && positions[i - 1] == 'V') {
                results[i] = (2 * Pow(3, numbers[i] - 1)) % MOD;
            } else if (positions[i] == 'V' && positions[i - 1] == 'V') {
                results[i] = Pow(2, numbers[i]);
            } else if (positions[i] == 'V' && positions[i - 1] == 'H') {
                results[i] = Pow(2, numbers[i] - 1);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        produs *= results[i];
        produs %= MOD;
    }
    fout << produs % MOD << endl;

    fin.close();
    fout.close();

    return 0;
}
