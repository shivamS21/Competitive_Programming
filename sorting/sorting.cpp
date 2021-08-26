#include<bits/stdc++.h>
using namespace std;
int n;
#define print(v) for(auto it: v) cout << it << " "; cout << endl;
void selectionSort(vector<int> arr){
    for(int i = 0; i < n; i++){
        int post = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[post])
            post = j;
        }
        int temp = arr[post];
        arr[post] = arr[i];
        arr[i] = temp;
    }
    cout << "After Selection Sort:"; print(arr);
}
void bubblesort(vector<int> arr){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "After BUbble Sort:"; print(arr);
}
void recurse(vector<int>&arr, int j, int i){
    if(j >= n-i-1) return;
    if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
    }
    recurse(arr, j+1, i);
}
void recursiveBubblesort(vector<int> arr){
    cout << "Before Recursive Bubble Sort: "; print(arr);
    for(int i = 0; i < n-1; i++){
        recurse(arr, 0, i);
    }
    cout << "After Recursive Bubble Sort:"; print(arr);
}
void insertionSort(vector<int> arr){
    for(int i = 1; i < n; i++){
        int j = i-1;
        while(j > -1 && arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j -= 1;
        }
    }
    cout << "After Insertion Sort:"; print(arr);
}
void recurse(vector<int> &arr, int i){
    if(i == n) return;
    int j = i-1;
    while(j > -1 && arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        j -= 1;
    }
    recurse(arr, i+1);
}
void recursiveInsertionSort(vector<int> arr){
    recurse(arr, 1);
    cout << "After recursive insertion Sort: "; print(arr);
}
void merge(vector<int> &a, int l , int m, int r){
    vector<int> temp;
    int i = l, j = m+1;
    while(i <= m && j <= r){
        if(a[i] < a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i <= m){
        temp.push_back(a[i]);
        i++;
    }
    while(j <= r){
        temp.push_back(a[j]);
        j++;
    }
    i = 0;
    while(i < temp.size()){
        a[l+i] = temp[i];
        i++;
    }
}
void mergeSort(vector<int> &arr, int start, int end){
    if(start >= end) return;
    int middle = start + (end - start)/2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle+1, end);
    merge(arr, start, middle, end);
}
void merging(vector<int> arr){
    mergeSort(arr, 0, n-1);
    cout << "After mergeSort Sort: "; print(arr);
}
void partition(){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high-1;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    returni+1;
}
int main(){
    vector<int> arr = {-8, 9, 4, 0, 1, 5, -6, -2};
    n = arr.size();
    selectionSort(arr);
    bubblesort(arr);
    recursiveBubblesort(arr);
    insertionSort(arr);
    recursiveInsertionSort(arr);
    merging(arr);
}