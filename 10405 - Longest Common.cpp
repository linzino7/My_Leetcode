#include <iostream>
#include <string>
#include <vector>
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1346


using namespace std;


int main(){

	char instr[1000];
	
	while(gets(instr)){
	    
		string a (instr);
		gets(instr);
		string b (instr);
		
// 		cout << "a :" << a << "\n";
// 		cout << "b :" << b << "\n";
		
        int L[a.size()+1][b.size()+1];
        
        for(int i  = 0; i< a.size()+1;i++){
            for(int j = 0; j< b.size()+1; j++){
                if(i == 0 || j ==0){
                    L[i][j] = 0;
                }else if(a[i+1]== b[j+1]){
                    L[i][j] = L[i-1][j-1]+1;
                }else if (L[i-1][j]> L[i][j-1]){
                    L[i][j] = L[i-1][j];
                }else{
                    L[i][j] = L[i][j-1];
                }
            }
        }
        
        // for(int i  = 0; i< a.size()+1;i++){
        //     for(int j = 0; j< b.size()+1; j++){
        //         cout << L[i][j]<< " ";
        //     }
        //     cout << "\n";
        // }
        
        cout << L[a.size()][b.size()] << "\n";
	}
	
	
}
