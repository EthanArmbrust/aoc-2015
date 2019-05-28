#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;


int main(){
	ifstream infile("input/12.txt");
	string s;
	getline(infile, s);
	string red = ":\"red\"";
	vector<int> positions;
	vector<pair<int, int>> objects;
	vector<pair<int, int>> redzones;

	auto pos = s.find(red, 0);
	while(pos != string::npos){
		positions.push_back(pos);
		pos = s.find(red, pos+1);
	}

	stack<int> obj_start;

	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		if(c == '{'){
			obj_start.push(i);
		}
		if(c == '}'){
			int start = obj_start.top();
			obj_start.pop();
			objects.push_back(make_pair(start, i));
		}
	}

	//find redzones
	
	for(int i : positions){
		vector<pair<int,int>> possible;
		for(auto &p : objects){
			if(i > p.first && i < p.second){
				possible.push_back(p);
			}
		}

		pair<int, int> smallest(0, s.length());
		for(auto &p : possible){
			if(p.second - p.first < smallest.second - smallest.first){
				smallest = p;
			}
		}
		redzones.push_back(smallest);
	}

	int sum = 0;

	string currentNum = "";

	//for(char c : s){
	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		bool inRed = false;
		for(auto p : redzones){
			if(i > p.first && i < p.second){
				inRed = true;
			}
		}
		if(!inRed){
			if(isdigit(c) || c == '-'){
				currentNum += c;
			}
			else{
				if(currentNum != ""){
					sum += stoi(currentNum);
					currentNum = "";
				}
			}
		}
	}

	cout << sum << endl;
	return 0;
}

