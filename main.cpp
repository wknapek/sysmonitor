#include <iostream>
#include "systemInfoCollector.h"
#include <memory>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
    int interval   = 0;
    if (argc == 4)
    {
        interval   = atoi(argv[2]);
        systemInfoCollector sys(argv[3]);
        auto start = chrono::high_resolution_clock::now();
        auto stop = start + chrono::seconds(atoi(argv[1]));
        while(start>stop)
        {
            sys.getSystemInfo();
            sleep(interval);
        }
    }
    else if (argc == 3)
    {
            interval   = atoi(argv[2]);
            systemInfoCollector sys;
            auto start = chrono::high_resolution_clock::now();
            auto stop = start + chrono::seconds(atoi(argv[1]));
            while(start>stop)
            {
                sys.getSystemInfo();
                sleep(interval);
            }
            cout<<"application usage sysomonior 100(time period in seconds) 10(time interval in seconds) lo(network interface)"<<endl;
    }
    else if (argc == 2)
    {
            interval   = 1;
            systemInfoCollector sys;
            auto start = chrono::high_resolution_clock::now();
            auto stop = start + chrono::seconds(atoi(argv[1]));
            while(start>stop)
            {
                sys.getSystemInfo();
                sleep(interval);
            }
            cout<<"application usage sysomonior 100(time period in seconds) 10(time interval in seconds) lo(network interface)"<<endl;
    }
    else
    {
            interval   = 1;
            systemInfoCollector sys;
            auto start = chrono::high_resolution_clock::now();
            auto stop = start + chrono::seconds(10);
            while(start<stop)
            {
                sys.getSystemInfo();
                sleep(interval);
                start = chrono::high_resolution_clock::now();
            }
            cout<<"application usage sysomonior 100(time period in seconds) 10(time interval in seconds) lo(network interface)"<<endl;
    }
    return 0;
}
