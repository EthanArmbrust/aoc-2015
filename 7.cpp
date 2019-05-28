#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

vector<vector<string>> set_wires(vector<vector<string>> input);
map<string, unsigned short> wires;

int main(){

	ifstream infile("input/7.txt");
	vector<vector<string>> file_input;
	string s;

	while(getline(infile, s)){
		vector<string> input;
		stringstream ss(s);
		string temp;
		while(ss >> temp){
			input.push_back(temp);
		}
		file_input.push_back(input);
	}

	while(file_input.size() > 0){
		cout << "Remaining lines: " << file_input.size() << endl;
		file_input = set_wires(file_input);
	}

	for(auto& x : wires){
		cout << x.first << ": " << x.second << endl;
	}

	//cout << wires.at("d") << endl;

	return 0;
}

vector<vector<string>> set_wires(vector<vector<string>> lines){
	vector<vector<string>> remain;

	for(auto input : lines){
		if(input.size() == 3){ //simple assign
			unsigned short value;
			bool bad = false;
			if(isdigit(input[0][0])){ //assigning literal
				value = stoi(input[0]);
			}
			else{ //assigning wire
				auto it = wires.find(input[0]);
				if(it == wires.end()){
					remain.push_back(input);
					bad = true;
				}
				else{
					value = wires.at(input[0]);
				}
			}
			if(bad){
			   	continue;
			}
			string dest = input[2];
			//check if exists already
			auto it = wires.find(dest);
			if(it != wires.end()){
				wires.at(dest) = value;
			}
			else{
				wires.emplace(dest, value);
			}
		}
		
		if(input.size() == 4){ //complement
			string source = input[1];
			string dest = input[3];
			auto it = wires.find(source);
			if(it == wires.end()){
				remain.push_back(input);
			}
			else{
				unsigned short source_val = wires.at(source);
				wires.emplace(dest, ~source_val);
			}
		}

		if(input.size() == 5){
			string source1 = input[0];
			auto it = wires.find(source1);
			if(it == wires.end() && isalpha(source1[0])){
				remain.push_back(input);
			}
			else{
				string dest = input[4];
				unsigned short source1_val;
				if(isalpha(source1[0])){
					source1_val = wires.at(source1);
				}
				else{
					source1_val = stoi(source1);
				}
				if(input[1] == "RSHIFT"){
					int shiftAmount = stoi(input[2]);
					wires.emplace(dest, source1_val>>shiftAmount);
				}
				else if(input[1] == "LSHIFT"){
					int shiftAmount = stoi(input[2]);
					wires.emplace(dest, source1_val<<shiftAmount);
				}
				else{
					string source2 = input[2];
					auto it = wires.find(source2);
					if(it == wires.end()){
						remain.push_back(input);
					}
					else{
						unsigned short source2_val = wires.at(source2);
						if(input[1] == "AND"){
							wires.emplace(dest, source1_val & source2_val);
						}
						if(input[1] == "OR"){
							wires.emplace(dest, source1_val | source2_val);
						}
					}
				}
			}
		}
	}

	return remain;
}
