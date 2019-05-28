#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input/6.txt");
	vector<bool> line(1000, false);
	vector<vector<bool>> grid(1000, line);
	string s;

	while(getline(infile, s)){
		vector<string> input;
		stringstream ss(s);
		string temp;
		while(ss >> temp){
			input.push_back(temp);
		}
		bool toggle = input[0] == "toggle";
		if(toggle){
			auto comma = input[1].find(',');
			int startx = stoi(input[1].substr(0, comma));
			int starty = stoi(input[1].substr(comma + 1, input[1].length() - comma));

			auto comma2 = input[3].find(',');
			int endx = stoi(input[3].substr(0, comma2));
			int endy = stoi(input[3].substr(comma2 + 1, input[3].length() - comma2));
			
			for(int i = startx; i <= endx; i++){
				for(int j = starty; j <= endy; j++){
					grid[i][j] = !grid[i][j];
				}
			}
		}
		else{
			bool lightState = input[1] == "on";
			auto comma = input[2].find(',');
			int startx = stoi(input[2].substr(0, comma));
			int starty = stoi(input[2].substr(comma + 1, input[2].length() - comma));

			auto comma2 = input[4].find(',');
			int endx = stoi(input[4].substr(0, comma2));
			int endy = stoi(input[4].substr(comma2 + 1, input[4].length() - comma2));
			
			for(int i = startx; i <= endx; i++){
				for(int j = starty; j <= endy; j++){
					grid[i][j] = lightState; 
				}
			}
		}
	}

	int count = 0;
	for(int x = 0; x < grid.size(); x++){
		for(int y = 0; y < grid[0].size(); y++){
			if(grid[x][y]){
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
