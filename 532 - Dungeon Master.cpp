#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, k, L, R, C;
char D[32][32][32]; // 注意要+2 
int sL, sR, sC;
int eL, eR, eC;
queue<int> DLq; // can use struct to process
queue<int> DRq;
queue<int> DCq;
queue<int> sumq;

void printmap(){
	cout << "\n";
	for(i = 0 ; i < L; i++){
		for(j = 0 ; j <R; j++){
			for(k =0; k<C; k++){
				cout << D[i][j][k];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	
	cout << sL << " " << sR << " " << sC << "\n";
	cout << eL << " " << eR << " " << eC << "\n";
}

void clearn(){
	for(i = 0 ; i < L; i++){
		for(j = 0 ; j <R; j++){
			for(k =0; k<C; k++){
				D[i][j][k]='#';
			}
		}
	}

}

int main(){
	
	while(true){
		cin >> L;
		cin >> R;
		cin >> C;
		
		if(L==0&&R==0&&C==0)
			break;
		
		L=L+2;
		R=R+2;// 注意要+2 
		C=C+2;
		
		for(i = 0 ; i < L; i++){
			for(j = 0 ; j <R; j++){
				for(k =0; k<C; k++){
					if(i==0||j==0||k==0 ||i==(L-1)||j==(R-1)||k==(C-1)){
						D[i][j][k]='#';
					}else{
						cin >> D[i][j][k];
						if(D[i][j][k]=='S'){
							sL = i;
							sR = j;
							sC = k;
						}
						if(D[i][j][k]=='E'){
							eL = i;
							eR = j;
							eC = k;
						}
					}
				}
			}
		}
		
		//printmap();
		
		int z,x,y,sum;
		
		DLq.push(sL);
		DRq.push(sR);
		DCq.push(sC);
		sumq.push(0);
		
		
		while(true){
			
			z = DLq.front();
			x = DRq.front();
			y = DCq.front();
			sum = sumq.front();
			DLq.pop();
			DRq.pop();
			DCq.pop();
			sumq.pop();
			
			//cout <<"z: "<< z << "x:" << x << "y:" << y << "\n";
			
			if(z==eL&&x==eR&&y==eC){
				cout <<"Escaped in "<< sum<<" minute(s)."<< endl;
				break;
				
			}else if(D[z][x][y]!='#'){
				//up
				DLq.push(z);
				DRq.push(x);
				DCq.push(y+1);
				sumq.push(sum+1);
				//right
				DLq.push(z);
				DRq.push(x+1);
				DCq.push(y);
				sumq.push(sum+1);
				//left
				DLq.push(z);
				DRq.push(x-1);
				DCq.push(y);
				sumq.push(sum+1);
				//down
				DLq.push(z);
				DRq.push(x);
				DCq.push(y-1);
				sumq.push(sum+1);
				//level up
				DLq.push(z+1);
				DRq.push(x);
				DCq.push(y);
				sumq.push(sum+1);
				//level down
				DLq.push(z-1);
				DRq.push(x);
				DCq.push(y);
				sumq.push(sum+1);
				// block path
				D[z][x][y]='#';
			}
			
			if(DLq.size()==0&& DRq.size()==0 && DCq.size()==0 && sumq.size()==0){
				cout << "Trapped!"<< endl;
				break;
			}
			
		}
		
		//clearn();
		while (!DLq.empty())
		  {
			DLq.pop();
			DRq.pop();
			DCq.pop();
			sumq.pop();
		  }
	}
	
	
	
	return 0;
}
