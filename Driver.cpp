/**************************************************************
** File:    Driver1.cpp
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Erich Johnson
** Date:    4/25/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   Basically the same driver as given just with just exceptions
**   added
**
**************************************************************/
#include "MMheap.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
  MMheap<int> theHeap;
  MMheap<int> theHeap2;
  vector<int> numbers;
  string filename;

  if(argc == 2)
    {
      filename = argv[1];
    }
  else
    {
      cout << "Not enough command line arguments." << endl;
      return 0;
    }

  ifstream file(filename.c_str());

  if (file.is_open())
    {
      string line;

      while(getline(file, line))
	{
	  numbers.push_back(atoi(line.c_str()));
	}
    }
  else
    {
      cout << "File was not opened." << endl;
      return 0;
    }

  cout << "*** Insert 18, 94, 74. ***" << endl;
  cout << "--------------------" << endl;
  theHeap2.insert(18);
  theHeap2.insert(94);
  theHeap2.insert(74);
  try{//just checking for exemptions
    theHeap2.dump();
  }
  catch (Exceptions &E){
    cout << "Exception: " << E.GetMessage() << endl;
  }
  cout << "--------------------" << endl;
  cout << "*** Then deleteMax. ***" << endl;
  cout << "--------------------" << endl;
  try{
    theHeap2.deleteMax();
    theHeap2.dump();
  }
  catch (Exceptions &E){
    cout << "Exception: " << E.GetMessage() << endl;
  }

  cout << "--------------------" << endl;
  cout << "*** Make the min-max heap in Figure 6.57. ***" << endl;
  cout << "--------------------" << endl;
  for(unsigned int i = 0; i<numbers.size();i++)
    {
      //cout << numbers[i] << endl;
      theHeap.insert(numbers[i]);
    }
  try{
    theHeap.dump();
  }
  catch (Exceptions &E){
    cout << "Exception: " << E.GetMessage() << endl;
  }
  cout << "--------------------" << endl;
  cout << "*** Then insert 53, 57, 13, 12, 9, 10. ***" << endl;
  cout << "--------------------" << endl;

  theHeap.insert(53);
  //theHeap.dump();
  theHeap.insert(57);
  //theHeap.dump();
  theHeap.insert(13);
  //theHeap.dump();
  theHeap.insert(12);
  //theHeap.dump();
  theHeap.insert(9);
  //theHeap.dump();
  theHeap.insert(10);

  try{
    theHeap.dump();
  }
    catch (Exceptions &E){
        cout << "Exception: " << E.GetMessage() << endl;
  }

  cout << "--------------------" << endl;
  cout << "*** Then call deleteMin 3 times. ***" << endl;
  cout << "--------------------" << endl;
  try{
    theHeap.deleteMin();
    theHeap.deleteMin();
    theHeap.deleteMin();
    theHeap.dump();
  }
    catch (Exceptions &E){
        cout << "Exception: " << E.GetMessage() << endl;
  }
  cout << "--------------------" << endl;
  cout << "*** Then call deleteMax 3 times. ***"<<endl;
  cout << "--------------------" << endl;
  try{
  theHeap.deleteMax();
  theHeap.deleteMax();
  theHeap.deleteMax();
  theHeap.dump();
  }
    catch (Exceptions &E){
        cout << "Exception: " << E.GetMessage() << endl;
  }
  cout << "--------------------" << endl;


  return 0;
}
