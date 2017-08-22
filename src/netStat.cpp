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
        interfaces.insert(std::map<std::string,networkInterFace>::value_type(ifa->ifa_name,networkInterFace(0,0)));
    }
}

void netStat::printInterfaces()
{
    for(auto it = interfaces.begin(); it != interfaces.end(); it++)
    {

        std::ifstream net_stat_rx;
        std::ifstream net_stat_tx;
        std::cout<<"Network Interface:         "<<it->first<<std::endl;
        net_stat_rx.open("/sys/class/net/"+ it->first+ "/statistics/rx_bytes");
        net_stat_rx >> it->second.rx_bytes;
        std::cout<< "                               RX bytes: " <<it->second.rx_bytes << std::endl;
        net_stat_tx.open("/sys/class/net/"+ it->first +"/statistics/tx_bytes");
        net_stat_tx >> it->second.tx_bytes;
        std::cout << "                               TX bytes: " << it->second.tx_bytes <<std::endl;
    }

}


