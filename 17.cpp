#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void advance(vector<int> &bin);

int main(){

	ifstream infile("input/17.txt");
	string s;
	vector<int> input;

	int nog_count = 150;

	while(getline(infile, s)){
		input.push_back(stoi(s));
	}

	vector<int> test_bin(input.size(), 0);
	int rounds = 1;
	rounds = rounds << input.size();

	int result = 0;

	for(int i = 0; i < rounds; i++){
		int sum = 0;
		for(int j = 0; j < input.size(); j++){
			sum += test_bin[j] * input[j];
		}
		if(sum == nog_count){
			result++;
		}
		advance(test_bin);
	}

	cout << result << endl;

	return 0;
}

void advance(vector<int> &bin){
	for(int i = bin.size() - 1; i >= 0; i--){
		if(bin[i] == 0){
			bin[i] = 1;
			return;
		}
		else{
			bin[i] = 0;
		}
	}
}
