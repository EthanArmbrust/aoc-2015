#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int boss_hp = 104;
int boss_dam = 8;
int boss_arm = 1;

bool battleSim(int hp, int dam, int arm);

struct Item{
	string name;
	int cost;
	int damage;
	int armor;
};

int main(){

	int player_hp = 100;

	Item d{"Dagger", 8, 4, 0};
	Item s{"Shortsword", 10, 5, 0};
	Item w{"Warhammer", 25, 6, 0};
	Item l{"Longsword", 40, 7, 0};
	Item g{"Greataxe", 74, 8, 0};

	Item le{"Leather", 13, 0, 1};
	Item ch{"Chainmail", 31, 0, 2};
	Item sp{"Splintmail", 53, 0, 3};
	Item bd{"Bandedmail", 75, 0, 4};
	Item pl{"Platemail", 102, 0, 5};

	Item dm1{"Damage +1", 25, 1, 0};
	Item dm2{"Damage +2", 50, 2, 0};
	Item dm3{"Damage +3", 100, 3, 0};
	Item df1{"Defense +1", 20, 0, 1};
	Item df2{"Defense +2", 40, 0, 2};
	Item df3{"Defense +3", 80, 0, 3};

	Item no{"NO_ITEM", 0, 0, 0};

	vector<Item> weapons{d,s,w,l,g};
	vector<Item> armors{no, le, ch, sp, bd, pl};
	vector<Item> rings{dm1, dm2, dm3, df1, df2, df3};
    
    vector<vector<Item>> ring_combos;
    
    vector<Item> empty_v{};
    ring_combos.push_back(empty_v);
    
    for(auto r : rings){
        vector<Item> one{r};
        ring_combos.push_back(one);
    }
    for(int x = 0; x < rings.size(); x++){
        for(int y = x + 1; y < rings.size(); y++){
            vector<Item> two{rings[x], rings[y]};
            ring_combos.push_back(two);
        }
    }
    
    int maxGold = INT_MIN;
    string weapon_name;
    string armor_name;
    vector<string> ring_names;

	for(int i = 0; i < weapons.size(); i++){
		//select weapon
		Item weapon = weapons[i];
		for(int j = 0; j < armors.size(); j++){
			//select armor
			Item armor = armors[j];
            for(auto rv : ring_combos){
                int player_damage = weapon.damage;
                int player_armor = armor.armor;
                int goldCost = weapon.cost + armor.cost;
                for(auto r : rv){
                    player_damage += r.damage;
                    player_armor += r.armor;
                    goldCost += r.cost;
                }
                if(!battleSim(player_hp, player_damage, player_armor)){
                    cout << "Weapon: " << weapon_name << endl;
                    cout << "Armor: " << armor_name << endl;
                    for(auto r : ring_names){
                        cout << "Ring: " << r << endl;
                    }
	
                    cout << goldCost << endl;
                    if(goldCost > maxGold){
                        maxGold = goldCost;
                        weapon_name = weapon.name;
                        armor_name = armor.name;
                        ring_names.clear();
                        for(auto r : rv){
                            ring_names.push_back(r.name);
                        }
                        
                    }
                }
            }
		}
	}
	cout << "Weapon: " << weapon_name << endl;
    cout << "Armor: " << armor_name << endl;
    for(auto r : ring_names){
        cout << "Ring: " << r << endl;
    }
	
	cout << maxGold << endl;

    return 0;
}

//Returns true if player wins, false otherwise

bool battleSim(int hp, int dam, int arm){
	bool playersTurn = true;
	int b_hp = boss_hp;
	while(hp > 0 && b_hp > 0){
		if(playersTurn){
			int damage_amount = dam - boss_arm > 1 ? dam - boss_arm : 1;
			b_hp -= damage_amount;
		}
		else{
			int damage_amount = boss_dam - arm > 1 ? boss_dam - arm : 1;
			hp -= damage_amount;
		}
		if(playersTurn){
		}
		else{
		}
		playersTurn = !playersTurn;
	}
	return !playersTurn;
}
