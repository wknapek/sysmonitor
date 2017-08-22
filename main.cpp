#include <iostream>
#include "cpuInfoCollector.h"
#include "RAMCollector.h"
#include "netStat.h"
#include <unistd.h>
#include "systemInfoCollector.h"

using namespace std;

int main()
{
    cpuInfoCollector cpu;
    RAMCollector ram;
    netStat net;
    systemInfoCollector sys;

    while(1)
    {
        //cout << ram.Get_usage() <<endl;
        //cout << ram.Get_free() <<endl;
        //cout << ram.Get_percent_Free() <<endl;
        //cout << ram.Get_Percent_Usage() <<endl;
        sys.getSystemInfo();
        sleep(4);
    }
    cout << "Hello world!" << endl;
    return 0;
}
