/**
 *      Name: Bradey Lounsbury
 *      Date: January 28, 2020
 *      Email: bl396918@ohio.edu
 *      Desc: Implementation file of "Runjournal.h" 
 */
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
        cout << "\nRun " << (i + 1) << ":" << runs[i] << endl;
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

void Runjournal::distance_view(double& d) {
    for (size_t i = 0; i < used; i++)
    {
        if (runs[i].distance_equal(d))
        {
            cout << runs[i] << endl;
        }
    }
}

void Runjournal::time_sort() {
    Runtime tmp;
    size_t loc_small;
    for (size_t i = 0; i < used - 1; i++)
    {
        loc_small = i;
        for (size_t j = 0; j < used; j++)
        {
            if (runs[i].get_time() < runs[loc_small].get_time())
            {
                loc_small = j;
            }
            tmp = runs[i];
            runs[i] = runs[loc_small];
            runs[loc_small] = tmp;
        }
    }
}