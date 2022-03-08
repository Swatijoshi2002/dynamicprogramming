#include<iostream>
using namespace std;
 int flag1=0;
 int flag2=0;
int  solve(int a[],int key,int start,int end)
{
  while(start<end)
{
   int mid=start+end/2;
if(a[mid]==key)
{
   return mid;
}
else if(a[mid]>key)
{
  solve(a,key,start,mid-1);
}
else solve(a,key,mid+1,end);
}

 return 0;
}


  
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
   cin>>a[i];
}
 int key;
cout<<"enter key";
 cin>>key;
 int search=solve(a,key,0,n-1);
 cout<<search;
int first_index=search,last_index=search;
int index1,index2;
if(search)
   {
      while(1)
   {
  index1=solve(a,key,0,first_index-1);
   if(index1!=0)
{
first_index=index1;
}
else if(index1==0)
break;
    }
   while(1)
   {
  index2=solve(a,key,last_index+1,n-1);
   if(index2!=0)
    {
     last_index=index2;
     }
else if(index2==0)
break;
    }

    }
  cout<<first_index<<" "<<last_index;
 
return 0;
}
