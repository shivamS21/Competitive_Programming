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
 
void solve(){
    ll m,n,k;
    cin >> n;
    string temp; cin >> temp;
    char s[n];
    rep(i,0,n){
        s[i] = temp[i];
    }
    vector<int> post;
    rep(i,0,n){
        if(s[i] != '?')
        post.pb(i);
    }
    if(post.size()==0){
        char c = 'B';
        rep(i,0,n){
            s[i] = c;
            if(c == 'B')
            c = 'R';
            else c = 'B';
        }
        rep(i,0,n){
            cout << s[i] << "";
        }
        cout << endl;
        return;
    }
    // print(post);
    if(post[0] != 0){
        char c = s[post[0]];
        if(c == 'R') c = 'B';
        else c = 'R';
        rrep(i,post[0]-1, -1){
            s[i] = c;
            if(c == 'R') c = 'B';
            else c = 'R';
        }
    }
    if(post[post.size()-1] != n-1){
        char c = s[post[post.size()-1]];
        if(c == 'R') c = 'B';
        else c = 'R';
        rep(i,post[post.size()-1]+1, n){
            s[i] = c;
            if(c == 'R') c = 'B';
            else c = 'R';
        }
    }
    //now dealing with the intermediate cases present
    rep(i,0,post.size()-1){
        char c;
        if(s[post[i]] == 'R')
        c = 'B';
        else c = 'R';
        rep(j,post[i]+1, post[i+1]){
            s[j] = c;
            if(c == 'B')
            c = 'R';
            else c = 'B';
        }
    }
    rep(i,0,n){
        cout << s[i];
    }
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
 