/** Note:
 * This program uses some C++11 features,
 * so to compile this program should add argument -std=c++11
 * @param argv[0]: the process name
 * @param argv[1]: the cypher key <- it must required
 */
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<tuple>

std::pair<int, int> find_pos(const std::vector< std::vector<char> >& table, char c);
int create_playfair_table(std::vector< std::vector<char> >& table, std::string key);
std::string encrypt(const std::vector< std::vector<char> >& table, std::string message, std::string program);

int main(int argc, char *argv[]) {
  // If no argument, exit the program
  if( argc == 1 ) {
    std::cout << "The porgram should be given a argument as key" << std::endl;
    return 0;
  }
  std::string message, input, program(argv[0]), key(argv[1]);
  std::vector< std::vector<char> > table(5);
  while(getline(std::cin, input)) {
    message += input;
  }
  // Convert key to upper case
  std::transform(key.begin(), key.end(), key.begin(), ::toupper);
  std::transform(message.begin(), message.end(), message.begin(), ::toupper);
  message.erase( // Remove spaces from string
                std::remove_if(message.begin(), message.end(), ::isspace),
                message.end());
  std::cout << message << std::endl;
  create_playfair_table(table, key);

  /* This block can test the table created by create_playfair_table() */
  /* for(auto& v : table) for(char& c : v) {
    static int x(0);
    std::cout << c << ' ';
    ++x;
    if(x%5 == 0) std::cout << std::endl;
  } */
  /* std::cout << message << std::endl; */
  std::cout << encrypt(table, message, program) << std::endl;
  system("pause");
  return 0;
}

std::pair<int, int> find_pos(const std::vector< std::vector<char> >& table, char c) {
  if(c == 'J') c = 'I';
  for(int i(0); i < 5; ++i) {
    for(int j(0); j < 5; ++j) {
      if(table[i][j] == c)
        return std::make_pair(i, j);
    }
  }
  return std::make_pair(-1, -1);
}
int create_playfair_table(std::vector< std::vector<char> >& table, std::string key) {
  int map[128] = {0};
  int i(0);
  for(char x : key) {
    if(x == ' ') continue;
    if(map[x] == 0)
    {
      // The case that x is 'I' or 'J' should put them together
      if(x == 'I' or x == 'J') {
        if(map['I'] == 0 and map['J'] == 0) {
          table[i/5].push_back('I');
        }
        map['I']++;
        map['J']++;
      } else {
        table[i/5].push_back(x);
        map[x]++;
      }
      i++;
    }
  }
  // Then putting the leaft char that not in the table
  for(int j='A'; j <= 'Z'; j++) {
    if(map[j] == 0) {
      if(j == 'I') {
        table[i/5].push_back('I');
        j++;
      } else {
        table[i/5].push_back(j);
      }
      i++;
    }
  }
  return 0;
}
std::string encrypt(const std::vector< std::vector<char> >& table, std::string message, std::string program) {
  std::string res;
  int sw = (program == "./hw03-encrypt" || program == "hw03-encrypt") ? 1 : 4;
  int x1, y1, x2, y2, xX, yX;
  std::tie(yX, xX) = find_pos(table, 'X');

  for(int i(0); i < message.size(); i+=2) {
    std::tie(y1, x1) = find_pos(table, message[i]);
    std::tie(y2, x2) = find_pos(table, message[i+1]);
    if(x1 == x2 and y1 == y2 or i+1 == message.size()) {
      y2 = yX, x2 = xX;
    }
    if(x1 != x2 and y1 != y2) {
      res.push_back(table[y1][x2]);
      res.push_back(table[y2][x1]);
    } else if(x1 == x2 and y1 != y2){
      res.push_back(table[(y1+sw)%5][x1]);
      res.push_back(table[(y2+sw)%5][x1]);
    } else if(y1 == y2 and x1 != x2) {
      res.push_back(table[y1][(x1+sw)%5]);
      res.push_back(table[y1][(x2+sw)%5]);
    }
  }
  return res;
}




