#include <bits/stdc++.h>
using namespace std;

#define INT_SIZE 32
bool cmp (pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first)
    return a.second<b.second;
    return a.first>b.first;
}

int ORsum(vector<int>arr, int n)
{
	vector<pair<int,int>>v;
    for(int i=0;i<N;i++)
    {
        v.push_back({h[i],c[i]});
    }

    sort(v.begin(),v.end(),cmp);
    int time=0;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        if((temp[i].second<=M) and (temp[i].second<=(M-time)) )
        {
            sum+=temp[i].first;
            time++;
        }
    }

    return sum;
	
}


int main()
{
	
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int v;
            cin>>v;
            arr.push_back(v);
        }
        cout << ORsum(arr, n)<<"\n";
    }
    
	return 0;
}
