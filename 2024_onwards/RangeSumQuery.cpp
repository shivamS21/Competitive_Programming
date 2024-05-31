#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long
const int N = 2e5+1;

void build(vector<int>&arr, ll segTree[], int vertex, int start, int end) {
    if (start == end) {
        segTree[vertex] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(arr, segTree, 2*vertex, start, mid);
    build(arr, segTree, 2*vertex+1, mid+1, end);

    segTree[vertex] = segTree[2*vertex] + segTree[2*vertex+1]; 
}
ll rangeSum(ll segTree[], int vertex, int start, int end, int l, int r) {
    if (l > r) return 0;
    if (start == l and end == r) return segTree[vertex];

    int mid = (start+end)/2;
    ll sum1 = rangeSum(segTree, 2*vertex, start, mid, l, min(r, mid));
    ll sum2 = rangeSum(segTree, 2*vertex+1, mid+1, end, max(mid+1, l), r);

    return sum1+sum2;
}
void update(ll segTree[], int vertex, int start, int end, int pos, ll val) {
    if (start == end) {
        segTree[vertex] = val;
        return;
    }
    int mid = (start+end)/2;
    if (pos <= mid) update(segTree, 2*vertex, start, mid, pos, val);
    else update(segTree, 2*vertex+1, mid+1, end, pos, val);
    segTree[vertex] = segTree[2*vertex] + segTree[2*vertex+1];
}
void solve(){
    ll n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll segTree[4*N]={0};
    build(arr, segTree, 1, 0, n-1);
    for(int i = 0; i < q; i++) {
        int check, a, b; cin >> check >> a >> b;
        if (check==1) {
            update(segTree, 1, 0, n-1, a-1, b);
        } else
        cout << rangeSum(segTree, 1, 0, n-1, a-1, b-1) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}