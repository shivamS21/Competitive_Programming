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
    ll n;
    cin >> n;
    if(n>1 and n<4){
        cout<<"NO SOLUTION";
        return;
    } else if(n==2){
        cout<<1<<endl;
        return;
    }
    vector<int> arr(n);
    int i = 1;
    int no = 1;
    while(i < n){
        arr[i] = no;
        no += 1;
        i+=2;
    }
    i = 0;
    while(i < n){
        arr[i] = no;
        no += 1;
        i += 2;
    }
    for(int ele: arr) cout << ele << " ";
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
