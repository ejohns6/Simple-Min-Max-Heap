/**************************************************************
** File:    MMheap.h
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Erich Johnson
** Date:    4/25/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file is the header which has the variables and
**   the declared function names to create a Min-Max heap
**   where even rows are min and odd rows are max (starting
**   with even rows which the first row would be row 0)
**
**************************************************************/
#ifndef MMHEAP_H_INCLUDED
#define MMHEAP_H_INCLUDED


#include <iterator>
#include <ostream>
//
#include <iostream>
#include "vector"
//
#include <utility>

template <typename DataType>
class MMheap
  {
  public:
  /* Iterator for the tree */
  class iterator;

  //input:N/A
  //output:an initialized heap with an empty node and size 0
  //Descriptaion: initializes a heap with an empty node and size 0
  MMheap();

  //input:the reference point of min max heap
  //output:a copy of the min max heap
  //Descriptaion: copies over the vector, size, min and max
    MMheap(const MMheap<DataType> &other);

  //input:the reference point of min max heap
  //output:a copy of the min max heap
  //Descriptaion: copies over the vector, size, min and max
  MMheap &operator=(const MMheap<DataType> &other);


  //input: N/A
  //output: N/A
  //Descriptaion: destroys the min max heap
  ~MMheap();


  //input: a data point
  //output: An ordered min max tree
  //Descriptaion: inserts the data into the last base pair and then it heapafies
  void insert(DataType data);


  //input: N/A
  //output: the size
  //Descriptaion: returns the size of the min max heap
  int size() const;

  //input: N/A
  //output: whether the heap is empty of not
  //Descriptaion: decides whether the heap is empty or not and returns that answer
  bool empty() const;

  //input: N/A
  //output: prints the list and other variables
  //Descriptaion: prints the list in an in order way and other variables
  void dump();

  //input: location
  //output: N/A
  //Descriptaion: finds whether current location is a odd or even row and then
  //flips is with its parent if it is an even row and then calls BubbleUpMax
  //or if it is a odd row then it calls BubbleUpMin
  void BubbleUp(int location);

  //input: location
  //output: N/A
  //Descriptaion: if it has a grandparent it then checks to see if the current location is lower then the
  //the grandparent location and then switches it and calls BubbleUpMin on the grandparent location
  void BubbleUpMin(int location);

  //input: location
  //output: N/A
  //Descriptaion: if it has a grandparent it then checks to see if the current location is greater then the
  //the grandparent location and then switches it and calls BubbleUpMax on the grandparent location
  void BubbleUpMax(int location);

  //input:  N/A
  //output: the data that was deleted
  //Descriptaion: deletes the min data point and then heapafies
  DataType deleteMin();

  //input: location
  //output: N/A
  //Descriptaion: finds whether current location is a odd or even row and then
  //calls BubbleDownMin if it is and if it isn't it calls BubbleDownMax
  void BubbleDown(int location);

  //input: location
  //output: N/A
  //Descriptaion: if it has a grandchild it then checks to see if the current location is lower then the
  //the grandparent location and then switches it and calls BubbleDownMin on the grandparent location
  void BubbleDownMin(int location);

  //input: location
  //output: the location of the Min of the child and grandchild
  //Descriptaion: find the min location of the child and grandchild
  int FindMinOfChildAndGrandChild(int location);

  //input:  N/A
  //output: the data that was deleted
  //Descriptaion: deletes the max data point and then heapafies
  DataType deleteMax();

  //input: location
  //output: N/A
  //Descriptaion: if it has a grandchild it then checks to see if the current location is greater then the
  //the grandparent location and then switches it and calls BubbleDownMax on the grandparent location
  void BubbleDownMax(int location);

  //input: location
  //output: the location of the max of the child and grandchild
  //Descriptaion: find the max location of the child and grandchild
  int FindMaxOfChildAndGrandChild(int location);


  //input: location in vector
  //output: whether the location is on a odd or even row
  //Descriptaion: does a math mathmatical equation to find what type of row it is on
  bool bIsEvenLevel(int positionInVector);

  //input: N/A
  //output: the min data point
  //Descriptaion: gets the min data point
  DataType getMin() const;

  //input: N/A
  //output: the max data point
  //Descriptaion: gets the max data point
  DataType getMax() const;

    private:
        std::vector<DataType> m_vector;
        int m_size;
        int m_min;
        int m_max;




};

#endif // MMHEAP_H_INCLUDED
