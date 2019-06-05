#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

	ifstream infile("input/17.txt");
	string s;
	vector<int> input;

	int nog_count = 150;

	while(getline(infile, s)){
		input.push_back(stoi(s));
	}

	int comb_count = 0;

	int n = input.size();

	vector<bool> v(n);
	
	for(int x = 1; x <= n; x++){

		do{
			int sum = 0;
			for(int i = 0; i < input.size(); i++){
				if(v[i]){
					sum += input[i];
				}
			}
			if(sum == nog_count){
				comb_count++;
			}

		} while(next_permutation(v.begin(), v.end()));
	}

	cout << comb_count << endl;

	return 0;
}
