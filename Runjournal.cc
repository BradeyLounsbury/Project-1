// The implementation file for the Runjournal class
#include "Runjournal.h"
#include "Runtime.h"
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//constructor
Runjournal::Runjournal() {
    used = 0;
}

//helpers
void Runjournal::record(Runtime& r1) {
    if (used < CAPACITY)
    {
        runs[used] = r1;
        used++;
    }
    else
    {
        cout << "No room left\n";
    }
}

void Runjournal::display() {
    for (size_t i = 0; i < used; i++)
    {
        cout << "Run " << (i + 1) << ": \n" << runs[i] << endl;
    }
}

void Runjournal::find_remove(Runtime& r1) {
    for (size_t i = 0; i < used; i++)
    {
        if (runs[i] == r1)
        {
            runs[i] = runs[used - 1];
            used--;
            return;
        }
    }
    cout << "Not found" << endl;
}