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
        cout << runs[i] << endl;
    }
}