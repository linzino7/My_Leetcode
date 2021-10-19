/******************************************************************************
10222 - Decode the Mad man

https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1163

*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string str;
	string key = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int c = 0;
	while(cin >> str){
	    if(c>0){cout << " ";}
	    
		for(int i=0 ; i< str.size();i++){
			char k = tolower(str[i]);
			int pistion = key.find(k);
			cout << key[pistion-2];
		}
		
		c+= 1;
		
	}
	cout << endl;
}
