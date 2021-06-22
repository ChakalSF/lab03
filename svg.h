#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;

 void svg_begin(double width, double height);
 void svg_end();
 void svg_text(double left, double baseline, string text,string type);
void svg_rect(double x, double y, double width, double height,string stroke, string fill);
void show_histogram_svg(const vector<size_t>& bins,double max,const size_t MAX_ASTERISK);

#endif // SVG_H_INCLUDED
