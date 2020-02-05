#include "ThirdTask.h"
#include "HashTable.h"
#include <fstream>
#include <chrono>
#include <windows.h>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <stdexcept>
#include <fstream>
#include <vector>

using namespace std;

int main()
{



    LARGE_INTEGER li;
    QueryPerformanceFrequency(&li);
    double PCFreq = li.QuadPart/1000.0;
    int64_t startt;
    int64_t endd;
    std::int64_t taken1 =0;
    std::int64_t taken2=0;
    std::int64_t taken3=0;
    std::int64_t taken4=0;
    std::int64_t taken5=0;
    std::int64_t taken6=0;
    std::int64_t taken7=0;
    std::int64_t taken8=0;


    int county = 0;
    int county2 =0;
    int county3 =0;
    int i=1;
    for (int n=0; n<i; n++)
    {
        county = 0;
        county2 =0;
        county3 =0;
        ifstream myfile ("master.txt");
        ifstream myfile2 ("master.txt");
        ifstream myfile3 ("master.txt");
        ifstream searc ("search.txt");
        ifstream searc2 ("search.txt");
        ifstream searc3 ("search.txt");
        ifstream myfile4 ("master.txt");
        ifstream searc4 ("search.txt");
        string line;
        /// push

        HashySlashy H;
        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (myfile.is_open())
        {
            while ( getline(myfile,line) )
            {
                H.pushy(line);
            }
            myfile.close();
        }
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken3 = endd - startt + taken3;



        trie g;
        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (myfile2.is_open())
        {
            while ( getline(myfile2,line) )
            {
                g.inse(line);
            }
            myfile2.close();
        }
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken4 = endd - startt + taken4;

        set<string> setty;
        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (myfile4.is_open())
        {
            while ( getline(myfile4,line) )
            {
                setty.insert(line);
            }
            myfile4.close();
        }
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken7 = endd - startt + taken7;


        vector<string> linea;
        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (myfile3.is_open())
        {
            while ( getline(myfile3,line) )
            {
                linea.push_back(line);
            }
            myfile3.close();
        }
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken5 = endd - startt + taken5;




        /// search

        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (searc.is_open())
        {
            while ( getline(searc,line) )
            {
                if(H.searching(line))
                    county++;
            }
            searc.close();
        }
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken1 = endd - startt + taken1;



        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (searc2.is_open())
        {
            while ( getline(searc2,line) )
            {
                if(g.finde(line))
                    county2++;
            }
            searc2.close();
        }
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken2 = endd - startt + taken2;


        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (searc3.is_open())
        {
            while ( getline(searc3,line) )
            {
                for(int j=0; j<linea.size(); j++)
                    if(linea[j]==line)
                    {
                        break;
                    }
            }
        }
        searc3.close();
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken6 = endd - startt + taken6;


        QueryPerformanceCounter(&li);
        startt = li.QuadPart;
        if (searc4.is_open())
        {
            while ( getline(searc4,line) )
            {
                if(setty.find(line)!=setty.end())
                    county3++;
            }
            searc4.close();
        }
        QueryPerformanceCounter(&li);
        endd = li.QuadPart;
        taken8 = endd - startt + taken8;



    }

    cout <<  county << endl;
    cout <<  county2 << endl;
    cout <<  county3 << endl;

    cout <<" Hash push: "<< std::setw(8) << std::fixed << " " << " " <<taken3/PCFreq/i<< std::endl;
    cout <<" trie push: "<< std::setw(8) << std::fixed << " " << " " <<taken4/PCFreq/i<< std::endl;
    cout <<" Hash search: "<< std::setw(8) << std::fixed << " " << " " <<taken1/PCFreq/i<< std::endl;
    cout <<" Trie search: "<< std::setw(8) << std::fixed << " " << " " <<taken2/PCFreq/i<< std::endl;
    cout <<" Linear Push: "<< std::setw(8) << std::fixed << " " << " " <<taken5/PCFreq/i<< std::endl;
    cout <<" Linear search: "<< std::setw(8) << std::fixed << " " << " " <<taken6/PCFreq/i<< std::endl;
    cout <<" Set Push: "<< std::setw(8) << std::fixed << " " << " " <<taken7/PCFreq/i<< std::endl;
    cout <<" Set search: "<< std::setw(8) << std::fixed << " " << " " <<taken8/PCFreq/i<< std::endl;





    return 0;
}

