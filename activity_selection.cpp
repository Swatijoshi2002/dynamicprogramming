
#include <bits/stdc++.h>

using namespace std;
vector<int> res;
static bool compare(pair<int,int> &s1,pair<int,int>s2)
{
    if(s1.second>s2.second)
    return false;
    else return true;
}
void activity_selection(vector<int>& start,vector<int>& finish,int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({start[i],finish[i]});
    }
    sort(v.begin(),v.end(),compare);
   /* for(int i=0;i<n;i++)
    {
        cout<<v[i].second<<" ";
    }*/
    //activity selection
    res.push_back(0);
    int j=v[0].second;
    for(int i=1;i<n;i++)
    {
        
        if(v[i].first>j)
        {
            res.push_back(i);
            j=v[i].second;
         
        }
    }
     for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}
int main()
{
   int n;
   cin>>n;
   vector<int> s(n),f(n);
   for(int i=0;i<n;i++)
   {
       cin>>s[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>f[i];
   }
   activity_selection(s,f,n);
}
