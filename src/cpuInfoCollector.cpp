#include "cpuInfoCollector.h"
#include <iostream>
#include <fstream>
#include <numeric>


cpuInfoCollector::cpuInfoCollector()
{
    m_cpu_values = scanProcFile();
    m_prev_info = acumulateValues(m_cpu_values);
}

cpuInfoCollector::~cpuInfoCollector()
{

}


std::vector<size_t> cpuInfoCollector::scanProcFile()
{
    std::ifstream proc_stat("/proc/stat");
    proc_stat.ignore(5, ' '); // Skip the 'cpu' prefix.
    std::vector<size_t> values;
    for (size_t value; proc_stat >> value; values.push_back(value));
    return values;
}

cpuInfoCollector::cpu_info cpuInfoCollector::acumulateValues(std::vector<size_t> m_cpu_values)
{
    cpu_info ret_val;

    ret_val.idle_value = m_cpu_values[3];
    ret_val.total_value = std::accumulate(m_cpu_values.begin(),m_cpu_values.end(),0);
    return ret_val;
}

double cpuInfoCollector::getCurrentValue()
{
    double percent = 0.0;
    cpu_info cur_info;
    m_cpu_values = scanProcFile();
    cur_info = acumulateValues(m_cpu_values);
    double idle_value_delta = cur_info.idle_value - m_prev_info.idle_value;
    double total_value_delta =  cur_info.total_value - m_prev_info.total_value;
    percent = 100.0 * (1.0-idle_value_delta/total_value_delta);
    m_prev_info = cur_info;

    return percent;
}
