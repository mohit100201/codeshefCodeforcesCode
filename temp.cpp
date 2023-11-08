#include <bits/stdc++.h>
using namespace std;





void solve(){
    string s;
    getline(cin,s);

     
    int n=s.size();

    if(s.size()<10){
        cout<<"hello"<<endl;
        cout<<"FALSE"<<endl;
        
        return;
    }

    
    

    if(s[0]!='0' && s[0]!='7' && s[0]!='8' && s[0]!='9' && s[0]!='+'){
        
        cout<<"FALSE"<<endl;
        return;
       
    }
    if(s[0]=='+'){
        if(s[1]!='9' && s[2]!='1' ){
            cout<<"FALSE"<<endl;
            return;
        }
        if(s[3]==' '){
            s=s.substr(4,n);

        }
        else{
            s=s.substr(3,n);

        }
        
       
    }
    else{
        s=s.substr(1,n);

    }
    

    cout<<s<<endl;


    








    
    
}
int32_t main(){

int t;
cin>>t;

while(t--){
solve();
}
return 0;
}
