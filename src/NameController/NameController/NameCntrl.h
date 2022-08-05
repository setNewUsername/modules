#pragma once
#ifndef NAMECNTRL_H
#define NAMECNTRL_H

#include "INameCntrl.h"
#include "../NameClient/NameCli.h"

#include <unordered_map>
#include <iostream>

using namespace std;

namespace NameController
{
    class NameCntrl : public INameCntrl
    {
    private:
        unordered_map<CLI_NAMES, INameCli*> ObjectMap;

    public:
        NameCntrl();
        ~NameCntrl();

        void AddNewClient(INameCli* NewClient, CLI_NAMES NewClientName) override;

        INameCli* GetObjectByName(CLI_NAMES ClientName);

        CLI_NAMES GetNameOfObject(INameCli* Client);
    };
    
}

#endif