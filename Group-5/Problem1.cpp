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

   int i=0,j=0,count=(n+m)/2+1,ans=0;
   while(count--)
   {
        if(i<n && j<m)
        {
            if(pile_A[i]>pile_B[j])
            {
                ans=pile_B[j];
                j++;
            }
            else
            {
                ans=pile_A[i];
                i++;
            }
        }
        else
        {
            if(i>=n)
            ans=pile_B[j++];
            else
            ans=pile_A[i++];
        }
   }

   cout<<ans<<endl;
    return 0;
}
