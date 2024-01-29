#include <bits/stdc++.h>
using namespace std;



void search(string text,string pat){
    int n=text.size();
    int m=pat.size();

    vector<int>bad(256,-1);
    
    for(int i=0;i<m;i++){
        bad[(int)pat[i]]=i;
    }

    int s=0;

    while(s<=(n-m)){
        int j=m-1;

        while(j>=0 && pat[j]==text[s+j]) {
            j--;
        }

        if(j<0){
            cout<<"pattern found at index: "<<s<<endl;
            s+=(s+m<n)?m-bad[text[s+m]]:1;
        }
        else{
             s += max(1, j - bad[text[s + j]]); 
        }



    }

    


}

int main()
{
    string text;
    cin>>text;
    string pat;
    cin>>pat;

    int n=text.size();
    int m=pat.size();
    

   search(text,pat);

    


    return 0;
}