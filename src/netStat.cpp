#include "netStat.h"
#include "iostream"
#include <fstream>
#include <limits>
#include <sys/types.h>
#include <ifaddrs.h>

netStat::netStat()
{
    //ctor
    get_interfaces();
    printInterfaces();
}

netStat::~netStat()
{
    //dtor
}

std::vector<size_t> netStat::net_stats()
{
    std::ifstream net_stat;
    net_stat.open("/proc/net/dev");
    //net_stat.ignore(2,'|');
    std::vector<size_t> values;
    for (size_t value; net_stat >> value; values.push_back(value));
    return values;
}

void netStat::get_interfaces()
{
    struct ifaddrs *ifaddr, *ifa;
    getifaddrs(&ifaddr);
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        interfaces.insert(ifa->ifa_name);
    }
}

void netStat::printInterfaces()
{
    for(auto it = interfaces.begin();it!=interfaces.end();it++)
    {
        std::ifstream net_stat_rx;
        std::ifstream net_stat_tx;
        net_stat_rx.open("/sys/class/net/"+*it+"/statistics/rx_bytes");
        std::cout<<net_stat_rx.rdbuf()<<std::endl;
        net_stat_tx.open("/sys/class/net/"+*it+"/statistics/tx_bytes");
        std::cout<<net_stat_tx.rdbuf()<<std::endl;
    }

}
