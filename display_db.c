#include"header.h"

int display_db(hash_t *ht)
{
    printf("\n-----------------Database----------------\n");

    for(int i = 0 ; i < 27 ; i++)
    {
        //check whether this indx contains any mlist
        //if mlist is empty move to nxt slot in ht
        if(ht[i].link == NULL)
        {
            continue;
        }

        Mlist *mtemp = ht[i].link;

        while(mtemp != NULL)
        {
            printf("[%d][%s] %dfiles:", i, mtemp->word, mtemp->fileCount);

            Slist *stemp = mtemp->sublink;

            while(stemp != NULL)
            {
                printf(" file : %s : %dtimes", stemp->fileName, stemp->wordcount);
                if(stemp->link != NULL)
                    printf(" :");
                stemp = stemp->link;
            }
            printf("\n");
            mtemp = mtemp->link;
        }
        printf("\n");
    }
    printf("------------------------------------------");

    return SUCCESS;
}