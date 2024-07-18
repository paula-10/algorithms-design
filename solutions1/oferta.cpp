#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, k;
    fin >> n >> k;
    vector<long long> prices(n);
    for (int i = 0; i <= n; ++i) {
        fin >> prices[i];
    }
    vector<double> dp(n, 0);

    double suma1 = 0, suma2 = 0, suma3 = 0;
    dp[0] = prices[0];
    if (prices[1] < prices[0]) {
        dp[1] = prices[0] + prices[1] / 2.0;
    } else {
        dp[1] = prices[0] / 2.0 + prices[1];
    }
    for (int i = 2; i < n; i++) {
        suma1 = dp[i - 1] + prices[i];
        // pentru suma1 nu aplic nicio reducere pentru produsul actual
        if (prices[i] <= prices[i - 1]) {
        // suma2 reprezinta reducerea pentru doua produse
            suma2 = prices[i] / 2.0 + prices[i - 1] + dp[i - 2];
        // suma3 reprezinta reducerea pentru 3 produse
            if (prices[i - 2] <= prices[i]) {
                suma3 = prices[i] + prices[i - 1];
            } else {
                suma3 = prices[i - 1] + prices[i - 2];
            }
            if (i > 2)
                suma3 += dp[i - 3];
        } else {
            suma2 = prices[i - 1] / 2.0 + prices[i] + dp[i - 2];
            if (prices[i - 2] <= prices[i - 1]) {
                suma3 = prices[i - 1] + prices[i];
            } else {
                suma3 = prices[i] + prices[i - 2];
            }
            // verificare ca sunt la o pozitie valida pentru a adauga dp[i - 3]
            if (i >= 2)
                suma3 += dp[i - 3];
        }
        double minim = min(suma2, suma3);
        dp[i] = min(suma1, minim);
    }

    if (k == 1) {
        fout << fixed << setprecision(1) << dp[n - 1] << endl;
    } else {
        fout << -1 << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
