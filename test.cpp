#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string key, text, ans;
    cout << "key :" << endl;
    getline(cin, key);
    cout << "text :" << endl;
    getline(cin, text);
    key.erase(std::remove_if(key.begin(), key.end(), isspace), key.end());
    text.erase(std::remove_if(text.begin(), text.end(), isspace), text.end());
    for(int i = 0; i < key.size(); i++){
        key[i] = toupper(key[i]);
    }
    for(int i = 0; i < text.size(); i++){
        text[i] = toupper(text[i]);
    }

    cout << key << endl;
    cout << text << endl;
    cout << "hi";

    system("pause");
}
