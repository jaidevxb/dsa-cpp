#include<bits/stdc++.h>
using namespace std;
// [HASHING] -> PRE STORING / FETCHING

void inputArray(int arr[], int n){
	for (int i = 0; i < n; i++) cin >> arr[i];
}
// bruteforce method to count no. of occurrence w/o hashing
int count(int number, int arr[], int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == number) cnt += 1;
    }
    return cnt;
}

// arr[1e6] is max when declaring int array inside main
// arr[ie7] is max when declaring int array on global

/* using array 
int main(){
    int n;
    cin >> n;
    int arr[n];
    inputArray(arr, n);

    // pre compute
    int hash[13] = {0}; // use the max value of element in array
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }
    
    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        // fetch
        cout << hash[number] << endl;
    }
    
    return 0;
}
*/

// using map for large nos. like 1e9
int main(){
    int n;
    cin >> n;
    int arr[n];
    inputArray(arr, n);

    // pre compute
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]] += 1;
    }

    /*
    // to print, map stores values in sorted order
    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl;
    } */
    
    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    
    return 0;
}
