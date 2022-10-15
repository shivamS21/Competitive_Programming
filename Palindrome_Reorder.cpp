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
    vector<int> arr(26, 0);
    string s; cin >> s;
    for(char c: s){
        arr[c-'A']++;
    }
    string a = "", b = "";
    int count = 0;
    char odd;
    for(int i = 0; i < 26; i++){
        if(arr[i]%2){
            ++count;
            odd = i+'A';
        }
        for(int j = 0; j < arr[i]/2; j++){
            a += i+'A';
        }
    }
    if(count>1){
        cout<<"NO SOLUTION";
    } else{
        // cout<<"YES"<<endl;
        b=a;
        if(count)
        a += odd;
        reverse(b.begin(), b.end());
        cout<<a+b<<endl;
    }
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
