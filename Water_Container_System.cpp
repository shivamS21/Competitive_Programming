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
int solve(){
    int n, queries;
    cin >> n >> queries;
    vector<int>adj[n+1];

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> level, visited(n+1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    for(int l = 1; !q.empty(); l++){
        level.push_back(q.size());
        int sz = q.size();

        for(int i = 0; i < sz; i++){
            int u = q.front();
            q.pop();

            for(int v: adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = 1;
                }
                    
            }
        }
    }

    vector<int> random(queries);
    for(int i = 0; i < queries; i++) cin >> random[i];

    for(int i = 1; i < level.size(); i++)
        level[i] += level[i-1];

    int it = upper_bound(level.begin(), level.end(), queries) - level.begin();

    return level[it-1];

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    for(int i = 0; i < tt; i++){
        cout << "Case #"<<i+1<<": "<< solve() << endl;
    }
}
