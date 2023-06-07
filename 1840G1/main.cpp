#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c=0;
        cin>>n;
        string s;
        cin>>s;

        char curr=s[0],ans[n];
        for(int i=1;i<n;i++){
            if(curr==s[i]){
                ans[c++]=curr;
                curr=s[++i];
            }
        }
        for(int i=0;i<c;i++){
            cout<<ans[i];
        }
        cout<<endl;

    }
}
