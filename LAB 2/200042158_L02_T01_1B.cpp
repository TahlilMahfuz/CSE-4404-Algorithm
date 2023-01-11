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

int solve(){
    int n=8;
    string a,b;
    cin>>a>>b;
    pair<int,int>t,x;
    t={mp[a[0]]-1,a[1]-'0'-1};
    x={mp[b[0]]-1,b[1]-'0'-1};

    if(t.first==x.first && t.second==x.second){
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
            int ax[8]={2,1,2,1,-2,-1,-2,-1};    
            int ay[8]={1,2,-1,-2,-1,-2,1,2};

            int xx=p.first;
            int yy=p.second;

            for(int j=0;j<8;j++){
                int nx=ax[j]+xx;
                int ny=ay[j]+yy;

                if(nx==t.first && ny == t.second){
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
    int p=1;
    for(int i=97;i<97+26;i++){
        mp[char(i)]=p;
        p++;
    }
    // testfs(mp);
    int t;
    cin>>t;
    while(t--){
        int ans=solve();
        cout<<ans<<endl;
    }

    return 0;
}