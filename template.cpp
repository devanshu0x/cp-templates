    #include<bits/stdc++.h>
    using namespace std;
    #define sp " "
    #define nl '\n'
    #define  ll long long
    #define vi vector<int>
    #define vl vector<long long>
    #define vii vector<vector<int>>
    #define vll vector<vector<long long>>
    #define vc vector<char>
     
    template <class t1>
    void printArr(vector<t1> arr){
        for(t1 i : arr){
            cout<<i<<sp;
        }
        cout<<nl;
    }
    int modInverse(ll a,int m){
        int ans=1;
        int n=m-2;
        while(n){
            if(n&1){
                ans=(ans*1LL*a)%m;
                n--;

            }
            a=(a*1LL*a)%m;
            n/=2;
        }
        return ans;
    }
     
    void solve(){
        
    }
     
    int main(){
        int t=1;
        cin>>t;
        while(t--){
            solve();
        }
        return 0;
    }