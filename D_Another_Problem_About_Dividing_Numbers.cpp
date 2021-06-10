//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
 
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
ll totalPrime(ll no){
    ll ans = 0;
    while(no%2==0){
        ans += 1;
        no = no/2;
    }
    ll temp = no;
    for(ll i = 3; i*i <= temp; i+=2){
        while(no % i == 0){
            no /= i;
            ans += 1;
        }
    }
    if(no != 1)
    ans += 1;
    return ans;
}
void solve(){
    ll a,b,k; cin >> a >> b >> k;
    int x = totalPrime(a), y = totalPrime(b);
    if(k==1){
        if((a%b==0 or b%a==0) && a != b)
        cout << "YES";
        else cout << "NO";
        cout << endl;
        return;
    }
    else if(x+y >= k)
    cout << "YES";
    else cout << "NO";
    cout<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 