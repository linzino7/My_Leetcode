/*
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1345
https://blog.csdn.net/u012997373/article/details/38360523
https://blog.csdn.net/cugfjp/article/details/9104835
§¹¥þ­I¥]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m, k;
	int i, j;
	
	while(cin >> n){
		int tbl[1000001]= {0}; // if size not enough , runtime error occur.
		int num[10]={0};	
	
//		cout << n<< "\n";
		cin >> m;
//		cout << m<< "\n";
		
		for(i = 0; i<m; i++){
			cin >> num[i];
		}
		
//		for(i=0; i<m; i++){
//			cout << num[i] << " ";
//		}
//		cout << "\n";
		
		sort(num, num+m);
		
//		for(i=0; i<m; i++){
//			cout << num[i] << " ";
//		}
//		cout << "\n";
		
		
		for(i = 1; i<= n; i++){
			//cout << i << " ==\n";
			for(j =0; j<m; j++){
				// number of stone minus numbers equal zero mean Stan win,
				// because Stan didn't not reach that number and next step stan can take last numbers of stone.
				if( i >= num[j]  && tbl[i-num[j]] ==0){ // note:  >= 
					tbl[i] = 1;
					//cout <<  i << " " << j << " " << num[j] << " " << tbl[i-num[j]] << "\n";
				}
			}
		}
		
		if (tbl[n]==1){
			cout << "Stan wins" << "\n";
		}else{
			cout << "Ollie wins" << "\n";
		}
	}
	
}
