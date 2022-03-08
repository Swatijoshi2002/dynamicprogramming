#include<bits/stdc++.h>
#include<string>
using namespace std;
bool ispalin(string s,int i,int j)
{
    while(i<=j)
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
    if(i>=j)
    return 0;
    if(ispalin(s,i,j))
    return 0;
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
    sring s;
    cin>>s;
    int n=s.length();
    int res=solve(s,0,n);
}
