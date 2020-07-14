/*
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
*/
//code
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
const int N=100005;
long long int lazy[4*N];
long long int seg[4*N];
 
void build(int low,int high,int node)
{
    if(low>high)
    return;
    if(low == high)
    {
        seg[node]=0;
        return;
    }
    int mid = low+high>>1;
    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);
    seg[node]=seg[2*node+1]+seg[2*node+2];
}
 
void update(int low,int high,int lq,int hq,int node,long long int val)
{
    if(lazy[node])
    {
        seg[node]+=(high-low+1)*lazy[node];
        if(high!=low)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(low>hq || high<lq)
    return;
    if(lq<=low && high<=hq)
    {
        seg[node]+=(high-low+1)*val;
        if(high!=low)
        {
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        return;
    }
    int mid=low+high>>1;
    update(low,mid,lq,hq,2*node+1,val);
    update(mid+1,high,lq,hq,2*node+2,val);
    seg[node]=seg[2*node+1]+seg[2*node+2];
}
 
long long int query(int low,int high,int lq,int hq,int node)
{
    if(lazy[node])
    {
        seg[node]+=(high-low+1)*lazy[node];
        if(high!=low)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(low>hq || high<lq)
    return 0;
    if(lq<=low && high<=hq)
    {
        return seg[node];
    }
    int mid=low+high>>1;
   return query(low,mid,lq,hq,2*node+1)+query(mid+1,high,lq,hq,2*node+2);
}
int main(){
    int t;
    cin>>t;
    int n,q;
    while(t--)
    {
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
        cin>>n>>q;
        int type;
        int x,y;
        long long int val;
        build(0,n-1,0);
        while(q--)
        {
            
            cin>>type;
            //printf("%dhh\n",type);
            if(type)
            {
                
                cin>>x>>y;
                cout<<query(0,n-1,x-1,y-1,0)<<"\n";
            }
            else
            {
                cin>>x>>y>>val;
                update(0,n-1,x-1,y-1,0,val);
            }
        }
         
    }
     
    return 0;
    
}