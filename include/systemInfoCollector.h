#ifndef SYSTEMINFOCOLLECTOR_H
#define SYSTEMINFOCOLLECTOR_H
#include "cpuInfoCollector.h"
#include "RAMCollector.h"
#include "netStat.h"


class systemInfoCollector
{
    public:
        systemInfoCollector();
        systemInfoCollector(std::string inteface);
        virtual ~systemInfoCollector();
        void getSystemInfo();
    private:
    cpuInfoCollector cpu;
    RAMCollector     ram;
    netStat          net;
};

#endif // SYSTEMINFOCOLLECTOR_H
