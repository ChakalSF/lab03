
 #include "histogram.h"
                    // Вариант 18 Чакал Семён А-03-20
#include <iostream>
#include "svg.h"
#include <vector>

#include <conio.h>

#include <iomanip>
#include <string>


using namespace std;





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

 vector <double> input_numbers( istream& in,size_t numberCount)
 {
     vector <double> Numbers(numberCount);

     for(int i=0;i<numberCount;i++)
        in>>Numbers[i];
            return(Numbers);
 }


int main()

{ setlocale(LC_ALL,"russian");

    const size_t SCREEN_WIDTH = 80;

    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    size_t numberCount,bin_Count;

    float bin_Size;

    bool flag = true;

    char star='*';

    double high=0;

    cerr << "numberCount=";

    cin>>numberCount;


    const auto vec= input_numbers(cin,numberCount);
  double min,max;
     find_minmax(min,max,vec,numberCount);

    cerr << "binCount=" << endl;

    cin>>bin_Count;


    vector <size_t>bins(bin_Count);

    for (int i = 0; i < bin_Count; i++)

        bins[i] = 0;

    bin_Size = (max - min) / bin_Count;


    make_histogramm(bin_Size,bin_Count,bins,numberCount,min,max,vec);
 double max1=bins[0];

    for ( size_t k:bins)
        {


        if (k>max1)
            max1=k;
        }

   show_histogram_svg(bins,max1, MAX_ASTERISK);


    return 0;

}
