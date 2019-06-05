#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream file;
  int last=0;
  int current;
  int i = 1;
  while (1){
    system(string("./DM").append(to_string(i)).c_str());
    file.open("log.txt");
    file >> current;
    file.close();
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
