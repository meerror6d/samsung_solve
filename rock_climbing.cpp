#include<iostream>
#define ll long long
using namespace std;

ll n,m,a[15][15],v[15][15],f=0,l=0;

void dfs(ll i,ll j){
    if(i<0 || i>=n || j<0 || j>=m)return;
    if(v[i][j])return;

    v[i][j]=1;

    if(a[i][j]==3){
        f=1;return ;
    }

    if(j+1<m && (a[i][j+1]==1 || a[i][j+1]==3) && !v[i][j+1])dfs(i,j+1);

    if(j-1>=0 && (a[i][j-1]==1 || a[i][j-1]==3) && !v[i][j-1])dfs(i,j-1);

    ll h=1;

    for(ll h=1;h<=l;h++){
        if(h<=l && i-h>=0 &&(a[i-h][j]==1 || a[i-h][j]==3) && !v[i-h][j])dfs(i-h,j);
    }

    for(ll h=1;h<=l;h++){
        if(h<=l && i+h<n &&(a[i+h][j]==1 || a[i+h][j]==3) && !v[i+h][j])dfs(i+h,j);
    }

}

int main(){
    cin>>n>>m;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)cin>>a[i][j];
    }

    for(l=0;l<n;l++){
        for(ll i=0;i<15;i++){
            for(ll j=0;j<15;j++)
                v[i][j]=0;
        }
        f=0;
        dfs(n-1,0);

        if(f){cout<<l<<endl;break;}


    }
}
