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
void solve(){
    int q;cin >> q;
    ll otherA = 0, otherB = 0, cntA = 1, cntB = 1;
    while(q--){
        string x;
        int d, k;
        cin >> d >> k >> x;
        
        for(char c: x){
            if(d==1){
                if(c != 'a') otherA = 1;
                else cntA+=k;
            } else{
                if(c != 'a') otherB = 1;
                else cntB+=k;
            }
        }
        if(otherB)cout<<"YES";
        else if(!otherA and cntA<cntB) cout<<"YES";
        else cout<<"NO";
        cout<<endl;

    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
