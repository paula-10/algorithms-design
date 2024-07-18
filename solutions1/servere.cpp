#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int n;
    fin >> n;
    vector<int> putere(n), prag(n);
    for (int i = 0; i < n; ++i) {
        fin >> putere[i];
    }
    int maxim = 0;
    int minim = 1e9;
    for (int i = 0; i < n; ++i) {
        fin >> prag[i];
        if (prag[i] > maxim) {
            maxim = prag[i];
        }
        if (prag[i] < minim) {
            minim = prag[i];
        }
    }

    double curent = 0;

    double limitaStanga = minim;
    double limitaDreapta = maxim;
    while (limitaDreapta - limitaStanga > 0.1) {
        double mijloc = (limitaStanga + limitaDreapta) / 2;
        double putereStanga = 1e9;
        double putereDreapta = 1e9;
        for (int i = 0; i < n; i++) {
            double aux1 = putere[i] - abs(mijloc - prag[i]);
            double aux2 = putere[i] - abs(mijloc + 0.01 - prag[i]);
            if (aux1 < putereStanga) {
                putereStanga = aux1;
            }
            if (aux2 < putereDreapta) {
                putereDreapta = aux2;
            }
        }
        // continui cautarea curentului optim in intervalul cu putere maxima
        if (putereStanga <= putereDreapta) {
            limitaStanga = mijloc;
        } else {
            limitaDreapta = mijloc;
        }
    }

    curent = (limitaStanga + limitaDreapta) / 2;

    // dupa ce a fost gasit curentul optim, caut puterea minima
    double final = 1e9;
    for (int i = 0; i < n; i++) {
        double aux = putere[i] - abs(curent - prag[i]);
        if (aux < final) {
            final = aux;
        }
    }

    fout << fixed << setprecision(1) << final << endl;

    fin.close();
    fout.close();

    return 0;
}
