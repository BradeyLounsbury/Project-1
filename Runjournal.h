/**
 *      Name: Bradey Lounsbury
 *      Date: January 28, 2020
 *      Email: bl396918@ohio.edu
 *      Desc: Header file of container class Runjournal which 
 *      stores runs made from the MyTime.h and Runtime.h classes
 */
#include <iostream>
#include "Runtime.h"
#include "MyTime.h"
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class Runjournal {
    public:
    //constructor
    Runjournal();

    static const size_t CAPACITY = 200;

    //getter
    size_t get_used() const {return used;}
    
    //setter
    void set_used(const size_t& u) {used = u;}

    //helpers
    void record(Runtime& r1);

    void display();

    void find_remove(Runtime& r1);

    void distance_view(double& d);

    void time_sort();


    private:
    Runtime runs[CAPACITY];
    size_t used;
};

#endif