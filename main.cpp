
                                                        // Вариант 18 Чакал Семён А-03-20
#include <iostream>

#include <vector>

#include <conio.h>

#include <iomanip>
#include <string>


using namespace std;



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
svg_text(double left, double baseline, string text) {
     cout << "<text x='" << left << "' y='"<< baseline << "' >" <<text << " </text>";
}
void svg_rect(double x, double y, double width, double height,string stroke, string fill){
   cout<<" <rect x= '"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";

}

void
show_histogram_svg(const vector<size_t>& bins,double max,const size_t MAX_ASTERISK) {
    const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
      svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
    //  svg_rect(TEXT_WIDTH,0,bins[0]*BLOCK_WIDTH,BIN_HEIGHT,"red","red");

      double top = 0;
      if (max<=MAX_ASTERISK)
for (size_t bin : bins)

    {
    const double bin_width = BLOCK_WIDTH * bin;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"green","black");
    top = top+ BIN_HEIGHT;
    }
    else
    for (size_t bin : bins)

    {
    const double bin_width = BLOCK_WIDTH * bin*MAX_ASTERISK/max;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"green","black");
    top = top+ BIN_HEIGHT;
    }


    svg_end();
}

void show_histogramm_txt(vector <size_t>bins,double bin_Count,double high,const size_t MAX_ASTERISK ,char star)
{
    size_t maxCount=bins[0];

    for(int i=0; i<bin_Count; i++)
        if (bins[i]>maxCount)

            maxCount=bins[i];

    if (maxCount>MAX_ASTERISK)

        high=  static_cast<double>(MAX_ASTERISK)/(maxCount);

    else

        high=1;
    size_t n=0;
    while(maxCount)

    {
        maxCount=maxCount/10;

        n++;
    }

    size_t Bins=0;

    for(int i=0; i<bin_Count; i++)

    {
        Bins=  static_cast <size_t> (high*bins[i]);

        cout<<endl<<setw(n)<< bins[i]<<"|";

        for(int j=0; j< Bins; j++)

            cout<<star;
    }
}

void make_histogramm ( float bin_Size, double bin_Count, vector  <size_t> &bins,size_t numberCount,double min,double maxm,const auto  vec )
{
   bool flag;

    for (int i = 0; i < numberCount; i++)

    {

        flag = false;

        for (int j = 0; (j < bin_Count - 1) && !flag; j++)

        {

            auto lo = min + j * bin_Size;

            auto hi = min + (j + 1) * bin_Size;



            if (vec[i] >= lo && vec[i] < hi)

            {
                bins[j]++;

                flag = true;
            }
        }

        if (!flag)

        {
            flag = true;

            bins[bin_Count - 1]++;
        }

}
 return;

}

 vector <double> input_numbers(size_t numberCount)
 {
     vector <double> Numbers(numberCount);

     for(int i=0;i<numberCount;i++)
        cin>>Numbers[i];
            return(Numbers);
 }


  double find_minmax(double &min,double &max, const vector <double> &a, size_t numberCount )
  { min =a[1];
  max=a[1];
      for (int i=0;i<numberCount;i++)
      {
      if (a[i]>max)
        max=a[i];
        if (a[i]<min)
            min=a[i];

      }
  }

int main()

{

    const size_t SCREEN_WIDTH = 80;

    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    size_t numberCount,bin_Count;

    float bin_Size;

    bool flag = true;

    char star='*';

    double high=0;

    cerr << "numberCount=";

    cin>>numberCount;


    const auto vec= input_numbers(numberCount);
  double min,max;
     find_minmax(min,max,vec,numberCount);

    cerr << "binCount=" << endl;

    cin>>bin_Count;



    vector <size_t>bins(bin_Count);

    for (int i = 0; i < bin_Count; i++)

        bins[i] = 0;

    bin_Size = (max - min) / bin_Count;

    make_histogramm(bin_Size,bin_Count,bins,numberCount,min,max,vec);


   show_histogram_svg(bins,max, MAX_ASTERISK);


    return 0;

}
