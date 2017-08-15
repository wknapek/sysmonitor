#ifndef RAMCOLLECTOR_H
#define RAMCOLLECTOR_H
#include <stdint.h>
#include "sys/sysinfo.h"


class RAMCollector
{
    public:
        RAMCollector();
        virtual ~RAMCollector();

        int64_t Get_free();
        int64_t Get_usage();
        float Get_Percent_Usage();
        float Get_percent_Free();


    protected:
    struct sysinfo m_info;

};

#endif // RAMCOLLECTOR_H
