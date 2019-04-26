//#include <tgmath.h>

#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <cstdlib>
using namespace std;

int main(){
  int postionInVector = 90;
  int temp = int(floor(log(double(postionInVector))/log(2.0))) % 2;
  return 0;
}
