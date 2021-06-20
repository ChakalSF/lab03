#include "histogram.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

void test_equally()
{
    double min = 0;
    double max = 0;
find_minmax( min, max,{1,1,1},3);

assert(min == 1);

assert(max == 1);


}

void test_negative()

{

    double min = 0;
    double max = 0;

find_minmax( min, max,{-3,-2,-1},3);

assert(min == -3);

assert(max == -1);

}
void
test_positive() {

    double min = 0;
    double max = 0;



    find_minmax(min, max,{1,2,3},3);


assert(min==1);

assert(max==3);

}

void test_alone()

{

double min = 0;

double max = 0;

find_minmax( min, max,{1},1);

assert(min == 1);

assert(max == 1);

}

void test_none()

{

double min = 0;

double max = 0;

find_minmax( min, max,{},0);

assert(min == 1);

assert(max == 2);

}
int
main() {
    test_positive();
    test_negative();
    test_equally();
     test_alone();
     test_none();

     cout<<"uspeh";
    return(0);
}
