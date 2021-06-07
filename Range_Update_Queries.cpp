// we need to make three functions only to make a code which will be handling the range-query problems.
// we will be making the tree implicitly
// first function = building the tree which uses the array of size 4 times the size of the original array
// second function = to sum the values in the segtreement from l to r
// third function = to update the values in the implicit array at certain position let say, pos
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+1;
void build(ll x[], ll segtree[],int vertex, int start, int end){
    if(start == end) segtree[vertex] = x[start];
    else{
        ll mid = (start+end)/2;
        build(x,segtree,2*vertex,start,mid);
        build(x,segtree,2*vertex+1,mid+1,end);
        segtree[vertex] += (segtree[2*vertex]+segtree[2*vertex+1]);
    }
}
ll rangesum(ll segtree[], int vertex, int start, int end, int l, int r){
    if(l>r) return 0;
    if(start == l and end == r) return segtree[vertex];
    int mid = (start+end)/2;
    ll sum1 = rangesum(segtree, 2*vertex, start, mid, l, min(r, mid));
    ll sum2 = rangesum(segtree, 2*vertex+1, mid+1, end, max(mid+1, l), r);
    return sum1+sum2; 
}
void update(ll segtree[], int vertex, int start, int end, int pos, ll val){
    //update for sum of elements vector.
    if(start == end) segtree[vertex] += val;
    else{
        int mid = (start+end)/2;
        if(pos <= mid) update(segtree, 2*vertex, start, mid, pos, val);
        else update(segtree, 2*vertex+1, mid+1, end, pos, val);
        segtree[vertex] = segtree[2*vertex] + segtree[2*vertex+1];
    }
}
int main(){
    int n,q; cin >> n >> q;
    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    ll segtree[4*N]={0};
    ll x[n+1]={0};
    build(x, segtree, 1, 0, n);
    // for(int i=0;i<21;i++) cout << segtree[i] << " ";
    //here l and r are entered as per the 0th based indexing
    for(int i=0;i<q;i++){
    	int check;
        if(check==1){
            //increament
            int a, b, u; cin >> a >> b >> u;
            update(segtree, 1, 0, n, a-1, u);
            update(segtree, 1, 0, n, b, u);
        }
        else{
            //tell the value at postion.
            int post; cin >> post;
            cout << arr[post-1] + rangesum(segtree, 1, 0, n, 0, post-1)<< endl;
        }
    }
    return 0;
}