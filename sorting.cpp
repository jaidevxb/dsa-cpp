#include<bits/stdc++.h>
using namespace std;

void inputArray(int arr[], int n){
	for (int i = 0; i < n; i++) cin >> arr[i];
}
void printArray(int arr[], int n){
   	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
void inputVector(vector<int> &arr){
	for (int &element : arr) cin >> element;
}
void printVector(vector<int> &arr){
   	for (int &element : arr) cout << element << " ";
}

// selectionSort push smallest to the first index and next smallest to 2nd index and so on
void selectionSort(int arr[], int n){
    for(int i = 0; i <= n-2; i++){
        int min = i;
        for(int j = i; j <= n-1; j++){
            if(arr[j] < arr[min]) min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
// bubbleSort push biggest to the last index and next biggest to last before index and so on by adjacent swaps
void bubbleSort(int arr[], int n){
    for(int i = n-1; i >= 1; i--){
        int didSwap = 0;    
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
        // cout << "runs" << endl; to check
    }
}
// insertionSort takes an element and place it in its correct position
void insertionSort(int arr[], int n){
    for(int i = 0; i <= n-1; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp; 
            j--;
        }
    }
}

// bubbleSort using recursion
void bubbleSort1(int arr[], int n){
    // base Case
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            didSwap = 1;
        }
    }
    if (didSwap == 0) return;
    bubbleSort1(arr, n - 1);
}
// insertionSort using recursion
void insertionSort1(int arr[], int i, int n){
    // base Case
    if (i == n) return;
    int j = i;
    while (j > 0 && arr[j-1] > arr[j]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }
    insertionSort1(arr, i+1, n);
}

// mergeSort -> divide and conquer TC -> O(N logN) SC -> O(N)
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low; // [low.... mid]
    int right = mid+1; // [mid+1.... high]
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}
void mS(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    merge(arr, low, mid, high);
}

// quickSort -> divide and conquer TC -> O(N logN) SC -> O(1)
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void qS(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qS(arr, low, pIndex-1);
        qS(arr, pIndex+1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    inputVector(arr);
    qS(arr, 0, n-1);
    printVector(arr);

    return 0;
}