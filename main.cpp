
#include "Library.h"


int main()
{
    Library* library = &Library::getInstance();
    library->addData();
    library -> start();
    return 0;
}
