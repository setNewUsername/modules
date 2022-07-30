#pragma once
#ifndef ITHREADCLIENT_H
#define ITHREADCLIENT_H

#include <string>

using namespace std;

class IThreadClient
{
public:
    virtual ~IThreadClient() = default;

    virtual bool IsThreadAlive() = 0;
    virtual string GetThreadCliTag() = 0;
};

#endif