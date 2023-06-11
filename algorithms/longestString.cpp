#include <bits/stdc++.h>
using namespace std;

typedef vector<int> ROW;
typedef vector<ROW> COL;

int longestCommonSubsequence(string str1, string str2, string& sequence) {
    int m = str1.length();
    int n = str2.length();

    COL dp(m + 1, ROW(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];
    int i = m, j = n;
    sequence = "";

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            sequence = str1[i - 1] + sequence;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return length;
}

int main() {
    string str1, str2;
    cout << "Enter the first sequence: ";
    cin >> str1;
    cout << "Enter the second sequence: ";
    cin >> str2;

    string sequence;
    int length = longestCommonSubsequence(str1, str2, sequence);

    cout << "Length of the longest common subsequence: " << length << endl;
    cout << "Longest common subsequence: " << sequence << endl;

    return 0;
}
