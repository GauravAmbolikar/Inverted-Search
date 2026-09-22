#include"header.h"

int main(int argc, char *argv[])
{
    Flist *head = NULL;

    if(read_and_validate(argc, argv, &head) == SUCCESS)
    {
        printf("read and validate input is success\n");
    }
    else
    {
        printf("Failed to validate input files\n");
    }
    return 0;
}