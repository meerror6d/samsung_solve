#include<iostream>
#define ll long long
using namespace std;

ll n,m,x,y,l;
ll a[1000][1000],visited[1000][1000];

struct node{
    ll x,y,l;
};

node q[100000];

ll f,b;

void init()
{
    f=0;b=0;
}

void push(node temp)
{
    q[b++]=temp;
}

node pop()
{
    return q[f++];
}

bool e(){
    return f==b;
}

bool valid(ll x,ll y)
{
    return (x>=0 && x<n && y>=0 && y<m);
}

bool left(ll x,ll y)
{
    return (a[x][y]==1 || a[x][y]==3 || a[x][y]==6 || a[x][y]==7);
}

bool right(ll x,ll y)
{
    return (a[x][y]==1 || a[x][y]==3 || a[x][y]==4 || a[x][y]==5);
}

bool up(ll x,ll y)
{
    return (a[x][y]==1 || a[x][y]==2 || a[x][y]==4 || a[x][y]==7);
}

bool down(ll x,ll y)
{
    return (a[x][y]==1 || a[x][y]==2 || a[x][y]==5 || a[x][y]==6);
}

ll solve(ll x,ll y,ll l)
{
    ll ans=0;
    push({x,y,l});
    visited[x][y]=1;
    while(!e())
    {
        node cur=pop();
        ll x=cur.x;
        ll y=cur.y;
        ll l=cur.l;
        if(l==0)continue;

        ans++;

        if(valid(x,y-1) && left(x,y) && right(x,y-1) && visited[x][y-1]==0)
        {
            push({x,y-1,l-1});
            visited[x][y-1]=1;
        }
        if(valid(x,y+1) && right(x,y) && left(x,y+1) && visited[x][y+1]==0)
        {
            push({x,y+1,l-1});
            visited[x][y+1]=1;
        }
        if(valid(x-1,y) && up(x,y) && down(x-1,y) && visited[x-1][y]==0)
        {
            push({x-1,y,l-1});
            visited[x-1][y]=1;
        }
        if(valid(x+1,y) && down(x,y) && up(x+1,y) && visited[x+1][y]==0)
        {
            push({x+1,y,l-1});
            visited[x+1][y]=1;
        }

    }return ans;
}

int main()
{
    ll t;cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y>>l;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++){cin>>a[i][j];visited[i][j]=0;}
        }

        if(a[x][y]>0)cout<<solve(x,y,l)<<endl;
        else cout<<0<<endl;
    }
}
