#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define endl '\n'
#define st first
#define nd second
#define double long double
#define ii pair<int, int>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 7;
const int N = 105;
double pi = acos(-1);
int t, n, k;
bool vis[N << 1];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<ii> v;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;
            if (x > y)
            {
                swap(x, y);
            }
            vis[x] = true;
            vis[y] = true;
            v.emplace_back(x, y);
        }
        vector<int> v1;
        for (int i = 0; i < (n << 1); i++) {
            if (!vis[i]) {
                v1.pb(i);
            }
        }
        for (int i = 0; i < n - k; i++) {
            v.emplace_back(mp(v1[i], v1[i + n - k]));
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i].st < v[j].st && v[i].nd < v[j].nd && v[i].nd > v[j].st) {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}