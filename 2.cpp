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
	vector<string> forbiddenWords = {"ab", "cd", "pq", "xy"};
	vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

	for(string str : input){
		//check for forbidden
		bool noBadWords = true;
		for(string f : forbiddenWords){
			if(str.find(f) != string::npos){
				noBadWords = false;
				break;
			}
		}
		if(noBadWords){
			int vowelCount = 0;
			for(char c : vowels){
				vowelCount += count(str.begin(), str.end(), c);
			}
			if(vowelCount >= 3){
				bool doubleLetter = false;
				for(int i = 0; i < str.length() - 1; i++){
					if(str[i] == str[i+1]){
						doubleLetter = true;
					}
				}
				if(doubleLetter){
					sum++;
				}
			}
		}
	}

	cout << sum << endl;

	return 0;
}
