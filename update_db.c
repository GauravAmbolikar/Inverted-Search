#include"header.h"

int update_db(Flist **head, hash_t *ht)
{
    char filename[100];

    printf("Enter the fileName : ");
    scanf("%99s", filename);

    //Check file extension
    char *extn = strrchr(filename, '.');

    if(extn == NULL || strcmp(extn, ".txt") != 0)
    {
        printf("Error: File should have .txt extension\n");
        return FAILURE;
    }

    //Check file exists
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error: File does not exist\n");
        return FAILURE;
    }

    //Check file is empty
    fseek(fp, 0, SEEK_END);

    if(ftell(fp) == 0)
    {
        printf("Error: File is empty\n");
        fclose(fp);
        return FAILURE;
    }

    fclose(fp);

    //Check duplicate file
    Flist *temp = *head;

    while(temp != NULL)
    {
        if(strcmp(temp->arr, filename) == 0)
        {
            printf("Error: File already exists in database\n");
            return FAILURE;
        }

        temp = temp->link;
    }

    //Add filename to Flist
    if(insert_fileName(head, filename) == FAILURE)
    {
        printf("Failed to add file\n");
        return FAILURE;
    }

    //Find the last node
    temp = *head;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    //Pass last node to create_db()
    if(create_db(temp, ht) == FAILURE)
    {
        printf("Failed to update database\n");
        return FAILURE;
    }

    printf("Database updated successfully\n");

    return SUCCESS;
}