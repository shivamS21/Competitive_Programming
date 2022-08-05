#include<bits/stdc++.h>
using namespace std;
vector<string> arr(1005);
int visited[1005][1005];
int n, m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char dir[4] = {'U','D','L','R'};
int manDir[1005][1005];
bool isValid(int x, int y){
    if(x >= 0 and x < n and y >= 0 and y < m and arr[x][y]=='.') return true;
    return false;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    memset(visited, -1, sizeof(visited));
    int r, c, newx, newy, time, x, y;
    queue<pair<int,int>>monster_queue;   //for storing the cell
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j]=='A'){
                r = i;
                c = j;
            } else if(arr[i][j]=='M'){
                monster_queue.push({i, j});
                visited[i][j] = 0;
            }
        }
    } 
    //traversal of monsters and calculating the minimum time they need to reach a cell
    while(!monster_queue.empty()){
        x = monster_queue.front().first;
        y = monster_queue.front().second;
        monster_queue.pop();
        time = visited[x][y];
        for(int i = 0; i < 4; i++){
            newx = x + dx[i];
            newy = y + dy[i];
            if(isValid(newx, newy) and visited[newx][newy]==-1){
                monster_queue.push({newx, newy});
                visited[newx][newy] = time+1;
            }
        }
    }
    //traversal of man
    memset(manDir, -1, sizeof(manDir));
    queue<pair<int,int>>q;
    queue<int> d;
    int flag = 0;
    q.push({r, c});
    d.push(0);
    while(!q.empty() and !flag){
        x = q.front().first;
        y = q.front().second;
        time = d.front();
        d.pop();
        q.pop();
        if(x==0 or x==n-1 or y==0 or y==m-1){
            flag = 1;
            break;
        }
        time++;
        for(int i = 0; i < 4; i++){
            newx = x + dx[i];
            newy = y + dy[i];
            if(isValid(newx, newy) and manDir[newx][newy]==-1){
                //meaning newx and newy are not yet visited

                if(visited[newx][newy]>time or visited[newx][newy]==-1){
                    q.push({newx, newy});
                    d.push(time);
                    manDir[newx][newy]=i;
                }
            }
        }
    }

    if(!flag){
        cout<<"NO\n";
    } else{
        cout<<"YES\n"<<time<<endl;
        vector<char>path;
        while(x != r or y != c){
            int direc = manDir[x][y];
            x -= dx[direc];
            y -= dy[direc];
            path.push_back(dir[direc]);
        }
        reverse(path.begin(), path.end());
        for(char c: path)cout<<c;
    }
} 