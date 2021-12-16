#include <iostream>
#include <string>
#include <vector>
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1346


using namespace std;


int main(){
	int i, idx;
	char instr[1000];
	vector<char> LCS;
	
	while(gets(instr)){
		LCS.clear();
		string a (instr);
		gets(instr);
		string b (instr);
		
		cout << "a :" << a << "\n";
		cout << "b :" << b << "\n";
		
		for(i = 0; i<a.size(); i++){
			idx = b.find(a[i]);
			if (idx>=0){
				LCS.push_back(a[i]);
				b.erase(b.begin(),b.begin()+idx); 
			}
			
		}
		
		for(i = 0; i<LCS.size();i++){
			cout << LCS[i];
		}
		cout << "\nsize:" << LCS.size()<<"\n\n";
	}
	
	
}
