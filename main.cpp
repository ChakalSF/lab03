

#include <iostream>

#include <vector>                            // Вариант 18 Чакал Семён А-03-20

#include <conio.h>

#include <iomanip>
#include <string>


using namespace std;




void show_histogramm_txt(vector <size_t>bins,double bin_Count,double high,const size_t MAX_ASTERISK ,char star)
{
    size_t maxCount=bins[0]; // Объявляем условно максимальное количество оценок в одном столбце гистрограммы

    for(int i=0; i<bin_Count; i++)  //Находим этот максимум в цикле

        if (bins[i]>maxCount)

            maxCount=bins[i];

    if (maxCount>MAX_ASTERISK) // Находим коэффициент масштабирования ,если оно не требуется коэффициент остается равным 1

        high=  static_cast<double>(MAX_ASTERISK)/(maxCount);

    else

        high=1;
    size_t n=0;  //счетчик количества цифр в maxCount

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

    for (int i = 0; i < numberCount; i++)     //Заполняем корзины количеством оценок,соответствующих данной корзине

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

    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1; //максимальное количество звездочек ,помещающихся в столбце гистограммы

    size_t numberCount,bin_Count;

    float bin_Size;

    bool flag = true;

    char star='*';

    double high=0;

    cerr << "numberCount=";

    cin>>numberCount; //Вводим количество чисел(оценок)


    const auto vec= input_numbers(numberCount);  //Объявляем  вектор для хранения оценок

  double min,max;
     find_minmax(min,max,vec,numberCount);

    cerr << "binCount=" << endl;

    cin>>bin_Count; //Вводим количество корзин



    vector <size_t>bins(bin_Count); //Объявляем вектор для хранения оценок в корзинах

    for (int i = 0; i < bin_Count; i++)

        bins[i] = 0;

    bin_Size = (max - min) / bin_Count;

    make_histogramm(bin_Size,bin_Count,bins,numberCount,min,max,vec); // Функция формирования гистограммы

   show_histogramm_txt(bins,bin_Count,high,MAX_ASTERISK,star);



    return 0;

}
