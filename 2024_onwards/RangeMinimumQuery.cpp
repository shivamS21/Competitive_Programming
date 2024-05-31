#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long
const int N = 2*1e5;
void build(ll arr[], ll segTree[], int vertex, int start, int end) {
    if (start == end) {
        segTree[vertex] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(arr, segTree, 2*vertex, start, mid);
    build(arr, segTree, 2*vertex+1, mid+1, end);

    segTree[vertex] = min(segTree[2*vertex], segTree[2*vertex+1]);
}
void update(ll segTree[], int vertex, int start, int end, int pos, int value) {
    if (start == end) {
        segTree[vertex] = value;
        return;
    }
    int mid = (start+end)/2;
    if (pos <= mid) {
        update(segTree, 2*vertex, start, mid, pos, value);
    } else {
        update(segTree, 2*vertex+1, mid+1, end, pos, value);
    }
    segTree[vertex] = min(segTree[2*vertex], segTree[2*vertex+1]);
}
ll rangeMin(ll segTree[], int vertex, int start, int end, int l, int r) {
    if (l > r) return INT_MAX;
    if (start == l && end == r) return segTree[vertex];

    int mid = (start+end)/2;
    ll minHalf = rangeMin(segTree, 2*vertex, start, mid, l, min(r, mid));
    ll maxHalf = rangeMin(segTree, 2*vertex+1, mid+1, end, max(mid+1, l), r);
    return min(minHalf, maxHalf);
}
void solve(){
    int n, q; cin >> n >> q;
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll segTree[4*N+1];
    build(arr, segTree, 1, 0, n-1);
    for(int i = 0; i < q; i++) {
        int check, a, b; cin >> check >> a >> b;
        if (check==1) {
            update(segTree, 1, 0, n-1, a-1, b);
        } else
        cout << rangeMin(segTree, 1, 0, n-1, a-1, b-1) << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    
    while(t--){
        solve();
    }
}