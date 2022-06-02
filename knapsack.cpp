#include <bits/stdc++.h>

using namespace std;
static bool compare(pair<double,double>& p1,pair<double,double>&p2)
{
    double ratio1,ratio2;
    ratio1=p1.first/p1.second;
     ratio2=p2.first/p2.second;
     if(ratio1>ratio2)
     return true;
     else return false;
}
double knapsack(vector<double> &weight,vector<double> &value,int n,int W)
{
    vector<pair<double,double>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({value[i],weight[i]});
    }
    sort(v.begin(),v.end(),compare);
    double profit=0;
    int i=0;
    while(i<n && W>0)
    {
        int va=v[i].first;
        int w=v[i].second;
        if(w<=W)
        {
            profit+=va;
            i++;
            W-=w;
        }
        else {
            double remain=W-w;
            double ratio=va/w;
            profit+=(remain*ratio);
            return profit;
        }
    }
    return  profit;
}
int main()
{
    
    int n,W;
    cin>>n;
    vector<double> weight(n);
    vector<double> value(n);
    for(int i=0;i<n;i++)
    {
       cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
       cin>>value[i];
    }
    cout<<"enter knapsack weight"<<endl;
    cin>>W;
    double ans=knapsack(weight,value,n,W);
    cout<<ans;
}
