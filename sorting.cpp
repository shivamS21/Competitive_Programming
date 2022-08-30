#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> arr, int n){
    //selection sort picking the minimum element from the error
    //putting thi minimum at the suitable positibe(preferbely at the last of sorted array)
    for(int i = 0; i < n-1; i++){
        int x = i+1;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[x]){
                x = j;
            }
        }
        swap(arr[i], arr[x]);
    }
    cout << "Array after selection sort: "; for(int ele: arr) cout << ele << " "; cout << endl;

    // stable algorithm
}
void mergeSortedArray(vector<int>&arr, int a, int mid, int b){
    vector<int> x(b-a+1);
    int y = 0;
    int i = a, j = mid+1;
    while(i <= mid and j <= b){
        if(arr[i] <= arr[j]){
            x[y] = arr[i++];
        } else{
            x[y] = arr[j++];
        }
        y++;
    }
    while(i <= mid){
        x[y++] = arr[i++];
    }
    while(j <= b){
        x[y++] = arr[j++];
    }
    y = 0;
    for(i = a; i <= b; i++){
        arr[i] = x[y++];
    }
    // not stable
}
void mergeSort(vector<int> &arr, int a, int b){
    if(a >= b) return;
    int mid = (a+b)/2;
    mergeSort(arr, a, mid);
    mergeSort(arr, mid+1, b);
    mergeSortedArray(arr, a, mid, b);
}
void merge_sort(vector<int> arr, int n){
    mergeSort(arr, 0, n-1);
    cout << "Array after Merge_sort: ";
    for(int ele: arr) cout << ele << " "; cout << endl;
}
void insertion_sort(vector<int> arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 and arr[j] > key){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
    cout << "Array after Insertion Sort: ";
    for(int ele: arr) cout << ele << " "; cout << endl;
    /*
        * This algorithm take maximum time to sort if arrays is decreasing.
        * or takes minimum time when array is increasing
        Time complexity:
        WORST   BEST    AVERAGE
        O(N2)   O(N)    
    */
}
void bubble_sort(vector<int> arr, int n){
    /*
        not suitable to large data sets because its average and worst complexity is quite high.
        works by swapping adjacent elements which are in wrong order.
        the algo needs one whole iteration to know whether the array is sorted.
    */

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1;j++){
            if(arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
        }
    }
    cout << "Array after Bubble_sort: ";
    for(int ele: arr) cout << ele << " "; cout << endl;

    /*
        The above function always runs O(n^2) time even if the array is sorted.
        It can be optimized by stopping the algorithm if the inner loop didn’t cause any swap. 
        WORST   BEST    AVERAGE
        O(N2)   O(N)    O(N2)
        In computer graphics, it is popular for its capability to detect a tiny error 
        (like a swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). 
        For example, it is used in a polygon filling algorithm, 
    */
}
void heap_sort(vector<int> arr, int n){
    
}
int main(){
    vector<int> arr = {-1, 18, 13, 18, -2, -16, 7, -1, -213, 11};
    cout << "Array before sorting: ";
    for(int ele: arr){
        cout << ele << " ";
    } cout << endl;
    selection_sort(arr, 10);
    merge_sort(arr, 10);
    insertion_sort(arr, 10);
    bubble_sort(arr, 10);
    cout << char('d'-2);
}