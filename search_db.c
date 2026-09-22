#include"header.h"

int search_db(hash_t *ht)
{
    char word[100];

    printf("Enter the word to search: ");
    scanf("%99s", word);

    int index;

    // hashing
    if(isalpha(word[0]))
    {
        index = word[0] - 'a';
    }
    else
    {
        index = 26;
    }

    // check whether index contains any Mlist
    if(ht[index].link == NULL)
    {
        printf("Word \"%s\" not found in database\n", word);
        return FAILURE;
    }

    // search word in Mlist
    Mlist *mtemp = ht[index].link;

    while(mtemp != NULL)
    {
        if(strcmp(mtemp->word, word) == 0)
        {
            break;
        }

        mtemp = mtemp->link;
    }

    // word not found
    if(mtemp == NULL)
    {
        printf("Word \"%s\" not found in database\n", word);
        return FAILURE;
    }

    // word found
    printf("\nWord \"%s\" is present in %d file(s)\n",
           mtemp->word, mtemp->fileCount);

    Slist *stemp = mtemp->sublink;

    while(stemp != NULL)
    {
        printf("File : %s : %d time(s)\n",
               stemp->fileName, stemp->wordcount);

        stemp = stemp->link;
    }

    return SUCCESS;
}