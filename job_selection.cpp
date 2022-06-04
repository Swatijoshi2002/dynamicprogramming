
#include <bits/stdc++.h>

using namespace std;
static bool compare(pair<int,int>&p1 ,pair<int,int>&p2)
{
    if(p1.second>p2.second)
    return true;
    else return false;
}
void activity_selection(vector<int> &d,vector<int>& p,int n,int jobs[])
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({d[i],p[i]});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++)
    {
        cout<<v[i].second<<" ";
    }
    int profit=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=(v[i].first)-1;j>=0;j--)
        {
            if(jobs[j]==0)
            {
                jobs[j]=v[i].second;
                profit+=jobs[j];
                break;
            }
        }
    }
    cout<<profit<<" ";
    
}
int main()
{
   int n;
   cin>>n;
   vector<int> deadline(n),profit(n);
   for(int i=0;i<n;i++)
   {
       cin>>deadline[i];
   }
   int m=*max_element(deadline.begin(),deadline.end());
   int jobs[m];
   memset(jobs,0,sizeof(jobs));
   for(int i=0;i<n;i++)
   {
       cin>>profit[i];
   }
   activity_selection(deadline,profit,n,jobs);
}
