#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main(){
	
	int nofcase=0;
	int n, s;
	int p, q;
	int i;
	vector< vector<int> > e;
	
	while(cin >> n && n!=0){
		
		e.clear();
		nofcase++;
		cin >> s;
		
		while( cin >> p && cin >>q){
			if (p ==0 &&q ==0){
				break;
			}
			vector<int> tmp;
			tmp.push_back(p);
			tmp.push_back(q);
			e.push_back(tmp);
	
		}  
		
	//	for(i = 0; i<e.size();i++){
	//		for(j=0; j<e[i].size();j++){
	//			cout << e[i][j] << " ";
	//		}
	//		cout << "\n";
	//	}
		
		int dis[n+1];
		int che[n+1];
		memset( dis, 0, (n+1)*sizeof(int) );
		memset( che, 0, (n+1)*sizeof(int) );
		
		for(i =1 ; i< n+1; i++){
			if ( i!= s) {
				dis[i] = -99999;
				che[i] = -99999;
			}	
		}
		
	//	for(k =1 ; k< n+1; k++){
	//		cout << dis[k] << " ";
	//	}
	//	cout << "\n";
		
		int check = 1;
		while(check){
			for( i =0; i< e.size(); i++){
				int A = e[i][0];
				int B = e[i][1];
				
				if (dis[A]+1 > dis[B]){
					dis[B] = dis[A] +1;
				}
			}
			
			check = 0;
			for( i = 1 ; i< n+1;i++){
				if (dis[i] != che[i]){
					check =1;
				}
				che[i] = dis[i];
			} 
			
		}
		
		int max = -99999;
		int idx = -99999;
		
		for( i =1 ; i< n+1; i++){
			//If there are several paths of maximum length, print the final place with smallest number.
			if ( dis[i] > max){
				max = dis[i];
				idx = i;
			}
		}
		
		cout  << "Case "<< nofcase << ": The longest path from " << s << " has length " << max << ", finishing at " << idx << ".\n";
		cout << "\n";
		
	}
	
	
}
