#include <iostream>

using namespace std;

bool check_password(string input);
void increment_string(string &input);

int main(){
	string input = "hepxcrrq";
	while(!check_password(input)){
		increment_string(input);
	}
	cout << input << endl;
	increment_string(input);
	while(!check_password(input)){
		increment_string(input);
	}
	cout << input << endl;
	return 0;
}

bool check_password(string input){
	for(char c : input){
		if(c == 'i' || c == 'o' || c == 'l'){
			return false;
		}
	}
	bool straight = false;
	for(int i = 0; i < input.length()-2; i++){
		if(input[i] == input[i+1] - 1 && input[i] == input[i+2] - 2){
			straight = true;
		}
	}
	if(!straight){
		return false;
	}
	bool firstPair = true;
	char firstC;
	for(int i = 0; i < input.length() - 1; i++){
		if(input[i] == input[i+1]){
			firstPair = true;
			firstC = input[i];
		}
	}

	if(firstPair){
		for(int i = 0; i < input.length() - 1; i++){
			if(input[i] == input[i+1] && input[i] != firstC){
				return true;
			}
		}
	}
	else{
		return false;
	}

	return false;
}

void increment_string(string &input){
	int place = input.length() - 1;
	bool carry;
	do{
		carry = false;
		input[place]++;
		if(input[place] > 'z'){
			input[place] = 'a';
			place--;
			carry = true;
		}

	} while(carry);
}
