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
#include <fstream>
using namespace std;

//constructor
Runjournal::Runjournal() {
    used = 0;
}

//helpers
//records a new run and adds to end runs[]
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

//displays all runs
void Runjournal::display() const {
    for (size_t i = 0; i < used; i++)
    {
        cout << "\nRun " << (i + 1) << ":" << runs[i] << endl;
    }
}

//finds specific run and removes it
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

//shows runs that are within a tenth of a given distance
void Runjournal::distance_view(double& d) const {
    for (size_t i = 0; i < used; i++)
    {
        if (runs[i].distance_equal(d))
        {
            cout << runs[i] << endl;
        }
    }
}

//sorts runs by time using bubble sort
void Runjournal::time_sort() {
    Runtime tmp;
    size_t loc_small;
    for (size_t i = 0; i < used; i++)
    {
        loc_small = i;
        for (size_t j = 0; j < used; j++)
        {
            if (runs[loc_small].get_time() < runs[j].get_time())
            {
                loc_small = j;
                tmp = runs[i];
                runs[i] = runs[loc_small];
                runs[loc_small] = tmp;
            }
        }
    }
}

//sorts runs by time using bubble sort
void Runjournal::distance_sort() {
    Runtime tmp;
    size_t loc_small;
    for (size_t i = 0; i < used; i++)
    {
        loc_small = i;
        for (size_t j = 0; j < used; j++)
        {
            if (runs[loc_small].get_distance() < runs[j].get_distance())
            {
                loc_small = j;
                tmp = runs[i];
                runs[i] = runs[loc_small];
                runs[loc_small] = tmp;
            }
        }
    }
}

//returns total time of all runs as MyTime object
MyTime Runjournal::total_time() const {
    MyTime tmp;
    for (size_t i = 0; i < used; i++)
    {
        tmp = tmp + runs[i].get_time();
    }
    return tmp;
}

//returns total distance of all runs as double
double Runjournal::total_distance() const {
    double x = 0;
    for (size_t i = 0; i < used; i++)
    {
        x += runs[i].get_distance();
    }
    return x;
}

//returns average pace of all runs as MyTime object
MyTime Runjournal::average_pace() const {
    MyTime tmp;
    tmp =  total_time() / total_distance();
    return tmp;
}

//saves time and distance of each run to file opened in main
void Runjournal::save(ofstream& ofs) const {
    for (size_t i = 0; i < used - 1; i++)
    {
        ofs << runs[i].get_time() << " " << runs[i].get_distance() << endl;
    }
    ofs << runs[used - 1].get_time() << " " << runs[used - 1].get_distance();   //this is w/out endl so that there isn't
                                                                                //an extra '\n' in the txt file
}