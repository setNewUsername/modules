#pragma once
#ifndef NAMECLI_H
#define NAMECLI_H

#include "../NameController/INameCntrl.h"
#include "INameCli.h"
#include "ClientNames.h"

#include "string.h"
#include <iostream>

using namespace std;

namespace NameController
{
    class NameCli : public INameCli
    {
    private:
        char CliTag[32];
        INameCntrl* NameCntrl;

    protected:
        char* GetCliTag() override;
        void SetCliTag(const char* NewCliTag);

    public:
        NameCli(INameCntrl* NameControllerInterface, CLI_NAMES NewClientName);
        NameCli(const char* NewCliTag, INameCntrl* NameControllerInterface, CLI_NAMES NewClientName);
        virtual ~NameCli();
    };
}

#endif