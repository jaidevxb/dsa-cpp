#include<bits/stdc++.h>
using namespace std;

// recursion
// print name n times
void printname(int i, int n){
	cout << "Jai" << endl;
	if(i == n) return; // base case to avoid stack overflow 
	printname(i+1, n);
}
void printname1(int n){
	if(n == 0) return; // base case to avoid stack overflow 
	printname1(n-1);
	cout << "Jai" << endl; // backtracking
}

// print lineraly from 1 to n
void printno(int i, int n){
	cout << i << " ";
	if(i == n) return;
	printno(i+1, n);
}
void printno1(int n){
	if(n == 0) return;
	printno1(n-1);
	cout << n << " "; // backtracking aka unwinding
}

// print lineraly from n to 1
void printnorev(int i, int n){
	cout << i << " ";
	if(i == 1) return;
	printnorev(i-1, n);
}
void printnorev1(int n){
	if(n == 0) return;
	cout << n << " ";
	printnorev1(n-1); 
}

// sum of n terms parameter method
void sumofnterms(int n,int sum = 0){
	if(n < 1){
		cout << sum;
		return;
	}
	sumofnterms(n-1, sum+n);
}
// function method
int sumofnterms1(int n){
	if(n == 0) return 0;
	return n + sumofnterms1(n-1);
}

// factorial of n terms parameter method
void fact(int n, int f = 1){
	if(n == 1){
		cout << f;
		return;
	}
	fact(n-1, f*n);
} 

// funtion method
int fact1(int n){
	if(n == 1) return 1; // cos 0*anything is 0
	return n * fact1(n-1);
}

// reverse an array
void inputArray(int arr[], int n){
	for (int i = 0; i < n; i++) cin >> arr[i];
}
void printArray(int arr[], int n){
   	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
// function to reverse array using recursion
// 2 pointer
void reverseArray(int arr[], int start, int end){ 
   	if (start < end) {
    	swap(arr[start], arr[end]);
    	reverseArray(arr, start + 1, end - 1);
   	}
}
// 1 pointer
void reverseArray1(int arr[], int n, int i=0){ 
	if(i >= n/2) return;
	swap(arr[i], arr[n-i-1]);
	reverseArray1(arr, n, i+1);
}
void reverseArray2(int arr[], int n){
   	reverse(arr, arr + n);
}

// given string is palindrome or not
bool palindrome(string &s, int i=0){
	if(i >= s.size()/2) return true;
	if(s[i] != s[s.size()-i-1]) return false;
	palindrome(s, i+1);
}
// leetcode use getline(cin, s) in main
bool palindrome1(string &s) {
    int start = 0;
    int end = s.size() - 1;
    while (start <= end) {
        while (start <= end && !isalnum(s[start])) {
            start++;
        }
        while (start <= end && !isalnum(s[end])) {
           	end--;
        }
        if (start <= end) {
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
    }
    return true;
}

// fibonacci using recursion 
int fibonacci(int n){
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
// fibonacci using for loop
int fibonacci1(int n){
    if (n <= 1) return n;
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}

int main(){
	int n;
	cin >> n;
	cout << fibonacci(n);
   	return 0;
}