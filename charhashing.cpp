#include<bits/stdc++.h>
using namespace std;


// bruteforce method to count no. of occurrence w/o hashing
int countChar(char ch, string& s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) { 
        if (s[i] == ch) cnt++;
    }
    return cnt;
}

/* using array
int main(){
    string s;
    getline(cin, s);

    // pre compute
    int hash[256] = {0}; // use hash[26] for only lowercase or only uppercase str
    for(int i = 0; i < s.size(); i++){
        hash[s[i]] += 1; // s[i] - 'a' or s[i] - 'A'
    }

    int q;
    cin >> q;
    while(q--){
        char ch;
        cin >> ch;

        // fetch
        cout << hash[ch] << endl; // ch - 'a' or ch - 'A'

    }

    return 0;
} */

// using map
int main(){
    string s;
    getline(cin, s);

    // pre compute
    map<char, int> mpp; // use hash[26] for only lowercase or only uppercase str
    for(int i = 0; i < s.size(); i++){
        mpp[s[i]] += 1; // s[i] - 'a' or s[i] - 'A'
    }

    int q;
    cin >> q;
    while(q--){
        char ch;
        cin >> ch;

        // fetch
        cout << mpp[ch] << endl; // ch - 'a' or ch - 'A'

    }

    return 0;
}
