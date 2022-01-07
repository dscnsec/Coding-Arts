#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findMedian(vector<ll> &pileA, vector<ll> &pileB)
{
    ll size_pile_A = pileA.size(), size_pile_B = pileB.size();
    ll totalMid=(size_pile_A+size_pile_B-1)/2;
    ll lower=0, upper=min(totalMid,size_pile_A);
    while(lower<upper)
    {
        ll midA=(lower+upper)/2;
        ll midB=totalMid-midA;
        if(pileA[midA]<pileB[midB])
            lower =midA+1;
        else
            upper=midA;
    }
    return max(lower>0?pileA[lower-1]:INT_MIN,totalMid-lower>=0?pileB[totalMid-lower]:INT_MIN);
}

int main()
{
    ll size_pile_A, size_pile_B;
    cin>>size_pile_A;
    vector<ll> pileA(size_pile_A);
    for(ll i=0; i<size_pile_A; i++)
        cin>>pileA[i];
    cin>>size_pile_B;
    vector<ll> pileB(size_pile_B);
    for(ll i=0; i<size_pile_B; i++)
        cin>>pileB[i];
    if(size_pile_A>size_pile_B)
    cout<<findMedian(pileB,pileA);
    else
    cout<<findMedian(pileA,pileB);
    return 0;
}
// Time Complexity - O(log(min(n,m)))
// Space Complexity - O(1). 
