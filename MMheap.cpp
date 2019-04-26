/**************************************************************
** File:    MMheap.cpp
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Erich Johnson
** Date:    4/25/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file is the cpp of a min-max heap
**
**************************************************************/
#ifndef MMheap_CPP
#define MMheap_CPP

#include <math.h>
#include <iostream>
#include "MMheap.h"
#include "MyExceptions.h"


template <typename DataType>
MMheap<DataType>::MMheap()//constructs the min max heap with a empty node and size 0
{
    DataType Dummy;
    m_vector.push_back(Dummy);
    m_size = 0;
}

template <typename DataType>
MMheap<DataType>::MMheap(const MMheap<DataType> &other)//does a deep copy of a min max heap
{
    m_vector = other.m_vector;
    m_size = other.m_size;
    if(m_size != 0){
        m_min = other.m_min;
        m_max = other.m_max;
    }
}

template <typename DataType>
MMheap<DataType>& MMheap<DataType>::operator=(const MMheap<DataType> &other)//does a deep copy of a min max heap
{
    if(this != other){
      m_vector = other.m_vector;
      m_size = other.m_size;
      if(m_size != 0){
         m_min = other.m_min;
         m_max = other.m_max;
      }
    }else{
        return(this);
    }
  /* Your code here... */
}

template <typename DataType>//deletes the vector and lets the thing do its stuff
MMheap<DataType>::~MMheap()
{
   m_vector.clear();
}


template <typename DataType>
void MMheap<DataType>::insert(DataType data)//insert a datatype into a empty root or calls another insert
{
    if(m_size == 0){
        m_min = data;
        m_max = data;
        m_vector.push_back(data);
        m_size++;
        return;
    }else{//finds if data point is the new min or max
        if(m_min > data){
            m_min = data;
        }
        if(m_max < data){
            m_max = data;
        }
    }
    m_vector.push_back(data);//pushes the data


    BubbleUp(m_vector.size()-1);//heapafies the heap


    m_size++;//increases the size

}

template <typename DataType>
void MMheap<DataType>::BubbleUp(int location){
    if(bIsEvenLevel(location) == true){//checks to see if
             if(bIsEvenLevel(location) != bIsEvenLevel(location/2) and m_vector[location] > m_vector[location/2]){
                DataType parent = m_vector[location/2];
                DataType current = m_vector[location];
                m_vector[location] = parent;
                m_vector[location/2] = current;
                //need to do this method
                BubbleUpMax(location/2);
            }else{
                //need to do this method
                BubbleUpMin(location);
            }

    }else{
       if(bIsEvenLevel(location) != bIsEvenLevel(location/2) and m_vector[location] < m_vector[location/2]){
            DataType parent = m_vector[location/2];
            DataType current = m_vector[location];
            m_vector[location] = parent;
            m_vector[location/2] = current;
            BubbleUpMin(location/2);
       }else{
            //need to do this method
            BubbleUpMax(location);
       }
    }
}

template <typename DataType>
void MMheap<DataType>::BubbleUpMin(int location){
    if(bIsEvenLevel(location) == true and bIsEvenLevel(location/2) == false and bIsEvenLevel(location/2/2) == true){
        if(m_vector[location] < m_vector[(location/2)/2]){
            DataType grandparent = m_vector[(location/2)/2];
            DataType current = m_vector[location];
            m_vector[location] = grandparent;
            m_vector[(location/2)/2] = current;
            BubbleUpMin((location/2)/2);
        }
    }
}

template <typename DataType>
void MMheap<DataType>::BubbleUpMax(int location){
    if(bIsEvenLevel(location) == false and bIsEvenLevel(location/2) == true and bIsEvenLevel(location/2/2) == false
       /*location != floor(location/2) and floor(location/2) != floor((location/2)/2) and location > 2*//*A[i] has grandparent*/){
        if(m_vector[location] > m_vector[(location/2)/2]){
            DataType grandparent = m_vector[(location/2)/2];
            DataType current = m_vector[location];
            m_vector[location] = grandparent;
            m_vector[(location/2)/2] = current;
            BubbleUpMax((location/2)/2);
        }
    }
}






