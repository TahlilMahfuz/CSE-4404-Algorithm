#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long;
typedef int lli;
#define testfsv(v) for(auto e:v){cout<<e.first<<"=> ";for(auto x:e.second){cout<<x<<" ";}cout<<endl;}cout<<endl;
#define testfs(v) for(auto e:v){cout<<e.first<<"=> "<<e.second<<endl;}cout<<endl;
#define test(v) for(auto e:v){cout<<e<<"";}cout<<endl;
#define input(v) for(auto &e:v){cin>>e;}
#define all(v) v.rbegin(),v.rend()

using namespace std;

map<char,int>mp;

bool isValid(int nx,int ny,int n,vector<vector<bool>>&visited){
    if(nx>=0 && nx<8 && ny>=0 && ny<8 && !visited[nx][ny]){
        return true;
    }
    return false;
}

int BFS(){
    string a,b;
    cin>>a>>b;
    pair<int,int>tx,x;
    int n=8;

    tx={mp[a[0]]-1,a[1]-'0'-1};//starting 
    x={mp[b[0]]-1,b[1]-'0'-1};//target

    if(x.first==tx.first && x.second==tx.second){
        return 0;
    }

    vector<vector<bool>>visited(n,vector<bool>(n,false));
    queue<pair<int,int>>q;
    q.push(x);
    visited[x.first][x.second]=true;

    int ans=0;
    while(!q.empty()){
        int size=q.size();
        ans++;

        while(size!=0){
            pair<int,int>p=q.front();
            q.pop();

            int xx=p.first;
            int yy=p.second;

            int ax[8]={2,1,2,1,-2,-1,-2,-1};    
            int ay[8]={1,2,-1,-2,-1,-2,1,2};

            for(int j=0;j<8;j++){
                int nx=xx+ax[j];
                int ny=yy+ay[j];

                if(nx==tx.first && ny==tx.second){
                    return ans;
                }

                if(isValid(nx,ny,n,visited)){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            size--;
        }
    }
    return ans;
}



signed main(){
    fio;
    int m=1;
    for(int i=97;i<97+26;i++){
        mp[(char)i]=m;m++;
    }
    // testfs(mp);
    int n;cin>>n;
    while(n--){
        int ans=BFS();
        cout<<ans<<endl;
    }

    return 0;
}