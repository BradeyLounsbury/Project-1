//Container class for Runtime objects
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


    private:
    Runtime runs[200];
    size_t used;
};

#endif