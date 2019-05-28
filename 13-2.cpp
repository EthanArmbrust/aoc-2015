#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
    string name;
    map<string, int> prefs;
};

int main(){

    ifstream infile("input/13.txt");
    string s;
    vector<Person> people;
    vector<string> names;


    while(getline(infile, s)){
        vector<string> line;
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            line.push_back(temp);
        }

        string name = line[0];
        bool positive = line[2] == "gain";
        int amount = positive ? stoi(line[3]) : 0 - stoi(line[3]);
        string neighbor = line[10];
        neighbor.pop_back();

        bool person_exists = false;

        for(Person &p : people){
            if(name == p.name){
                person_exists = true;
                p.prefs[neighbor] = amount;
            }
        }

        if(!person_exists){
            Person p{name, {{neighbor, amount}}};
            people.push_back(p);
            names.push_back(name);
        }
    }

    for(auto &person : people){
        person.prefs["Me"] = 0;
    }
    map<string, int> mymap;
    for(auto name : names){
        mymap[name] = 0;
    }
    Person me = {"Me", mymap};
    people.push_back(me);
    names.push_back("Me");

    vector<int> amounts;

    do{
        int amt = 0;
        for(unsigned i = 0; i < names.size(); i++){
            int prev = (i + names.size() - 1) % names.size(); 
            string p = names[prev];
            int next = (i + 1) % names.size();
            string n = names[next];

            for(auto &person : people){
                if(person.name == names[i]){
                    amt += person.prefs[p];
                    amt += person.prefs[n];
                }
            }
        }
        amounts.push_back(amt);

    } while(next_permutation(names.begin(), names.end()));

    sort(amounts.begin(), amounts.end());
    cout << amounts[amounts.size() - 1] << endl;


    return 0;
}
