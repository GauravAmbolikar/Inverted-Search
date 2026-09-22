#include"header.h"

int read_and_validate(int argc,char *argv[], Flist **head)
{
    printf("\n------------------------------------------------\n");
    for(int i = 1 ; i < argc ; i++)
    {
        char *extn = strrchr(argv[i], '.');
        if(extn != NULL && strcmp(extn, ".txt") == 0)
        {
            printf("%s is a valid text file\n", argv[i]);
            FILE *fp = fopen(argv[i], "r");
            if(fp != NULL)
            {
                fseek(fp, 0, SEEK_END);
                if(ftell(fp))
                {
                    printf("%s file is not empty\n", argv[i]);
                    if(insert_fileName(head, argv[i]) == SUCCESS)
                    {
                        printf("%s file is successfully inserted\n", argv[i]);
                    }
                    else
                    {
                        printf("%s file is not inserted\n",argv[i]);
                    }
                }
                else
                {
                    printf("%s file is empty\n", argv[i]);
                }
            }
            else
            {
                printf("Failed to open %s file\n", argv[i]);
            }
        }
        else
        {
            printf("%s is not .txt file\n", argv[i]);
            return FAILURE;
        }
        printf("------------------------------------------------\n");
    }

    return SUCCESS;
}

int insert_fileName(Flist **head, char *filename)
{
    if(*head != NULL)
    {
        Flist *temp = *head;

        while(temp != NULL)
        {
            if(strcmp(temp->arr, filename) == 0)
                return FAILURE;

            temp = temp->link;
        }
    }

    Flist *newNode = malloc(sizeof(Flist));

    if(newNode == NULL)
        return FAILURE;

    newNode->arr = malloc(strlen(filename) + 1);

    if(newNode->arr == NULL)
    {
        free(newNode);
        return FAILURE;
    }

    strcpy(newNode->arr, filename);
    newNode->link = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return SUCCESS;
    }

    Flist *temp = *head;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    
    temp->link = newNode;
    return SUCCESS;
}