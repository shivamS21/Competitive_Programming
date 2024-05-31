#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long
void build(ll segTree[], ll rooms[], int vertex, int start, int end) {
    if (start == end) {
        segTree[vertex] = rooms[start];
        return;
    }
    int mid = (start+end)/2;
    build(segTree, rooms, 2*vertex, start, mid);
    build(segTree, rooms, 2*vertex+1, mid+1, end);
    segTree[vertex] = max(segTree[2*vertex], segTree[2*vertex+1]);
}
void update (ll segTree[], int vertex, int start, int end, int pos, int val) {
    if (start == end) {
        segTree[vertex] = val;
        return;
    }
    int mid = (start+end)/2;
    if (pos <= mid) {
        update(segTree, 2*vertex, start, mid, pos, val);
    } else{
        update(segTree, 2*vertex+1, mid+1, end, pos, val);
    }
    segTree[vertex] = max(segTree[2*vertex], segTree[2*vertex+1]);
}
ll maxValue(ll segTree[], int vertex, int start, int end, int l, int r) {
    if (l > r) return -1;
    if (start == l && end == r) return segTree[vertex];

    int mid = (start+end)/2;
    ll maxLeft = maxValue(segTree, 2*vertex, start, mid, l, min(r, mid));
    ll maxRight = maxValue(segTree, 2*vertex+1, mid+1, end, max(l, mid+1), r);

    return max(maxLeft, maxRight);

}
void bsearch(ll segTree[], ll rooms[], int n) {
    int a = 0, b = n-1;
    int guest; cin >> guest;
    while(a < b) {
        int mid = (a+b)/2;
        ll mx1 = maxValue(segTree, 1, 0, n-1, a, mid);
        if(mx1 >= guest) {
            b = mid;
        } else {
            a = mid+1;
        }
    }
    if (a == n-1 && rooms[n-1] < guest) {
        cout << 0 << endl;
    }
    else {
        cout << a+1 << endl;
        update(segTree, 1, 0, n-1, a, rooms[a]-guest);
        rooms[a] -= guest;
    }
}
const int N = 2*1e5+1;
void solve(){
    int n, m; cin >> n >> m;
    ll rooms[n], guests[m];
    for(int i = 0; i < n; i++) cin >> rooms[i];

    ll segTree[4*N+1];
    build(segTree, rooms, 1, 0, n-1);
    for(int j = 0; j < m; j++) {
        bsearch(segTree, rooms, n);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
}