#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> step(vector<string> &grid);

int main(){

	ifstream infile("input/18.txt");
	string s;
	vector<string> input;

	while(getline(infile, s)){
		input.push_back(s);
	}

	for(int i = 0; i < 100; i++){
		input = step(input);
	}

	int count = 0;
	for(auto s : input){
		for(auto c : s){
			if(c == '#'){
				count++;
			}
		}
		cout << s << endl;
	}

	cout << count << endl;	

	return 0;
}

vector<string> step(vector<string> &grid){
	auto result = grid;
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[0].length(); j++){
			bool isOn = grid[i][j] == '#';
			int onCount = 0;
			for(int y = i - 1; y < i + 2; y++){
				for(int x = j - 1; x < j + 2; x++){
					if(!(x < 0 || x >= grid.size() || y < 0 || y >= grid.size() || (y == i && j == x))){
						if(grid[y][x] == '#'){
							onCount++;
						}
					}
				}
			}
			if(isOn){
				if(onCount == 2 || onCount == 3){
					result[i][j] = '#';
				}
				else{
					result[i][j] = '.';
				}
			}
			else{
				if(onCount == 3){
					result[i][j] = '#';
				}
				else{
					result[i][j] = '.';
				}
			}
		}
	}
	return result;
}
