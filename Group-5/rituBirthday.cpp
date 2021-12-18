#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
   int n,m;
   cin>>n;
   int pile_A[n];

   for(int i=0;i<n;i++)
   {
       cin>>pile_A[i];
   }

   cin>>m;
   int pile_B[m];

   for(int j=0;j<m;j++)
   {
       cin>>pile_B[j];
   }

   int i=0,j=0;
   int arr[n+m];

   while(i<n && j<m)
   {
       if(pile_A[i]>=pile_B[j])
       arr[i+j]=pile_B[j++];
       else
       arr[i+j]=pile_A[i++];
       
   }

   while(i<n)
   {
       arr[m+i]=pile_A[i++];
   }
   while(j<m)
   {
        arr[n+j]=pile_B[j++];
   }
    
    cout<<arr[(n+m)/2+1]<<endl;

    return 0;
}