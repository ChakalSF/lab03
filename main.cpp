
 #include "histogram.h"
                    // Вариант 18 Чакал Семён А-03-20
#include <iostream>
#include "svg.h"
#include <vector>

#include <conio.h>

#include <iomanip>
#include <string>


using namespace std;




struct Input {
    vector<double> numbers;
    size_t bin_count;
};

vector <double> input_numbers( istream& in,size_t numberCount)
 {
     vector <double> Numbers(numberCount);

     for(int i=0;i<numberCount;i++)
        in>>Numbers[i];
            return(Numbers);
 }


Input read_input(istream& in)
{
     Input data;
     cerr << "Enter number count: ";
     size_t number_count;
    in >> number_count;
     cerr << "Enter numbers: ";

     data.numbers=input_numbers(in,number_count);
     cerr<< endl<<"Enter bin_count ";
     in>>data.bin_count;
     return data;
}


void findmax(vector <size_t> &bins,double &max1)
{

    for ( size_t k:bins)
        {
            if (k>max1)
            max1=k;
        }
       return;
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

void make_histogramm ( float bin_Size, double bin_Count, vector  <size_t> &bins,double min,double max,const auto  vec )
{
   bool flag;

    for (int i = 0; i < vec.size(); i++)

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




int main()

{ setlocale(LC_ALL,"russian");

    const size_t SCREEN_WIDTH = 80;

    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    size_t numberCount,bin_Count;

    float bin_Size;

    bool flag = true;

    char star='*';

    double high=0;
    double max1;

    Input name;
    name=read_input(cin);

  double min,max;
     find_minmax(min,max,name.numbers);
    vector <size_t>bins(name.bin_count);

    for (int i = 0; i < name.bin_count; i++)

        bins[i] = 0;

    bin_Size = (max - min) / name.bin_count;


    make_histogramm(bin_Size,name.bin_count,bins,min,max,name.numbers);
    findmax(bins,max1);
    show_histogram_svg(bins,max1, MAX_ASTERISK);
   return 0;

}
