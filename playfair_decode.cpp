#include<vector>
#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
vector<vector<char>> table(5);

void table_for_check(string key){
    bool check_for_I = false;
    string font = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    for (int j = 0; j < key.size(); j++) {
        for (int i = 0; i < key.size(); i++) {
            if (i == j) continue;
            if (key[j] == key[i]) key.erase(key.begin() + i);
        }
    }
    for(int i = 0; i < key.size(); i++){
        if(key[i] == 'I'){
            check_for_I = true;
        }
    } 
    if(check_for_I) {
        for(int i = 0; i < key.size(); i++){
            if(key[i] == 'J'){
                key.erase(key.begin() + i);
                cout << key << endl;
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
    for(int i = 0; i < key.size(); i++){                  
        for(int j = 0; j < font.size(); j++){
            if(font[j] == key[i]) font.erase(font.begin() + j);
        }
    }
    key = key + font;
    int j = 0;
    for (int i = 0; i < key.size(); i++) {
        table[j].push_back(key[i]);
        if (i == 4) j = 1;
        if (i == 9) j = 2;
        if (i == 14) j = 3;
        if (i == 19) j = 4;
    }
}

string for_correct_text(string text){

    for(int i = 0; i < text.size(); i++){
        if(text[i] == 'J') text[i] = 'I';
    }
    for (int i = 0; i < text.size(); i += 2) {
        if (text[i] == text[i + 1]) {
            text.insert(i + 1, "X");
        }
    }
    if((text.size() % 2) != 0){
        text.push_back('X');
    }
    return text;

}

string check_position(char a, char b){
    string ans;
    vector<int> a_pos, b_pos;
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5; i++){
            if(table[j][i] == a) {
                a_pos.push_back(i);
                a_pos.push_back(j);
                
            }
            if(table[j][i] == b) {
                b_pos.push_back(i);
                b_pos.push_back(j);
            }
        }
    }


    // 同一個位置的問題 !!!
    if(a == 'X' && b == 'X') {
        a = table[a_pos[1]][a_pos[0] - 1];
        b = table[b_pos[1]][b_pos[0] - 1];
    }
    else if(a_pos[0] == b_pos[0]){  //他們在同一行
        if(a_pos[1] == 0){
            a = table[4][a_pos[0]];
            b = table[b_pos[1] - 1][b_pos[0]];
        }
        else if(b_pos[1] == 0){
            b = table[4][b_pos[0]];
            a = table[a_pos[1] - 1][a_pos[0]];
        }
        else {
            a = table[a_pos[1] - 1][a_pos[0]];
            b = table[b_pos[1] - 1][b_pos[0]];
        }
    }     
    else if(a_pos[1] == b_pos[1]){  //他們在同一列
        if(a_pos[0] == 0){
           a =table[a_pos[1]][4]; 
           b = table[b_pos[1]][b_pos[0] - 1];
        }
        if(b_pos[0] == 0){
           b =table[b_pos[1]][4]; 
           a = table[a_pos[1]][a_pos[0] - 1];
        }
        else{
            a = table[a_pos[1]][a_pos[0] - 1];
            b = table[b_pos[1]][b_pos[0] - 1];
        }
    }    
    else {
        a = table[a_pos[1]][b_pos[0]];
        b = table[b_pos[1]][a_pos[0]];
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;

}

int main(){
    string key, text,ans;
    cout << "key :";
    cin >> key;
    for(int i = 0; i < key.size(); i++){
        key[i] = toupper(key[i]);
    }
    cout << "text :";
    cin >> text;
    for(int i = 0; i < text.size(); i++){
        text[i] = toupper(text[i]);
    }
    table_for_check(key);
    text = for_correct_text(text);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << table[i][j] << " "; 
        }
        cout << endl;
    }

    for(int i = 0; i < text.size(); i += 2){
        ans += check_position(text[i], text[i+1]);
    }
    cout << "answer :" << ans << endl;
    system("pause");
}