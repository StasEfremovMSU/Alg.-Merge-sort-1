#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>

#define NU 80000

using namespace std;
 long int co  = 0; int stop = 0; int step = 10000;
int NUM = NU;
vector <long int> ba;
vector <long int> a;


void merge(long int l, long int r) {
    if (r == l)
        return;
    if (r - l == 1) {
        if (a[r] < a[l])
            {swap(a[r], a[l]);
            co+=2;
            }
        return;
    }

    int m = (r + l) / 2;

    merge(l, m);

    merge(m + 1, r);

    long int buf[NUM];

    long int xl = l;
    long int xr = m + 1;
    long int cur = 0;

    while (r - l + 1 != cur) {
        if (xl > m)
            {
                buf[cur++] = a[xr++]; co+=2;
            }
        else{ co++; if (xr > r)
            {
                buf[cur++] = a[xl++]; co+=2;
            }

            else { co++;
                if (a[xl] > a[xr])
                    {buf[cur++] = a[xr++]; co+=2;}
                else
                    {buf[cur++] = a[xl++]; co+=2;}
                }
            }

    }
    for (int i = 0; i < cur; i++)
        {a[i + l] = buf[i]; co+=2;}

}


int main()
{
    ofstream fout("cppstudio.txt");

    a.reserve(NU+5);
    ba.reserve(NU+5);

    cout << " start massiv base" << endl;

    for (int i = 0; i < NUM; i++)
    {
       /// a.push_back  (i);
        ba.push_back  (i);
       /// cout << ba[i]<< " ";

    }
    cout << endl;
    random_shuffle(ba.begin(), ba.end());

    do
    {
        stop =0;

       /* LARGE_INTEGER timerFrequency, timerStart, timerStop;
        QueryPerformanceFrequency(&timerFrequency);
        QueryPerformanceCounter(&timerStart);*/

        /// Сортировка
        co = 0;
        for (int i=0; i < NUM; i++ )
        {
            a[i] = ba [i];
            /// cout << a[i] << " ";
        }

        merge(0, NUM - 1);

       ///cout << " hey "<< endl;
        fout << co << "    " << NUM<< endl;

        /*QueryPerformanceCounter(&timerStop);
        double const t( static_cast<double>( timerStop.QuadPart -
        timerStart.QuadPart ) / timerFrequency.QuadPart );*/

        //cout << "Time is " << t << " seconds." << endl;
        cout << "co  " << co << " num " << NUM << endl;

        ///cout << " Time " << ( timeGetTime()- cl ) << endl;
        ///cout << " Number of operation = " << c << endl ;
        NUM = NUM *0.75;
        a.~vector<long int> ();

    } while (NUM > 5);

    fout.close();

    return 0;
}
