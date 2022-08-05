#include "NameCli.h"

using namespace NameController;

NameCli::NameCli(INameCntrl* NameControllerInterface, CLI_NAMES NewClientName) : 
NameCntrl(nullptr),
CliTag("no_tag")
{
    NameCntrl = NameControllerInterface;
    if(NameCntrl != nullptr)
    {
        NameCntrl->AddNewClient(static_cast<INameCli*>(this), NewClientName);
    }
    cout << "Constructed new NameClient with no name" << endl;
};

NameCli::NameCli(const char* NewName, INameCntrl* NameControllerInterface, CLI_NAMES NewClientName) : 
NameCntrl(nullptr)
{
    strcpy(CliTag, NewName);
    NameCntrl = NameControllerInterface;
    if(NameCntrl != nullptr)
    {
        NameCntrl->AddNewClient(static_cast<INameCli*>(this), NewClientName);
    }
    cout << "Constructed new NameClient with " << CliTag << " name" << endl;
};

NameCli::~NameCli()
{
    cout << "Destructed NameClient with " << CliTag << " name" << endl;
};

char* NameCli::GetCliTag()
{
    return CliTag;
};

void NameCli::SetCliTag(const char* NewName)
{
    strcpy(CliTag, NewName);
    cout << "Setted new name for NameClient; name = " << CliTag << endl;
};