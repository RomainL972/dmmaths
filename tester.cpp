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
  int i = 1;
  while (1){
    ss << "./DM " << to_string(i);
    system(ss.str().c_str());
    file.open("log.txt");
    file >> current;
    file.close();
    ss = stringstream();
    cout << to_string(i) << " : " << current << endl;

    if(current != last*2+1) {
      cout << "[FATAL ERROR] Incorrect result" << endl;
      return -1;
    }
    last = current;
    i++;
  }
  return 0;
}
