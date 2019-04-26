/**************************************************************
 * File:    MyExceptions.h
 * Project: CMSC 341 Project 4, Spring 2016
 * Author : Original: Frank Zastawnik;Adapted by: Erich Johnson
 * Date   : 4/25/16
 * Section: 03
 * E-mail:  frankz2@umbc.edu ; ejohns6@umbc.edu
 *
 * MyExceptions Class definition was taken from project 1 of this
 * semester and then changed to fit to the project 4
 *
 *************************************************************/
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

class Exceptions {
public:

    //input:a message of why the exception was called
    //output:N/A
    //Descriptaion: sets m_message to what ever is passed
    Exceptions(std::string message){
        m_message = message;
    }

    //input:N/A
    //output:the message of why exception was calling
    //Descriptaion: gets the message
    const std::string GetMessage() {
         return(m_message);
    }

private:

    std::string m_message; //Error message.
};

#endif
