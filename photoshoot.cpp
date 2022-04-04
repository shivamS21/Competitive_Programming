#include <bits/stdc++.h>
#define ll long long int 
#define ld long double 
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll T; cin>>T; 
    while(T--){
        ll n; cin>>n;
        string s; 
        cin>>s; 
        ll ans = 0; 
        vector<ll> arr; 
        for(int i = 0; i<n; i++){
            if(s[i]=='0') arr.push_back(i);
        }
        if(n>2 and !arr.empty())
        {
             for(int i = 0 ; i<arr.size()-1; i++){
                ans = ans + 3 - arr[i+1] + arr[i];    
             }
        }
        else{
            if(s=="0")  ans = 0; 
            else if(s=="00") ans =2; 
            else ans = 0;
        }
        arr.clear();
        cout<<ans<<endl;
    }
    return 0; 
}