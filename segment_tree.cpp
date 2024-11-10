#include<bits/stdc++.h>
using namespace std;

class SG_TREE{
    vector<int> seg;
public:
    SG_TREE(int n){
        seg.resize(4*n+1);
    }

    void build(int ind,int low,int high, int *arr){
        if(low==high){
            seg[ind]=arr[low];
            return ;
        }
        int mid = low +(high-low)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }

    int query(int ind,int low, int high,int l,int r){
        // no overlap
        // lr Low High or Low High lr
        if(r<low || l>high) return INT_MAX;

        // complete overlap
        //l low high r
        if(low>=l && high<=r ) return seg[ind];

        // else partial overlap
        int mid=(low +high)>>1;
        int left= query(2*ind+1,low,mid,l,r);
        int right= query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int ind,int low,int high,int i,int val){
        if(low==high){ 
            seg[ind]=val;
            return ;
        }

        int mid=(low+high)>>1;
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);
        seg[ind]= min(seg[2*ind+1],seg[2*ind+2]);
    }
};