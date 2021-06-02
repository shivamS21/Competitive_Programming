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
int n = 1e7+5;
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    vector<int> prime(n, true);
    for(ll p=2;p*p < n;p+=1) {
        if(prime[p] == true){
           for (ll i=p*p; i<n; i += p) 
                prime[i] = false;
        }
    }

    int p[n+1]={0};
    p[2] = 1;
    p[3] = 2;
    p[4] = 2;
    rep(i,5,n+1){
        p[i] = p[i-1]+ prime[i];
    }
    while(tt--){
        int x; cin >> x;
        if(x==2)
        cout<<1<<endl;
        else if(x==3 or x==4)
        cout<<2<<endl;
        else
        cout << p[x] - p[x/2]+1<<endl;
    }
}
 