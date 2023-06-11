#include <bits/stdc++.h>
using namespace std;

string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}
string reverseWords(string str) {
    str = reverseString(str);
    stringstream ss(str);
    string word;
    string reversedStr;

    while (ss >> word) {  reversedStr += word + " ";}

    reversedStr.pop_back(); // Remove the trailing space
    return reversedStr;
}
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string reversedStr = reverseWords(str);
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}
