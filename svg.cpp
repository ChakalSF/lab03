
#include <iostream>
#include <string>
#include <cmath>
#include "svg.h"
#include <windows.h>
#include <sstream>
#define INFO_BUFFER_SIZE 32767


void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}


void
svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text,string type) {
      cout << "<text x='" << left << "' y='"<< baseline << "' text-decoration='"<<type<<"' >" <<text << " </text>";
}
void svg_rect(double x, double y, double width, double height,string stroke, string fill){
   cout<<" <rect x= '"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";

}
string make_info_text()
{  stringstream buffer;

DWORD info=GetVersion();
DWORD mask = 0x0000ffff;
DWORD version = info & mask;
DWORD platform = info >> 16;
 mask=0x000000ff;
 DWORD version_major=version&mask;
 DWORD version_minor =version >>8;
 DWORD build=0;
 if((info & 0x40000000)==0)
 {
     build = platform;
 }
 else
 {
      build = platform;
 }
   char infoBuf[INFO_BUFFER_SIZE];
    DWORD bufCharCount = INFO_BUFFER_SIZE;
    GetUserName(infoBuf, &bufCharCount);

 buffer << "Windows v" << version_major << "." << version_minor << "(" << platform << ")"<<endl<<"ComputerName: "<<infoBuf;
 return(buffer.str());

}



void
show_histogram_svg( const vector<size_t>& bins) {
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
string type;
  bool flag1=false;
  cerr<<endl<<"Choose type of the text (none,underline ,overline,line-through) ";
         cin>>type;
         while (flag1==false)
         {



      if((type== "none")|| (type== "underline") || (type== "overline") || (type=="line-through"))
       {
          flag1=true;
       }
       else {
            cerr<<"Choose type of the text correctly ";
           cin>>type;
            }
         }


    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
      svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]),type);
    //  svg_rect(TEXT_WIDTH,0,bins[0]*BLOCK_WIDTH,BIN_HEIGHT,"red","red");

      double top = 0;
      double max=bins[0];

       for ( size_t k:bins)
        {
            if (k>max)
            max=k;
        }

      if (max<=MAX_ASTERISK)
for (size_t bin : bins)

    {
    const double bin_width = BLOCK_WIDTH * bin;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),type);
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"green","black");
    top = top+ BIN_HEIGHT;
    }
    else
    for (size_t bin : bins)

    {
    const double bin_width = BLOCK_WIDTH * bin*MAX_ASTERISK/max;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),type);
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"green","black");
    top = top+ BIN_HEIGHT;
    }
     top=top+BIN_HEIGHT;
      svg_text(TEXT_LEFT,top,make_info_text(),type);
    svg_end();
}
