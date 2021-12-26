#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findMedian(vector<ll> &A, vector<ll> &B)
{
    ll n=A.size(),m=B.size();
    ll k=(n+m-1)/2;
    ll l=0,r=min(k,n);
    while(l<r)
    {
        ll midA=(l+r)/2;
        ll midB=k-midA;
        if(A[midA]<B[midB])
            l =midA+1;
        else
            r=midA;
    }
    return max(l>0?A[l-1]:INT_MIN,k-l>=0?B[k-l]:INT_MIN);
}

int main()
{
    ll n,m;
    cin>>n;
    vector<ll> A(n);
    for(ll i=0;i<n;i++)
        cin>>A[i];
    cin>>m;
    vector<ll> B(m);
    for(ll i=0;i<m;i++)
        cin>>B[i];
    if(n>m)
    cout<<findMedian(B,A);
    else
    cout<<findMedian(A,B);
    return 0;
}
// Time Complexity - O(log(min(n,m)))
// Space Complexity - O(1). 
