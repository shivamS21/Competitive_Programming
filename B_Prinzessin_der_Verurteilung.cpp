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
 
bool comp(string x,string y){
    if(x.length() != y.length())
    return x.length() < y.length();
    else return x < y;
}
 
/*...............code starts here................*/
// C is first won in M
vector<string> v;
void poss_string(){
    for(char c = 'a'; c <= 'z'; c++){
        string temp = "";
        temp += c;
        v.pb(temp);
    }
    for(char c = 'a'; c <= 'z'; c++){
        string temp="";
        temp += c;
        for(char d = 'a'; d <= 'z'; d++){
            v.pb(temp+d);
        }
    }
    for(char c = 'a'; c <= 'z'; c++){
        string temp="";
        temp += c;
        for(char d = 'a'; d <= 'z'; d++){
            string temp2="";
            temp2 += d;
            for(char e = 'a'; e <= 'z'; e++){
                v.pb(temp+temp2+e);
            }
        }
    }
}
void solve(){
    ll m,n,k;
    cin >> n;
    string s; cin >> s;
    rep(i,0,v.size()){
        int a = v[i].length();
        int f = 0;
        rep(j,0,n-a+1){
            string t = s.substr(j,a);
            if(t == v[i]){
                f = 1;
                break;
            }
        }
        if(!f){
            cout << v[i] << endl;
            return;
        }
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    poss_string();
    sortd(v);
    // rep(i,0,2000){
    //     cout << v[i]<<" ";
    // }
    // cout<<endl;
    while(tt--){
        solve();
    }
}
 