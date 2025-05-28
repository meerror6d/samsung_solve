#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

ll n,srcx=0,srcy=0,desx=100,desy=100,s;
ll x[10],y[10],visited[10];

ll getdis(ll srcx,ll srcy,ll desx,ll desy){
    ll x=srcx-desx;
    ll y=srcy-desy;

    ll s=abs(x)+abs(y);

    return s;

}

void func(ll cur,ll cost,ll node){
    if(node<=1){
        if(cost+getdis(x[cur],y[cur],desx,desy)<s){
            s=cost+getdis(x[cur],y[cur],desx,desy);
            return;
        }
    }

        visited[cur]=1;

        for(ll i=0;i<n;i++){
            if(visited[i]==0){
                func(i,cost+getdis(x[cur],y[cur],x[i],y[i]),node-1);
            }
        }
        visited[cur]=0;
}

int main(){
    ll t=10;
    while(t--){
        cin>>n;
        cin>>srcx>>srcy>>desx>>desy;

        for(ll i=0;i<n;i++){cin>>x[i]>>y[i];visited[i]=0;}

        s=10000000;

        for(ll i=0;i<n;i++){
            func(i,getdis(x[i],y[i],srcx,srcy),n);
        }

        cout<<"# "<<10-t<<" "<<s<<endl;



    }

}