template <typename DataType>
DataType MMheap<DataType>::deleteMin()//returns the size
{
    if(m_size == 0){//makes sure the heap is not empty
        throw Exceptions("The Heap is empty");
    }
    DataType MinBeforeDeletion = m_vector[1];//so we can return what was deleted
    m_vector[1] = m_vector[m_vector.size()-1];//sets the last data to slot 1
    m_size--;//decreases size
    if(m_size != 0){//checks to see if slot is not one
        m_vector.pop_back();//deletes the last slot
        BubbleDown(1);
        m_min = m_vector[1];//the new min is in slot 1
    }
    return(MinBeforeDeletion);
}

template <typename DataType>
void MMheap<DataType>::BubbleDown(int location){

    if(bIsEvenLevel(location) == true){//finds which level it is on
        BubbleDownMin(location);//if even go down min
    }else{
        BubbleDownMax(location);//if odd go down max
    }
}

template <typename DataType>
void MMheap<DataType>::BubbleDownMin(int location){
    if(int(m_vector.size()-1) >= location*2 and bIsEvenLevel(location*2) == false){//checks to see if it has a child
        int minumValueLocation = FindMinOfChildAndGrandChild(location);//finds a smaller value of the current one in the child and grandparent
        if(bIsEvenLevel(minumValueLocation) != bIsEvenLevel(location)){//checks to see if the new min value is not on the same type of level
           if(m_vector[minumValueLocation] < m_vector[location]){//checks to see if the new value is smaller than the current one
                DataType grandchild = m_vector[minumValueLocation];//replaces the values
                DataType current = m_vector[location];
                m_vector[location] = grandchild;
                m_vector[minumValueLocation] = current;
           }
            //BubbleDownMin(minumValueLocation);
        }else if(bIsEvenLevel(location) == bIsEvenLevel(minumValueLocation) and location != minumValueLocation){//checks to see if on same type of level and values are not the same
            if(m_vector[minumValueLocation] < m_vector[location]){//checks to see if new value is lower than current
                DataType grandchild = m_vector[minumValueLocation];//switchs the slots
                DataType current = m_vector[location];
                m_vector[location] = grandchild;
                m_vector[minumValueLocation] = current;
                if(m_vector[minumValueLocation] > m_vector[minumValueLocation/2]){//checks to see if current is lower then parent if it is then switch
                    DataType minumValueLocationsParent = m_vector[minumValueLocation];
                    DataType minumValueLocation = m_vector[location];
                    m_vector[minumValueLocation] = minumValueLocationsParent;
                    m_vector[minumValueLocationsParent] = minumValueLocation;
                }
            }
            BubbleDownMin(minumValueLocation);
        }
    }
}

template <typename DataType>
int MMheap<DataType>::FindMinOfChildAndGrandChild(int location){//finds the min of the child and grandchild of the location
    //Also checks to make sure they exists before see if one is smaller than the other
    int MinLocation = location;
    if(int(m_vector.size()-1) >= (location*2)){//left child
        if(m_vector[MinLocation] > m_vector[location*2]){
            MinLocation = location*2;
        }
    }
    if(int(m_vector.size()-1) > (location*2)*2){//left child's left child
       if(m_vector[MinLocation] > m_vector[(location*2)*2]){
            MinLocation = (location*2)*2;
        }
    }
    if(int(m_vector.size()-1) > (location*2)*2+1){//left child's right child
       if(m_vector[MinLocation] > m_vector[(location*2)*2+1]){
            MinLocation = (location*2)*2+1;
        }
    }


    if(int(m_vector.size()-1) >= (location*2+1)){//right child's
        if(m_vector[MinLocation] > m_vector[location*2+1]){
            MinLocation = location*2+1;
        }
    }
    if(int(m_vector.size()-1) > (location*2+1)*2){//right child's left child
       if(m_vector[MinLocation] > m_vector[(location*2+1)*2]){
            MinLocation = (location*2+1)*2;
        }
    }
    if(int(m_vector.size()-1) > (location*2+1)*2+1){//right child's right child
       if(m_vector[MinLocation] > m_vector[(location*2+1)*2+1]){
            MinLocation = (location*2+1)*2+1;
        }
    }

    return(MinLocation);
}




