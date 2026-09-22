#include"header.h"

int save_db(hash_t *ht)
{
    char filename[100];

    printf("Enter the database file name to save: ");
    scanf("%99s", filename);

    // Open file in write mode
    // If file already exists, it will be overwritten
    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Error: Unable to open %s\n", filename);
        return FAILURE;
    }

    // Traverse hash table
    for(int i = 0; i < 27; i++)
    {
        Mlist *mtemp = ht[i].link;

        while(mtemp != NULL)
        {
            fprintf(fp, "#%d;%s;%d;",
                    i,
                    mtemp->word,
                    mtemp->fileCount);

            Slist *stemp = mtemp->sublink;

            while(stemp != NULL)
            {
                fprintf(fp, "%s;%d;",
                        stemp->fileName,
                        stemp->wordcount);

                stemp = stemp->link;
            }

            fprintf(fp, "#\n");

            mtemp = mtemp->link;
        }
    }

    fclose(fp);

    printf("Database saved successfully in %s\n", filename);

    return SUCCESS;
}