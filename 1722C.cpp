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
    ll n; cin >> n;
    map<string,set<int>>mp;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            string st;
            cin >> st;
            mp[st].insert(i);
        }
    }

    vector<int> score(3, 0);

    for(auto it: mp){
        if(it.second.size() == 1){
            //each guy will get three points
            for(int x: it.second){
                score[x]+=3;
            }
        } else if(it.second.size() == 2){
            for(int x: it.second){
                score[x] += 1;
            }
        } 
    }
    cout << score[0] << " " << score[1] << " " << score[2] << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
