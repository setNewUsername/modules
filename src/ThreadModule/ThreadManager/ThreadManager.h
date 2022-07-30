#pragma once
#ifndef THREADMAMAGER_H
#define THREADMANAGER_H

#include "IThreadManager.h"

#include "../ThreadClient/ThreadClient.h"

#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

struct ThreadStruct
{
    thread* Thread;
    IThreadClient* ThrCli;
};

namespace ThreadModule 
{
    class ThreadManager : public IThreadManager
    {
    private:
        /**
         * @brief mutex that uses by clients
         * 
         */
        mutex SharedMutex;

        /**
         * @brief contains all threads
         */
        vector<ThreadStruct> ThreadsContainer;

        /**
         * @brief returns pointer to new thread object
         * @return thread* 
         */
        thread* CreateThread(ThreadClient* NewClient);

        /**
         * @brief kills thread by its id
         */
        void KillThread(vector<ThreadStruct>::iterator ThreadToDelete);

    public:
       ThreadManager();
        ~ThreadManager();

        void AddClient(IThreadClient* NewClient) override;

        mutex* GetSharedMutex() override;

        void CheckClients() override;
    };
}

#endif