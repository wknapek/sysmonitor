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
    cpuInfoCollector m_cpu;
    RAMCollector     m_ram;
    netStat          m_net;
};

#endif // SYSTEMINFOCOLLECTOR_H
