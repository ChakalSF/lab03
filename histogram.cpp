#include "histogram.h"
#include <vector>
#include <iostream>


void find_minmax(double &min,double &max, const vector <double> &a )
  { if (a.size()==0)
  {
    return;
  }
       min =a[0];
  max=a[0];
      for (int i=0;i<a.size();i++)
      {
      if (a[i]>max)
        max=a[i];
        if (a[i]<min)
            min=a[i];

      }
      return;

  }
