#pragma once 
#ifndef ITHREADMANAGER_H
#define ITHREADMANAGER_H

#include "../ThreadClient/IThreadClient.h"

#include <thread>
#include <mutex>

using namespace std;

namespace ThreadModule
{
    class IThreadManager
    {
    public:
        virtual ~IThreadManager() = default;

        virtual void AddClient(IThreadClient* NewClient) = 0;

        virtual mutex* GetSharedMutex() = 0;

        virtual void CheckClients() = 0;
    };
}
#endif