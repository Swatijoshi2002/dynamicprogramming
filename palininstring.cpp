#include<bits/stdc++.h>
#include<string>
using namespace std;
vector<string> v;
map<string,int> m;
string str(string s,int i ,int j)
{
    string s1;
    while(i<=j)
    {
        s1.push_back(s[i]);
        i++;
    }
    m[s1]=1;
    return s1;
}

bool ispalin(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}
int solve(string s,int i,int j)
{
    if(i>j)
    return 0;
    if(i==j)
    {
         string s2=str(s,i,j);
        if(v.size()==0)
          v.push_back(s2);
       else if(m.find(s2)==m.end())
         v.push_back(s2);
         return 0;
    }
    if(ispalin(s,i,j))
    {
        string s2=str(s,i,j);
        if(v.size()==0)
          v.push_back(s2);
       else if(m.find(s2)==m.end())
         v.push_back(s2);
    }
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=1+solve(s,i,k)+solve(s,k+1,j);
        if(temp<min)
        {
            min=temp;
        }
    }
    return min;
}

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int res=solve(s,0,n);
    cout<<res;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
bool ispalin(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
    }
    return true;
}
void solve_2(vector<vector<string>>&v,vector<string>& v1,string s,int start,int end)
{
    if(start>=end)
    {
        v.push_back(v1);
        return ;
    }
    for(int i=start;i<end;i++)
    {
        if(ispalin(s,start,i))
        {
        v1.push_back(s.substr(start,i-start+1));
        solve_2(v,v1,s,i+1,end);
        v1.pop_back();
        }
    }
}
void solve(string s,int start,int end)
{
    vector<vector<string>> v;
    vector<string> v1;
    solve_2(v,v1,s,start,end);
     for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
    }
}
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    solve(s,0,n);
}

    */
