#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int countAparitions(string word, char c) {
    int count = 0;
    for (char ch : word) {
        if (ch == c) {
            count++;
        }
    }
    return count;
}

bool compareWords(string& a, string& b, char c) {
    int countA = countAparitions(a, c);
    int countB = countAparitions(b, c);
    return countA > countB;
}

void sortWords(vector<string>& words, char c) {
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (compareWords(words[i], words[j], c)) {
                swap(words[i], words[j]);
            }
        }
    }
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int n;
    fin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        fin >> words[i];
    }

    int maxLength = 0;
    vector<int> maxLen(26, 0);

    for (int i = 0; i < 26; i++) {
        vector<string> sorted(words);
        // sortWords(words, (i + 'a'));
        sort(sorted.begin(), sorted.end(), [i](const string& a, const string& b) {
            return countAparitions(a, 'a' + i) > countAparitions(b, 'a' + i);
        });
        for (const auto& word : sorted) {
            if (countAparitions(word, (i + 'a')) != 0) {
                int currentLen = word.size();
                int currentAparitions = countAparitions(word, (i + 'a'));
                for (const auto& word2 : sorted) {
                    if (word != word2) {
                        int newLen = currentLen + word2.size();
                        int newAparitions = currentAparitions + countAparitions(word2, (i + 'a'));
                        if (newAparitions > newLen / 2) {
                            currentLen = newLen;
                            currentAparitions = newAparitions;
                        }
                    }
                }
                maxLen[i] = max(maxLen[i], currentLen);
            }
        }
            maxLength = max(maxLength, maxLen[i]);
    }

    fout << maxLength << endl;

    fin.close();
    fout.close();

    return 0;
}
