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

signed main(){
    int n;cin>>n;
    vector<int>v[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;cin>>a;
            v[i].push_back(a);
        }
    }
    for(int i=0;i<n;i++){
        if(count(v[i].begin(),v[i].end(),1)==1){
            auto index=find(v[i].begin(),v[i].end(),1)-v[i].begin();
            int x=0;
            for(int j=0;j<n;j++){
                if(v[j][index]==1){
                    x++;
                }
            }
            if(x==n){
                cout<<i<<endl;return 0;
            }
        }
    }
    cout<<"no celebrity"<<endl;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}