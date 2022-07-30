#pragma once 
#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include "../ThreadManager/IThreadManager.h"
#include "IThreadClient.h"

#include <string>
#include <iostream>

using namespace std;

namespace ThreadModule
{
    class ThreadClient : public IThreadClient
    {
    protected:
        /**
         * @brief ThreadClient tag, uses to identify different thread clients in console logs
         */
        string ThrCliTag;

        /**
         * @brief indicates stat of thread
         */
        bool ThreadAlive;
        
        /**
         * @brief pointer to IThreadManager
         */
        IThreadManager* ThrMgrInterface;

        /**
         * @brief sets ThreadClient ThreadAlive field
         * @param ThreadStat 
         */
        void SetThreadAlive(bool ThreadStat);

        /**
         * @brief sets ThreadClient ThrCliTag field
         * @param NewCliTag 
         */
        void SetCliTag(string NewCliTag);

        /**
         * @brief sets ThreadClient ThrMgrInterface field
         * 
         * @param ThreadManager 
         */
        void SetThreadManager(IThreadManager* ThreadManager);

        /**
         * @brief calls to ThreadManager::AddClient to add this object to thread clients queue
         */
        void AddToThrMgr();

    public:
        ThreadClient();
        virtual ~ThreadClient();

        /**
         * @brief returns ThreadManager ThreadAlive field stat
         * @return true 
         * @return false 
         */
        bool IsThreadAlive() override;

        /**
         * @brief must be overrided in child class of ThreadClient
         */
        virtual void ThreadFunction();

        /**
         * @brief returns tag of ThreadClient
         * @return string 
         */
        string GetThreadCliTag();
    };
}

#endif