#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    bool check_for_I = false;
    vector<vector<char>> table(5);
    string key = "HIKK";
    string font = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < key.size(); i++){
        if(key[i] == 'I'){
            check_for_I = true;
        }
    } 
    if(check_for_I) {
        for(int i = 0; i < key.size(); i++){
            if(key[i] == 'J'){
                key.erase(key.begin() + i);
            }
        }
    }
    else{
        for(int i = 0; i < key.size(); i++){
            if(key[i] == 'J'){
                key[i] = 'I';
                break;
            }
        }

    }

    for(int j = 0; j < key.size(); j++){
        for(int i = 1; i < key.size() - 1; i++){
            if(key[j] == key[i]) key.erase(key.begin() + i);
        }
    }

    for(int i = 0; i < key.size(); i++){                  
        for(int j = 0; j < font.size(); j++){
            if(font[j] == key[i]) font.erase(font.begin() + j);
        }
    }
    key = key + font;
    cout << key << endl;
    int j = 0;
    for (int i = 0; i < key.size(); i++) {
        table[j].push_back(key[i]);
        if (i == 4) j = 1;
        if (i == 9) j = 2;
        if (i == 14) j = 3;
        if (i == 19) j = 4;
    }
    system("pause");
}
