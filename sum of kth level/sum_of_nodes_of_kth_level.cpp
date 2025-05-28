#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum(string s)
{
    ll num=0;

    for(ll i=0;i<s.size();i++)
    {
        num=num*10+(s[i]-'0');
    }
    return num;
}

int32_t main()
{
    ll n;cin>>n;
    string s;cin>>s;

    ll a=s.size();
    ll level=-1,x=0;
    vector<ll>v;
    for(ll i=0;i<a;i++)
    {
        if(s[i]=='(')level++;
        else if(s[i]==')')level--;
        else if(level==n)
        {
            string tmp;
            while(s[i]!='(' && s[i]!=')'){tmp+=s[i];i++;}
            i--;
            x+=sum(tmp);
        }
    }
    //x=accumulate(v.begin(),v.end(),0ll);
        cout<<x<<endl;
}

