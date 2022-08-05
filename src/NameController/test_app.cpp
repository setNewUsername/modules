#include "NameClient/NameCli.h"
#include "NameController/NameCntrl.h"
#include "NameClient/ClientNames.h"

using namespace NameController;

int main(int argc, char* argv[])
{
    NameCntrl* cntrl_1 = new NameCntrl();

    NameCli* tst1 = new NameCli("test_1", cntrl_1, FIRST_NAME);

    return 0;
}