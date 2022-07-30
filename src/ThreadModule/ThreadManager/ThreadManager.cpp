#include "ThreadManager.h"

using namespace ThreadModule;

ThreadManager::ThreadManager()
{
    cout << "Created ThreadManager" << endl;
}

ThreadManager::~ThreadManager()
{
    cout << "Destructed ThreadManager" << endl;
}

mutex* ThreadManager::GetSharedMutex()
{
    return nullptr;
};

thread* ThreadManager::CreateThread(ThreadClient* NewClient)
{
    thread* NewThread = new thread(&ThreadClient::ThreadFunction, NewClient);
    NewThread->detach();
    cout << "Created new thread for ThreadClient " << NewClient->GetThreadCliTag() << endl;
    return NewThread;
};

void ThreadManager::KillThread(vector<ThreadStruct>::iterator ThreadToDelete)
{
    cout << "Killed thread of " << ThreadToDelete.base()->ThrCli->GetThreadCliTag() << endl;
    delete(ThreadToDelete.base()->Thread);
    delete(ThreadToDelete.base());
    ThreadToDelete = ThreadsContainer.erase(ThreadToDelete);
    
};

void ThreadManager::AddClient(IThreadClient* NewClient)
{
    ThreadStruct NewThreadStruct;
    NewThreadStruct.ThrCli = NewClient;
    NewThreadStruct.Thread = CreateThread(static_cast<ThreadClient*>(NewClient));

    ThreadsContainer.push_back(NewThreadStruct);
}

void ThreadManager::CheckClients()
{
    while(1)
    {
        for(auto iter = ThreadsContainer.begin(); iter != ThreadsContainer.end();)
        {
            if(!iter.base()->ThrCli->IsThreadAlive())
            {
                KillThread(iter);
            }
        }
    }
}