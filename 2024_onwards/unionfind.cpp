#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long

/**
 * Three functions: 
 * We use parent to
*/
class disjoinSet {
    int *rank, *parent, n;
    public:
    disjoinSet(int n) {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet() {
        for (int i = 0; i < this->n; i++) {
            parent[i] = i;
        }
    }
    int find (int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }
    void Union(int x, int y) {
        int xRep = find(x);
        int yRep = find(y);

        if (rank[xRep] < rank[yRep]) {
            parent[xRep] = yRep;
        } else if (rank[yRep] < rank[xRep]) {
            parent[yRep] = xRep;
        } else {
            parent[xRep] = yRep;
            rank[yRep] += 1;
        }
    }
};
void solve(){
    disjoinSet ds(5);
    ds.Union(1, 0);
    ds.Union(1, 2);
    ds.Union(3, 4);

    cout << (ds.find(1) == ds.find(2)) << '\n';
    cout << (ds.find(3)==ds.find(4)) << '\n';
    cout << (ds.find(1)==ds.find(4)) << '\n';
    
}
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
}

// 5-10
// 2 - 11
// 2-11, 5-10