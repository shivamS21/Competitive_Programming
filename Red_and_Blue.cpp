#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
int solve(){
    ll n;
    string S;
    cin >> n >> S;
    int D[n];
    for(int i = 0; i < n; i++)
        cin >> D[i];

    if(S[0] == 'B') return -1;
    int a = -1, b = D[0];
    int spills = 0;
    for(int i = 1; i < n; i++){
        if(S[i] == 'B'){
            if(i <= a){
                b = max(b, i+D[i]);
                continue;
            } 
            if(b < i) return -1;
            a = b;
            ++spills;
        }
        b = max(b, i+D[i]);
    }
    return spills;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--)cout<< solve() << endl;
}
