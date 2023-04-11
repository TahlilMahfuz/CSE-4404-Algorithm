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
    map<int,vector<int>>mp;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            mp[i].push_back(a);
        }
    }
    for(int i=0;i<mp.size();i++){
        if(count(mp[i].begin(),mp[i].end(),1)==1){
            auto index=find(mp[i].begin(),mp[i].end(),i)-mp[i].begin();
            int x=0;
            for(int j=0;j<n;j++){
                if(mp[j][i]==1){
                    x++;
                }
            }
            if(x==n){cout<<i<<" is the celebrity"<<endl;return 0;}
        }
    }
    cout<<"No celebrity exists"<<endl;
}



// signed main(){
//     int n;cin>>n;
//     vector<int>v[n];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             int a;cin>>a;
//             v[i].push_back(a);
//         }
//     }
//     for(int i=0;i<n;i++){
//         // cout<<count(v[i].begin(),v[i].end(),1)<<endl;
//         if(count(v[i].begin(),v[i].end(),1)==1){
//             int x=0;
//             for(int j=0;j<n;j++){
//                 if(v[j][i]==1){
//                     x++;
//                 }
//             }
//             // cout<<"X"<<x<<"N"<<n<<endl;
//             if(x==n){
//                 cout<<i<<" is the celebrity"<<endl;return 0;
//             }
//         }
//     }
//     cout<<"No celebrity exists"<<endl;
//     // for(auto e:v){
//     //     for(int i=0;i<n;i++){
//     //         cout<<e[i]<<" ";
//     //     }
//     //     cout<<endl;
//     // }

//     return 0;
// }