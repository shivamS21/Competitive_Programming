#include<bits/stdc++.h>
#define int long long
#define M 1000000007
using namespace std; 

int n, a, b, c;

int findcost(vector<int> v, int n, int high, vector<int> psum, vector<int> ssum){
    int tmp = lower_bound(v.begin(), v.end(), high) - v.begin();
    int add, remove;
    if(tmp==0){
      remove = psum[n-1] - n*high;
      add = 0;
    }else if(tmp==n){
      remove = 0;
      add = n*high - psum[n-1];
    }else{
      remove = ssum[tmp] - (n-tmp)*high;
      add = tmp*high - psum[tmp-1];
    }

    //cout << high << " " << remove << " " << add <<  " " << tmp << " " << psum[tmp-1] << '\n';

    int cost = 0;
    if(remove>add){
      cost += ((remove-add)*b + add*c)%M;
    }else{
      cost += ((add-remove)*a + remove*c)%M;
    }

    return cost;
}
void solve(){
  cin >> n >> a >> b >> c;
  c = min((a+b), c);
  vector<int> v(n,0);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  vector<int> psum(n);
  int csum = 0;
  for(int i=0; i<n; i++){
    csum += v[i];
    psum[i] = csum;
  }
   csum = 0;
  vector<int> ssum(n);
  for(int i=n-1; i>=0; i--){
    csum += v[i];
    ssum[i] = csum;
  }

  int low = 1;
  int high, mid, cost;
  int currentcost = findcost(v,n,low,psum,ssum);
  
  while(true){
    high = 2*low;
    cost = findcost(v,n,high,psum,ssum);
    if(currentcost>cost){
      currentcost = cost;
      low = high;
    }else{
      break;
    }
  }

  while((high-low)>1){
    mid = (low+high)/2;
    cost = findcost(v,n,mid,psum,ssum);

    if(cost>currentcost){
      high = mid-1;
    }else{
      low = mid;
      currentcost = cost;
      //cout << currentcost << " " << low << '\n';
    }
  }

  cout << currentcost%M << '\n';
}


int32_t main(){
  solve();
  return 0;
}