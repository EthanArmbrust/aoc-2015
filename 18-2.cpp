#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <curses.h>

using namespace std;
vector<string> step(vector<string> &grid);

int main(){

	ifstream infile("input/18.txt");
	string s;
	vector<string> input;

	while(getline(infile, s)){
		input.push_back(s);
	}
	input[0][0] = '#';
	input[0][input.size() - 1] = '#';
	input[input.size() - 1][0] = '#';
	input[input.size() - 1][input.size() - 1] = '#';

	initscr();
	curs_set(0);

	for(int i = 0; i < 5000; i++){
		input = step(input);
		for(int j = 0; j < input.size(); j++){
			mvaddstr(j, 0, input[j].c_str());
		}
		refresh();
		this_thread::sleep_for(chrono::milliseconds(80));
	}
	getch();
    endwin();

	int count = 0;
	for(auto s : input){
		for(auto c : s){
			if(c == '#'){
				count++;
			}
		}
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
	result[0][0] = '#';
	result[0][result.size() - 1] = '#';
	result[result.size() - 1][0] = '#';
	result[result.size() - 1][result.size() - 1] = '#';

	return result;
}
