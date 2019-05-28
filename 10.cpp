#include <iostream>

using namespace std;

int main(){

	string input = "1321131112";

	for(int i = 0; i < 50; i++){
		string new_input = "";
		int num_count = 1;
		char current = input[0];
		for(int j = 1; j < input.length(); j++){
			if(current == input[j]){
				num_count++;
			}
			else{
				new_input += to_string(num_count);
				new_input += current;
				num_count = 1;
				current = input[j];
			}
		}
		new_input += to_string(num_count);
		new_input += current;
		input = new_input;
		if(i == 39){
			cout << "Part 1: " << input.length() << endl;
		}
	}
	cout << "Part 2: " << input.length() << endl;
	return 0;
}