template <typename DataType>
DataType MMheap<DataType>::deleteMax()//deletes the max
{
    if(m_size == 0){//makes sure the heap is not empty
        throw Exceptions("The Heap is empty");
    }
    DataType MaxBeforeDeletion;
    if(m_vector[2] == m_max){//finds which slot is the max
        MaxBeforeDeletion = m_vector[2];//if slot 2 does it stuff
        m_vector[2] = m_vector[m_vector.size()-1];//replaces the value
        m_vector.pop_back();//delete the last value
        BubbleDown(2);
        m_size--;//reduce the size
        if(m_size >= 3 and m_vector[3] > m_vector[2]){//finds the new max
            m_max = m_vector[3];
        }else if(m_size >=2){//checks to see if there is a slot 2
            m_max = m_vector[2];
        }else{
            m_max = m_vector[1];
        }
    }else if(m_size >= 3){
        MaxBeforeDeletion = m_vector[3];//if slot 3 does it stuff
        m_vector[3] = m_vector[m_vector.size()-1];//replaces the value
        m_vector.pop_back();//deletes the last value
        BubbleDown(3);
        m_size--;//reduces the size
        if(m_size >= 3 and m_vector[3] > m_vector[2]){//finds the new max
            m_max = m_vector[3];
        } if(m_size >=2){//checks to see if there is a slot 2
            m_max = m_vector[2];
        }else{
            m_max = m_vector[1];
        }
    }else{//if slot 3 and 2 do not exist then delete max just deletes position 1
        MaxBeforeDeletion = m_vector[1];
        m_vector.pop_back();
        m_size--;
    }
    return(MaxBeforeDeletion);
}

template <typename DataType>
void MMheap<DataType>::BubbleDownMax(int location){
    if(int(m_vector.size()-1) >= location*2 and bIsEvenLevel(location*2) == true){//finds if it has a child
        int MaxValueLocation = FindMaxOfChildAndGrandChild(location);//finds the max of the current's childs and grandchild
        if(bIsEvenLevel(MaxValueLocation) != bIsEvenLevel(location)){//checks to see if is the child
           if(m_vector[MaxValueLocation] > m_vector[location]){//checks to see if it is greater
                DataType grandchild = m_vector[MaxValueLocation];//then switch slots
                DataType current = m_vector[location];
                m_vector[location] = grandchild;
                m_vector[MaxValueLocation] = current;
           }
            //BubbleDownMin(minumValueLocation);
        }else if(bIsEvenLevel(location) == bIsEvenLevel(MaxValueLocation) and location != MaxValueLocation){//if it is a granchild
            if(m_vector[MaxValueLocation] > m_vector[location]){//checks to see if it is greater
                DataType grandchild = m_vector[MaxValueLocation];//then switches the slots
                DataType current = m_vector[location];
                m_vector[location] = grandchild;
                m_vector[MaxValueLocation] = current;
                if(m_vector[MaxValueLocation] < m_vector[MaxValueLocation/2]){//checks to see if parent is lower then current location
                    DataType MaxValueLocationsParent = m_vector[MaxValueLocation];//if it is switch it
                    DataType MaxValueLocation = m_vector[location];
                    m_vector[MaxValueLocation] = MaxValueLocationsParent;
                    m_vector[MaxValueLocationsParent] = MaxValueLocation;
                }
            }
            BubbleDownMax(MaxValueLocation);
        }
    }
}

