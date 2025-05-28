#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll s=INT_MAX;

void func(ll a[][2],ll l,ll r){

    if(l==r){
           ll c=0;
            c=c+abs(a[0][0]-a[2][0])+abs(a[0][1]-a[2][1]);
            c=c+abs(a[1][0]-a[r][0])+abs(a[1][1]-a[r][1]);

            for(ll i=2;i<r;i++){
                c+=abs(a[i][0]-a[i+1][0])+abs(a[i][1]-a[i+1][1]);
                cout<<c<<endl;
            }

            s=min(s,c);
            //cout<<s<<endl;

    }
    else{

        for(ll i=l;i<=r;i++){
            swap(a[i][0],a[l][0]);
            swap(a[i][1],a[l][1]);

            func(a,l+1,r);

            swap(a[i][0],a[l][0]);
            swap(a[i][1],a[l][1]);
        }
    }

}


int main(){
    ll t=1;
    while(t<=10){
         ll n;cin>>n;
         ll a[n+2][2];
         cin>>a[0][0]>>a[0][1];
         cin>>a[1][0]>>a[1][1];

         for(ll i=2;i<n+2;i++){
            cin>>a[i][0]>>a[i][1];
         }

         s=INT_MAX;

         func(a,2,n+1);

         cout<<"# "<<t<<" "<<s<<endl;
         t++;

    }
}
