#ifndef NETSTAT_H
#define NETSTAT_H
#include <vector>
#include <stdio.h>
#include <string>
#include <set>


class netStat
{
    public:
        netStat();
        virtual ~netStat();
        void printInterfaces();

    protected:

    private:
    std::vector<size_t> net_stats();
    void get_interfaces();
    std::set<std::string> interfaces;
};

#endif // NETSTAT_H
