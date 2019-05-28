#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct City{
	string name;
	vector<pair<string, int>> dest;
};

int main(){

	ifstream infile("input/9.txt");
	vector<City> cities;
	string s;
	vector<string> city_perms;
	
	while(getline(infile, s)){
		stringstream ss(s);
		vector<string> line;
		string temp;
		while(ss >> temp){
			line.push_back(temp);
		}
		string city1 = line[0];
		string city2 = line[2];
		int dist = stoi(line[4]);
		bool foundCity1 = false;
		bool foundCity2 = false;
		for(City &c : cities){
			if(c.name == city1){
				foundCity1 = true;
				c.dest.push_back(make_pair(city2, dist));
			}
			if(c.name == city2){
				foundCity2 = true;
				c.dest.push_back(make_pair(city1, dist));
			}
		}
		if(!foundCity1){
			City c = {city1, {make_pair(city2, dist)}};
			city_perms.push_back(city1);
			cities.push_back(c);
		}
		if(!foundCity2){
			City c = {city2, {make_pair(city1, dist)}};
			city_perms.push_back(city2);
			cities.push_back(c);
		}
	}

	vector<int> distances;
	
	do{
		int distance = 0;
		for(int i = 0; i < city_perms.size() - 1; i++){
			string first = city_perms[i];
			string second = city_perms[i+1];
			for(City city : cities){
				if(city.name == first){ 
					for(auto d : city.dest){
						if(d.first == second){
							distance += d.second;
						}
					}
				}
			}
		}
		distances.push_back(distance);
	} while(next_permutation(city_perms.begin(), city_perms.end()));

	cout << *min_element(distances.begin(), distances.end()) << endl;
	cout << *max_element(distances.begin(), distances.end()) << endl;

	return 0;
}
