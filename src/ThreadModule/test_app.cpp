#include <iostream>
#include "ThreadManager/ThreadManager.h"
#include "ThreadManager/IThreadManager.h"
#include "ThreadClient/ThreadClient.h"

using namespace std;

using namespace ThreadModule;

class test_class : protected ThreadClient
{
private:
    
public:
    test_class(IThreadManager* thr_mgr)
    {
        this->SetCliTag("test_class");
        this->SetThreadManager(thr_mgr);
        this->AddToThrMgr();
    };

    ~test_class()
    {

    };

    void ThreadFunction() override
    {
        int count(0);
        while(1)
        {
            if(count > 10)
            {
                this->SetThreadAlive(false);
                break;
            }
            cout << "a" << endl;
            count++;
        }
    };
};

int main(int argc, char* argv[])
{
    ThreadManager thr_mgr;
    test_class* cli1 = new test_class(static_cast<IThreadManager*>(&thr_mgr));
    
    thr_mgr.CheckClients();
    return 0;
}