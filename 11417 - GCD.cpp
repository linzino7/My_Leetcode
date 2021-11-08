#include <iostream>

using namespace std;


int GCD(int a, int b){
	
	while(a!=0 & b!=0){
		if( a > b){
			a = a % b;
		}else{
			b = b % a;
		}
//		cout << a << " " << b << "\n";
	}
	
	if(a==0){
		return b;	
	}else{
		return a;
	}
}

int main(){
	
	int n ;
	cin >> n;
	
	while(n!=0){
		int i;
		int j;
		long G=0;
		
		for(i = 1 ;i<n;i++){
			for(j= i+1;j<=n;j++){
				G+=GCD(i,j);
			}
		}
		
		cout << G <<"\n";
		
		cin >> n;
	}

}
