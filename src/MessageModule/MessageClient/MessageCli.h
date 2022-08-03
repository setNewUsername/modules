#pragma once
#ifndef MESSAGECLI_H
#define MESSAGECLI_H

namespace MessageModule
{
    class MessageCli
    {
    private:
        void SetMessageDistributor();
        void SetClientName();

    public:
        MessageCli();
        ~MessageCli();
    };
}

#endif