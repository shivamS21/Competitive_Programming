#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long
const int N = 2*1e5;

void update (ll segTree[], int vertex, int start, int end, int pos, int val) {
    if (start == end) {
        segTree[vertex] += val;
        return;
    }
    int mid = (start+end)/2;
    if (pos <= mid) update(segTree, 2*vertex, start, mid, pos, val);
    else update(segTree, 2*vertex+1, mid+1, end, pos, val);

    segTree[vertex] = segTree[2*vertex] + segTree[2*vertex+1];
}

ll findValue(ll segTree[], int vertex, int start, int end, int l, int r) {
    if (l > r) return 0;
    if (start == l && end == r) return segTree[vertex];

    int mid = (start+end)/2;
    ll sumFirst = findValue(segTree, 2*vertex, start, mid, l, min(r, mid));
    ll sumSecond = findValue(segTree, 2*vertex+1, mid+1, end, max(mid+1, l), r);

    return sumFirst + sumSecond;
}
void solve(){
    ll segTree[4*N+10];
    int n, q; cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll sumArr[n+1];

    for(int i = 0; i<q; i++) {
        int typeQuery; cin >> typeQuery;
        if (typeQuery==1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(segTree, 1, 0, n, a-1, u);
            update(segTree, 1, 0, n, b, -u);
        } else {
            int k; cin >> k;
            cout << arr[k-1] + findValue(segTree, 1, 0, n, 0, k-1) << endl;
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
}