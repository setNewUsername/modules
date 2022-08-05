#include "NameCntrl.h"

using namespace NameController;

NameCntrl::NameCntrl()
{
}
    
NameCntrl::~NameCntrl()
{
}

void NameCntrl::AddNewClient(INameCli* NewClient, CLI_NAMES NewClientName)
{
    ObjectMap[NewClientName] = NewClient;
    cout << "Added new object with " << NewClient->GetCliTag() << " tag and " << NewClientName << " name; registrated objects amount is " << ObjectMap.size() << endl;
}

INameCli* NameCntrl::GetObjectByName(CLI_NAMES ClientName)
{
    return ObjectMap[ClientName];
}

CLI_NAMES NameCntrl::GetNameOfObject(INameCli* Client)
{
    CLI_NAMES Result = UNDEFINED;

    for(const auto& CurrentPair : ObjectMap) {
        if(CurrentPair.second == Client)
        {
            Result = CurrentPair.first;
            cout << "Found registered client with " << Client->GetCliTag() << " tag; " << Result << " name; returning value" << endl;
        }
        else
        {
            cout << "Client with tag " << Client->GetCliTag() << " not registered" << endl;
        }
    }

    return Result;
}