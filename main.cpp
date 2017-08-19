#include <iostream>
#include "cpuInfoCollector.h"
#include "RAMCollector.h"
#include "netStat.h"
#include <unistd.h>

using namespace std;

int main()
{
    cpuInfoCollector cpu;
    RAMCollector ram;
    netStat net;

    //while(1)
    {
        cout << cpu.getCurrentValue() <<endl;
        cout << ram.Get_usage() <<endl;
        cout << ram.Get_free() <<endl;
        cout <<ram.Get_percent_Free() <<endl;
        cout <<ram.Get_Percent_Usage()<<endl;
       // sleep(4);
    }
    cout << "Hello world!" << endl;
    return 0;
}
