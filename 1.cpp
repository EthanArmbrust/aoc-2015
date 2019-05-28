#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream infile("input/1.txt");
    string s;
    getline(infile, s);

    int floor = 0;
    bool part2_done = false;

    for(unsigned i = 0; i < s.length(); i++){
        char c = s[i];
        if(c == '('){
            floor++;
        }
        else{
            floor--;
        }
        if(floor == -1 && !part2_done){
            cout << "Part 2: " << i+1 << endl;
            part2_done = true;
        }
    }

    cout << "Part 1: " << floor << endl;
    
    return 0;
}
