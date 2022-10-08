/*
	This algorithm finds all occurrences of a pattern in a text in linear time.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> z_algorithm(string s){
	int n = s.size();
	vector<int> z(n, 0);
	z[0] = n;
	int L = 0, R = 0;
	int count = 0;
	for(int i = 1; i < n; i ++){
		if(i <= R){
			z[i] = min(R - i + 1, z[i - L]);
		}
		for(int j = z[i]; j + i < n; j ++){
			if(s[j] == s[i + j]) 
				z[i] ++;
			else 
				break;
		}
		if(i + z[i] - 1 > R){
			L = i, R = i + z[i] - 1;
		}
	}
	return z;
}

int main(){
	string txt = "Z Algorithm is Linear Time Search Algorithm";
	string pat = "Algo"; 
	int n = txt.size(), m = pat.size();

	vector<int> z = z_algorithm(pat + "$" + txt);

	for(int i = pat.size() + 1; i < z.size(); i ++){
		if(z[i] == pat.size()){
			cout << "Pattern found at index " << i - pat.size() - 1 << '\n'; 
		}
	}
}

/*

	Output:
	Pattern found at index 2
	Pattern found at index 34

*/


/*

	Logic: 
	if z[i] = k
	then k means => {s.substring(0, k) == s.substring(i, i + k - 1)} 
	Eg -> {
		string s = abcabcd
		z[0] = 0; XXXX 0 index didn't consider
		z[1] = 0;
		z[2] = 0;
		z[3] = 3; // s[0...2] == s[3...5]
		z[4] = 0;
		z[5] = 0; 
		z[6] = 0; 
	}
	
	So, we genrally convert text with "pattern + someImaginaryCharacter + text" and then apply
	the z algorithm to optain the above z array.
	Now, the only thing that left is checking the elements of z array to be equal to pattern size
	that simply means the pattern is found at the given index.

	Happy Coding !! 
	
*/