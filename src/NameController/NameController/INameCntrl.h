#pragma once
#ifndef INAMECNTRL_H
#define INAMECNTRL_H

#include "../NameClient/INameCli.h"
#include "../NameClient/ClientNames.h"

namespace NameController
{
    class INameCntrl
    {
    public:
        virtual ~INameCntrl() = default;

        virtual void AddNewClient(INameCli* NewClient, CLI_NAMES NewClientName) = 0;
    };
}

#endif