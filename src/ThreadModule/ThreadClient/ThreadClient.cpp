#include "ThreadClient.h"

using namespace ThreadModule;

ThreadClient::ThreadClient() : 
ThrCliTag("none_cli_tag"),
ThreadAlive(false),
ThrMgrInterface(nullptr)
{
    cout << "Created new ThreadClient" << endl;
}

ThreadClient::~ThreadClient()
{
}

bool ThreadClient::IsThreadAlive()
{
    return ThreadAlive;
}

void ThreadClient::SetThreadAlive(bool ThreadStat)
{
    ThreadAlive = ThreadStat;
}

void ThreadClient::SetCliTag(string NewCliTag)
{
    ThrCliTag = NewCliTag;
}

void ThreadClient::SetThreadManager(IThreadManager* ThreadManager)
{
    if(ThreadManager != nullptr)
        ThrMgrInterface = ThreadManager;
    else
        cout << "Nullptr ThreadManager put to " << ThrCliTag << endl;
}

void ThreadClient::AddToThrMgr()
{
    if(ThrMgrInterface != nullptr)
    {
        this->SetThreadAlive(true);
        ThrMgrInterface->AddClient(this);
    }
    else
        cout << "ThreadManager is nullptr in " << ThrCliTag << endl;
}

string ThreadClient::GetThreadCliTag()
{
    return ThrCliTag;
}

void ThreadClient::ThreadFunction()
{
    cout << "Thread function of " << ThrCliTag << " not overrided" << endl;
}