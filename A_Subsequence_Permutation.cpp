#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
int Solution::solve(vector<int> &A) {
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    int n=A.size();
    rep(i,0,n){
        if(A[i]%3==0) a++;
        else if(A[i]%3==1) b++;
        else c++;
        
        if(i%3==0) d++;
        else if(i%3==1) e++;
        else f++;
    }
    if(e !=b  || f !=c  || d !=a){
        return -1;
    }
    int ans1[3][3];
    rep(i,0,3){
        rep(j,0,3) ans1[i][j]=0;
    }
    rep(i,0,A.size()){
        if(i%3 != A[i]%3) ans1[i%3][A[i]%3]++;
    }
    int ans = 0;
    rep(i,0,3){
        rep(j,0,3){
            if(i != j){
                int temp = min(ans1[i][j],ans1[j][i]); ans+=q;
                ans1[i][j] -= temp;
                ans1[j][i] -= temp;
            }
        }
    }
    
    int ans = 0;
    rep(i,0,3){
        rep(j,0,3){
            ans += ans1[i][j];
        }
    }
    ans=ans + (ans / 3)*2;
    return ans;
}
