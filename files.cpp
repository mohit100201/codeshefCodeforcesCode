#include<bits/stdc++.h>

using namespace std;

int main(){

    // string st="Mohit bhai";
    // string ans;

    // ofstream out("sample.txt");
    // out<<st;

    // ifstream in("sampleb.txt");
    // // in>>ans;
    // getline(in,ans);
    // cout<<ans<<endl;

    ofstream out;
    out.open("sample.txt");
    out<<"My Name is Mohit\n";
    out<<"My Name is Charu\n";
    out<<"My Name is Ram\n";
    out<<"My Name is Shyam\n";
    out<<"My Name is Shyam"<<endl;
    out<<"My Name is Shyam"<<endl;

    ifstream in;
    in.open("sample.txt");
    
    while(in.eof()==0){
        string st;
        getline(in,st);
        cout<<st<<endl;
    }



    return 0;
}