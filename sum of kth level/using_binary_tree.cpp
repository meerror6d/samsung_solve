#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

char str[1050];
ll binarytree[1050];
bool visited[1050];

int main(){
    ll k;cin>>k;
    cin>>str;

    memset(binarytree,0,1050*sizeof(int));
    memset(visited,false,1050);

    ll i=1,counter=1;

    while(str[i]!='\0'){
        if(str[i]=='('){
            counter=2*counter;
            if(visited[counter])counter++;
            visited[counter]=true;
           }
        else if(str[i]==')'){
            counter/=2;
        }
        else{
            ll x=binarytree[counter];
            x=x*10+(str[i]-'0');
            binarytree[counter]=x;
        }
        i++;
    }

    ll l=1,r=1;

    while(k--){l=l*2;}

    r=l*2;
    counter=0;

    for(ll i=l;i<r;i++)counter+=binarytree[i];


    cout<<counter<<endl;
}
