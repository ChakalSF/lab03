#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
using namespace std;
void find_minmax(double &min,double &max, const vector <double> &a);
struct Input {
    vector<double> numbers;
    size_t bin_count;
};



#endif // HISTOGRAM_H_INCLUDED
