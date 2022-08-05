#pragma once
#ifndef INAMECLI_H
#define INAMECLI_H

namespace NameController
{
    class INameCli
    {
    public:
        virtual ~INameCli() = default;
        virtual char* GetCliTag() = 0;
    };   
}

#endif