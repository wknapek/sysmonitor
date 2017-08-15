#ifndef CPUINFOCOLLECTOR_H
#define CPUINFOCOLLECTOR_H

#include "stdlib.h"
#include "string.h"
#include <stdio.h>
#include <vector>



class cpuInfoCollector
{
    public:
        cpuInfoCollector();
        virtual ~cpuInfoCollector();
        double getCurrentValue();
    private:
        std::vector<size_t>  scanProcFile();
        class cpu_info
        {
        public:
            size_t idle_value;
            size_t total_value;

        };
        cpu_info acumulateValues(std::vector<size_t> cpu_values);
        std::vector<size_t> cpu_values;
        cpu_info prev_info;
};

#endif // CPUINFOCOLLECTOR_H
