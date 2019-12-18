#include <iostream>
#include <string>
//#include <wstring>

using namespace std;

int main() {

  char str[] = u8"Hello フルハン";
  string str1 = u8"Hello フルハン";

  cout << "Size (str): " << strlen(str) << endl;

  for(auto c:str) {
    cout << "Character (str): " << c << endl;
  }

  cout << "Size (str1): " << str1.size() << endl;

  for(auto c:str1) {
    cout << "Character (str1): " << c << endl;
  }


  cout << "Unicode UTF-8 string literal: " << str << endl;
  return 0;
}
