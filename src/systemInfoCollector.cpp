#include "systemInfoCollector.h"
#include <sys/sysinfo.h>
#include <iostream>

systemInfoCollector::systemInfoCollector()
{
}

systemInfoCollector::~systemInfoCollector()
{
    //dtor
}

void systemInfoCollector::getSystemInfo()
{
    struct sysinfo sys_info;
    int days, hours, mins;
    if(sysinfo(&sys_info) != 0)
    {
        return;
    }
    std::cout<<"\033c";
    days = sys_info.uptime / 86400;
    hours = (sys_info.uptime / 3600) - (days * 24);
    mins = (sys_info.uptime / 60) - (days * 1440) - (hours * 60);
    std::cout<<"uptime: " << "days: " << days  << " hours: " << hours << " minutes: " << mins <<std::endl;
    std::cout<<"Total Number of processes: " << sys_info.procs << std::endl;
    std::cout<<"CPU load:                  " << cpu.getCurrentValue() << "%"<<std::endl;
    std::cout<<"RAM in bytes usage:        " << ram.Get_usage() <<std::endl;
    std::cout<<"RAM in bytes free:         " << ram.Get_free() << std::endl;
    std::cout<<"RAM usage percentage:      " << ram.Get_Percent_Usage() << "%" <<std::endl;
    std::cout<<"RAM free percentage:       " << ram.Get_percent_Free() << "%" <<std::endl;
    net.printInterfaces();

}
