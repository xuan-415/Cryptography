#include<vector>
#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

vector<vector<char>> table;



void tolower(string text){
    for(int i = 0; i < text.size(); i++){
        text[i] = toupper(text[i]);
    }
}

void table_for_check(string key){
    int j = 0;
    for(int j = 0; j < key.size(); j++){
        for(int i = 1; i < key.size() - 1; i++){
            if(key[j] == key[i]) key.erase(key.begin() + i);
        }
    }
    for(int i = 0; i < key.size(); i++){
        table[j].push_back(key[i]);
        switch(i){
            case 5:
               j = 1;
               break;
            case 10:
                j = 2;
                break;
            case 15:
                j = 3;
                break;
            case 20:
                j = 4;
                break;
            case 25:
                j = 5;
                break;
        }
    }
}

void for_correct_text(string text){
    for(int j = 0; j < text.size(); j++){
        for(int i = 1; i < text.size() - 1; i++){
            if(text[j] == text[i]) text.insert(j, "X");  
        }
    }
    if((text.size() % 2) != 0){
        text.push_back('X');
    }
}

void check_position(string text){

}


int main(){
    string key, text;
    cout << "key :";
    cin >> key;
    tolower(key);
    cout << "text :";
    cin >> text;
    tolower(text);

    system("pause");
}