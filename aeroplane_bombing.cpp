#include<iostream>
using namespace std;

void func(int a[][5],int row,int col,int tmp,int &ans,int bomb,int effort){
    if(row==-1){
        if(tmp>ans)ans=tmp;
        return;
    }

    for(int i=-1;i<=1;i++){
        if(col+i<0 || col+i>4)continue;

        if(a[row][col+i]==0 || a[row][col+i]==1){
            if(bomb==0){
                func(a,row-1,col+i,tmp+a[row][col+i],ans,bomb,effort-1);
            }
            else func(a,row-1,col+i,tmp+a[row][col+i],ans,bomb,effort);
        }
        else{
            if(bomb==0){
                if(effort>0)func(a,row-1,col+i,tmp,ans,bomb,effort-1);
            }
            else func(a,row-1,col+i,tmp,ans,0,5);

        }
    }
    return;

}

int main(){
    int a[20][5],ans;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;

        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++)cin>>a[i][j];
        }

        ans=0;

        func(a,n-1,2,0,ans,1,0);

        cout<<ans<<endl;
    }

}
