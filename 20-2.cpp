#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int sum_presents(int n);

int main(){

	int input = 36000000; 

	int house_num = 1;

	//for(int i = 0; i < 10; i++){	
	while(sum_presents(house_num) < input){
		house_num++;
	}
	
	cout << house_num << endl;

    return 0;
}

int sum_presents(int n){
	int sum = 0;
	int d = (int)sqrt((double) n) + 1;
	for(int i = 1; i <= d; i++){
		if(n % i == 0){
			if(n < i * 50){
				sum += i;
			}
			if(n < (n/i) * 50){
				sum += n/i;
			}
		}
	}
	return sum * 11;
}
