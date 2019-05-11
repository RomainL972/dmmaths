#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream file;
  int last=0;
  int current;
  stringstream ss;
  for(int i = 1; i < 30; i++) {
    ss << "./DM " << to_string(i);
    system(ss.str().c_str());
    file.open("log.txt");
    file >> current;
    file.close();
    ss = stringstream();
    cout << to_string(i) << " : " << current << endl;

    if(current != last*2+1) {
      cout << "FATAL ERROR THAT YOU PROBABLY ALREADY KNOW OF" << endl;
      return -1;
    }
    last = current;
  }
  return 0;
}
