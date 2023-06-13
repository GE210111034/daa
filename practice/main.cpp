#include <bits/stdc++.h>
using namespace std;

typedef vector<int> BULB;
int countAdjecentBulds(BULB B){
    int countE = 0, countO = 0, size = B.size();
    for(int i=0;i<size;i+=2) if(B[i]) countE++;
    for(int i=1;i<size;i+=2) if(B[i]) countO++;
    return max(countE, countO);
}

int main(){
    int size;
    cin >> size;
    BULB B(size);
    for(auto& b : B) cin >> b;
    int need;
    cin >> need;
    if(need >= countAdjecentBulds(B)) cout << "Yes";
    else cout << "No";
    return 0;
}

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
