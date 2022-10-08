/*Kmp search requires an array known as lps(longest prefix which is 
also suffix*/
#include<bits/stdc++.h>
//Code by Brotin..
using namespace std;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void computeLPSArray(string pat, int M, int* lps)
{
   
    int len = 0;
 
    lps[0] = 0; 
 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpsearch(string txt,string pat){
	int N=txt.size();
	int M=pat.size();
	int lps[M];
	computeLPSArray(pat,M,lps);
 
    int i = 0;
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            cout<<"Found pattern at index "<<i - j<<'\n';
            j = lps[j - 1];
        }
 
        
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}



#define ll long long
int main(){
    // fastIO();
    string txt,pat;
    cout<<"Enter the text"<<'\n';
    cin >> txt;
    cout<<"Enter the pattern"<<'\n';
    cin >> pat;
    kmpsearch(txt,pat);


}