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
int r, c, c1,c2; 
int vec[1002][1002];
bool valid(int x, int y){
    if(x >= 0 and y >= 0 and x < r and y < c and vec[x][y] == -1)
    return true;
    else return false;
}
void bfs(int x, int y){
    queue<pair<pair<int,int>, int> > q;
    q.push(mk(mk(x, y), 0));
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int val = q.front().second;
        q.pop();
        if(!valid(a,b)) continue;

        vec[a][b] = val;
        val += 1;
        q.push(mk(mk(x, y-1), val));
        q.push(mk(mk(x-1, y-1), val));
        q.push(mk(mk(x-1, y), val));
        q.push(mk(mk(x-1, y+1), val));
        q.push(mk(mk(x, y+1), val));
        q.push(mk(mk(x+1, y+1), val));
        q.push(mk(mk(x+1, y), val));
        q.push(mk(mk(x+1, y-1), val));
    }
} 
void solve(){
    cin >> r >> c >> c1 >> c2;
    rep(i,0,r){
        rep(j,0,c) vec[i][j] = -1;
    }
    bfs(c1, c2);
    rep(i,0,r){
        rep(j,0,c) cout << vec[i][j] << " ";
        cout << endl;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 