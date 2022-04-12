#include<bits/stdc++.h>
using namespace std;
long long p(vector<int>&a, vector<int>&b){
    int n = a.size(), m = b.size();
    long long ans = 0;
    int i = 0, j = 0;
    while(i < n and j < m){
        cout << i << " " << j << endl;
        if(a[i] < b[j]) ++i;
        else if(a[i] > b[j]) ++j;
        else{
            long long c1 = 1, c2 = 1;
            ++i;++j;
            while(i < n and a[i] == a[i-1]) ++c1;
            while(j < m and b[j] == b[j-1]) ++c2;
            ans += c1 * c2;
        }
    }
    return ans;
}
int main(){
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int j = 0; j < m; j++) cin >> b[j];
    return p(a, b);
}