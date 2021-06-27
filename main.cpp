
 #include "histogram.h"
                    // Вариант 18 Чакал Семён А-03-20
#include <iostream>
#include "svg.h"
#include <vector>
 #include <curl/curl.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <string>


using namespace std;

const size_t SCREEN_WIDTH = 80;

    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
     char star='*';
     double high=0;

     string
make_info_text() {
    stringstream buffer;
    // TODO: получить версию системы, записать в буфер.
    // TODO: получить имя компьютера, записать в буфер.
    return buffer.str();
}



void find_time()
{ cerr<<"Enter name of server ";
string url;
cin>>url;
     curl_global_init(CURL_GLOBAL_ALL);
        CURL *curl = curl_easy_init();
if(curl) {
  double namelookup;
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
   CURLcode res = curl_easy_perform(curl);
    if(CURLE_OK == res) {
    res = curl_easy_getinfo(curl, CURLINFO_NAMELOOKUP_TIME, &namelookup);
    if(CURLE_OK == res) {

      printf("Time: %.1f", namelookup);

    }
  }
  curl_easy_cleanup(curl);
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


Input read_input(istream& in,bool promt)
{
     Input data;
     if (promt)
     cerr << "Enter number count: ";
     size_t number_count;
    in >> number_count;
    if (promt)
     cerr << "Enter numbers: ";

     data.numbers=input_numbers(in,number_count);
     if(promt)
     cerr<< endl<<"Enter bin_count ";
     in>>data.bin_count;
     return (data);
}

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx)
{
    size_t data_size = item_count*item_size;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    const char* items_2 = reinterpret_cast<const char*>(items);
    buffer->write(items_2, data_size);

    return(data_size);
}


     Input
download(const string& address)
 {
    stringstream buffer;
     curl_global_init(CURL_GLOBAL_ALL);
        CURL *curl = curl_easy_init();
        if(curl)
    {
  CURLcode res;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
 curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
  res = curl_easy_perform(curl);

  if (res!=0)
  {
   cerr<<curl_easy_strerror(res);
    exit(1);
  }


  curl_easy_cleanup(curl);
    }
    return (read_input(buffer, false));
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

  vector <size_t> make_histogramm ( Input name)

{ double min;
  double max;
  find_minmax(min,max,name.numbers);
double bin_Size = (max - min) / name.bin_count;


   bool flag;
 vector <size_t> bins(name.bin_count);
    for (int i = 0; i < name.bin_count; i++)

        bins[i] = 0;

    for (int i = 0; i < name.numbers.size(); i++)

    {

        flag = false;

        for (int j = 0; (j < name.bin_count - 1) && !flag; j++)

        {

            auto lo = min + j * bin_Size;

            auto hi = min + (j + 1) * bin_Size;



            if (name.numbers[i] >= lo && name.numbers[i] < hi)

            {
                bins[j]++;

                flag = true;
            }
        }

        if (!flag)

        {
            flag = true;

            bins[name.bin_count - 1]++;
        }

}
 return(bins);

}




int main(int argc, char* argv[])
{ Input name;
const char* Name = "Commander Shepard";
int year = 2154;
printf("%s was born in %d.\n", Name, year);
printf("n = %08x\n", 0x1234567);
return 0;
    if (argc>1)
    {
       name = download(argv[1]);
    }
    else
    {
        name=read_input(cin,true);
    }

       const vector <size_t>bins= make_histogramm(name);
    show_histogram_svg(bins);
    find_time();
   return 0;

}