template <typename DataType>
int MMheap<DataType>::FindMaxOfChildAndGrandChild(int location){//finds the max of the child and grandchild of the location
    //Also checks to see if they exist before checking if they are greater than the location
    int MaxLocation = location;
    if(int(m_vector.size()-1) >= (location*2)){//left child
        if(m_vector[MaxLocation] < m_vector[location*2]){
            MaxLocation = location*2;
        }
    }
    if(int(m_vector.size()-1) > (location*2)*2){//left child's left child
       if(m_vector[MaxLocation] < m_vector[(location*2)*2]){
            MaxLocation = (location*2)*2;
        }
    }
    if(int(m_vector.size()-1) > (location*2)*2+1){//left child's right child
       if(m_vector[MaxLocation] < m_vector[(location*2)*2+1]){
            MaxLocation = (location*2)*2+1;
        }
    }


    if(int(m_vector.size()-1) >= (location*2+1)){//right child's
        if(m_vector[MaxLocation] < m_vector[location*2+1]){
            MaxLocation = location*2+1;
        }
    }
    if(int(m_vector.size()-1) > (location*2+1)*2){//right child's left child
       if(m_vector[MaxLocation] < m_vector[(location*2+1)*2]){
            MaxLocation = (location*2+1)*2;
        }
    }
    if(int(m_vector.size()-1) > (location*2+1)*2+1){//right child's right child
       if(m_vector[MaxLocation] < m_vector[(location*2+1)*2+1]){
            MaxLocation = (location*2+1)*2+1;
        }
    }

    return(MaxLocation);
}


template <typename DataType>
bool MMheap<DataType>::empty() const//tells if the tree is empty or not
{
    if(m_size == 0){//if m_size is zero then it is empty
        return(true);
    }
  return false;
}

template <typename DataType>
int MMheap<DataType>::size() const//returns the size
{
    return(m_size);
}


template <typename DataType>
DataType MMheap<DataType>::getMin() const//returns the size
{
    if(m_size == 0){//makes sure the heap is not empty
        throw Exceptions("The Heap is empty");
    }
    return(m_min);//returns the min
}


template <typename DataType>
DataType MMheap<DataType>::getMax() const//returns the size
{
    if(m_size == 0){//makes sure the heap is not empty
        throw Exceptions("The Heap is empty");
    }
    return(m_max);//returns the max
}

template <typename DataType>
bool MMheap<DataType>::bIsEvenLevel(int positionInVector) {//finds if it is on an even level
    bool OddLevel;
    if(int(floor(log(double(positionInVector))/log(2.0))) % 2 == 0){//since a binary tree increases a level the amount of leafs increase
            //by two so I did log(position)/log(2) and then floor just to make sure it goes to the lowest int and then if divisible by 2 then
            //it is an odd level if not an even level
        OddLevel = true;
    }else{
       OddLevel = false;
    }
    return(OddLevel);
}

template <typename DataType>
void MMheap<DataType>::dump()//returns the size
{
    if(m_size == 0){//makes sure the heap is not empty
        throw Exceptions("The Heap is empty");
    }
    std::cout << "---min-max heap dump---" << std::endl;
    std::cout << "Size = " << m_size << std::endl;//prints the size
    std::cout << "Minimum = " << m_min << std::endl;//prints the min data point
    std::cout << "Maximum = " << m_max << std::endl;//prints the max data point
    std::cout << "Last level is ";
    if(bIsEvenLevel(m_size) == true){//finds out which row it is
        std::cout << "even" << std::endl;
    }else{
        std::cout << "odd" << std::endl;
    }
    std::cout << "--- heap data items ---" << std::endl;
    for(unsigned int i = 0; i < m_vector.size(); i++){//prints the heap in level order
        if(i != 0){//slot 0 is a dummy node so I skipped over it
            std::cout << "H[" << (i) << "] = " << m_vector[i] << std::endl;
        }
    }
}

#endif
