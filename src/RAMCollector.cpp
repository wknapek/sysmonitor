#include "RAMCollector.h"
#include "sys/types.h"
#include <iostream>
#include <stdio.h>

RAMCollector::RAMCollector()
{

}


RAMCollector::~RAMCollector()
{
    //dtor
}

int64_t RAMCollector::Get_usage()
{
    sysinfo(&m_info);
    return m_info.totalram - m_info.freeram;
}

int64_t RAMCollector::Get_free()
{

    sysinfo(&m_info);
    return m_info.freeram;
}

float RAMCollector::Get_percent_Free()
{
    sysinfo(&m_info);
    return (static_cast<double>(m_info.freeram)/static_cast<double>(m_info.totalram))*100;

}

float RAMCollector::Get_Percent_Usage()
{
    sysinfo(&m_info);
    return (static_cast<double>(m_info.totalram - m_info.freeram)/static_cast<double>(m_info.totalram))*100;
}
