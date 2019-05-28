#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input/5.txt");
	vector<string> input;

	string s;

	while(getline(infile, s)){
		input.push_back(s);
	}

	int sum = 0;

	for(string str : input){
		bool doubleLet = false;
		for(int i = 0; i < str.length() - 2; i++){
			if(str[i] == str[i+2]){
				doubleLet = true;
				break;
			}
		}
		if(doubleLet){
			bool repeat = false;
			for(int i = 0; i < str.length() - 1; i++){
				string small = str.substr(i, 2);
				for(int j = i+2; j < str.length() - 1; j++){
					string test = str.substr(j, 2);
					if(test == small){
						repeat = true;
						break;
					}
				}
			}
			if(repeat){
				sum++;
			}
		}
	}

	cout << sum << endl;

	return 0;
}
