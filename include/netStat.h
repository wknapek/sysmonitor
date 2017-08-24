#ifndef NETSTAT_H
#define NETSTAT_H
#include <vector>
#include <stdio.h>
#include <string>
#include <map>


class netStat
{
    public:
        netStat();
        netStat(std::string interface);
        virtual ~netStat();
        void printInterfaces();

    protected:

    private:
    std::vector<size_t> net_stats();
    void get_interfaces();
    class networkInterFace
    {
    public:
        networkInterFace(int64_t rx,int64_t tx)
        {
            rx_bytes = rx;
            tx_bytes = tx;
        }
        int64_t rx_bytes;
        int64_t tx_bytes;
    };
    std::map<std::string,networkInterFace> m_interfaces;
};

#endif // NETSTAT_H
