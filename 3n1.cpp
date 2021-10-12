/******************************************************************************

3n+1 problems

*******************************************************************************/

#include <iostream>

using namespace std;


long get_length(long num){
	long leng = 0;

	while(num>1){
		leng++;
		if (num%2==0){
			num = num/2;
		}else{
			num = num * 3  +1;
		}
	}
	return leng+1;
}

int main(){
	long a;
	long b;
	long fir;
	long sec;

	while(cin>>a>>b){
		long max_num = 0;

		if (a<b){
			fir = a;
			sec = b;
		}else{
			fir = b;
			sec = a;
		}
		

		for (long i = fir; i<=sec ; i++){
			long tmp_len = get_length(i);
			if(tmp_len>max_num){
				max_num = tmp_len;
			}
		}

		cout << a << ' ' << b << ' ' << max_num<< endl;
	}

	return 0;
}
