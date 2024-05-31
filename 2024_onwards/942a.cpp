#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll>a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    int minAdditions = 0;
    for(int i = 0; i < n; i++) {
        if (a[i-minAdditions] > b[i]) {
            ++minAdditions;
        }
    }
    cout << minAdditions << endl;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}