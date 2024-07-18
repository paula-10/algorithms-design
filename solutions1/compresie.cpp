#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n, m;
    long long sumA = 0, sumB = 0;

    fin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        fin >> A[i];
        sumA += A[i];
    }

    fin >> m;
    vector<long long> B(m);
    for (int i = 0; i < m; ++i) {
        fin >> B[i];
        sumB += B[i];
    }

    int i = 0, j = 0;
    int length = 0;
    long long currSumA = 0, currSumB = 0;

    if (sumA != sumB) {
        fout << -1 << endl;
    } else {
        while (i < n && j < m) {
            currSumA = A[i];
            currSumB = B[j];
            while (currSumA != currSumB) {
                if (currSumA < currSumB) {
                    i++;
                    currSumA += A[i];
                } else {
                    j++;
                    currSumB += B[j];
                }
            }
            if (currSumA == currSumB) {
                length++;
                i++;
                j++;
            }
        }
    }

    fout << length << endl;

    fin.close();
    fout.close();
    return 0;
}
