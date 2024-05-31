#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long
const int N = 2*1e5;
void build(ll segTree[], ll arr[], int start, int end, int vertex) {
    if (start == end) {
        segTree[vertex] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(segTree, arr, start, mid, 2*vertex);
    build(segTree, arr, mid+1, end, 2*vertex+1);

    segTree[vertex] = (segTree[2*vertex] ^ segTree[2*vertex+1]);
}
ll rangeXOR(ll segTree[], int start, int end, int l, int r, int vertex) {
    if (l > r) return 0;
    if (start == l && end == r) return segTree[vertex];

    int mid = (start+end)/2;
    ll xorFirst = rangeXOR(segTree, start, mid, l, min(r, mid), 2*vertex);
    ll xorSecond = rangeXOR(segTree, mid+1, end, max(mid+1, l), r, 2*vertex+1);

    return xorFirst ^ xorSecond;
}
void solve(){
    ll segTree[4*N+1];
    int n, q; cin >> n >> q;
    ll arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(segTree, arr, 0, n-1, 1);
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << rangeXOR(segTree, 0, n-1, a-1, b-1, 1) << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
}