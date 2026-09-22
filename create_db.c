#include"header.h"

int create_db(Flist *f_head, hash_t *ht)
{
    Flist *temp = f_head;

    while(temp != NULL)
    {
        FILE *fp = fopen(temp->arr, "r");
        
        if(fp == NULL)
        {
            printf("Error:Unable to open %s\n",temp->arr);
            return FAILURE;
        }

        printf("%s opened successfully\n", temp->arr);

        char word[100];

        while(fscanf(fp, "%99s", word) != EOF)
        {
            int index;

            //hashing
            if(isalpha(word[0]))
            {
                index = word[0] - 'a';
            }
            else
            {
                index = 26;
            }

            printf("Word = %s, Index = %d\n", word, index);
            
            //search word in mlist
            Mlist *mtemp = ht[index].link;
            
            while(mtemp != NULL)
            {
                if(strcmp(mtemp->word, word) == 0)
                {
                    break;
                }
                mtemp = mtemp->link;
            }
            //word not exist
            if(mtemp == NULL)
            {
                Mlist *newM = malloc(sizeof(Mlist));
                
                if(newM == NULL)
                {
                    fclose(fp);
                    return FAILURE;
                }
                
                newM->word = malloc(strlen(word)+1);

                if(newM->word == NULL)
                {
                    free(newM);
                    fclose(fp);
                    return FAILURE;
                }

                strcpy(newM->word,word);
                newM->fileCount = 1;

                //create first sublist node
                Slist *newS = malloc(sizeof(Slist));

                if(newS == NULL)
                {
                    fclose(fp);
                    return FAILURE;
                }

                newS->fileName = malloc(strlen(temp->arr)+1);

                if(newS->fileName == NULL)
                {
                    fclose(fp);
                    return FAILURE;
                }

                strcpy(newS->fileName, temp->arr);

                newS->wordcount = 1;
                newS->link = NULL;

                newM->sublink = newS;

                //insert newM at beginning of mainNode list

                newM->link = ht[index].link;
                ht[index].link = newM;
            }
            //word exist
            else
            {
                Slist *stemp = mtemp->sublink;

                while(stemp != NULL)
                {
                    //word is present in existing file or not
                    if(strcmp(stemp->fileName, temp->arr) == 0)
                    {
                        break;
                    }
                    stemp = stemp->link;
                }

                if(stemp != NULL)
                {
                    //same file
                    stemp->wordcount++;
                }
                else
                {
                    //differnt file
                    Slist *newS = malloc(sizeof(Slist));

                    if(newS == NULL)
                    {
                        fclose(fp);
                        return FAILURE;
                    }

                    newS->fileName = malloc(strlen(temp->arr)+1);

                    if(newS->fileName == NULL)
                    {
                        fclose(fp);
                        return FAILURE;
                    }

                    strcpy(newS->fileName, temp->arr);
                    newS->wordcount = 1;
                    newS->link = NULL;

                    //insert node
                    newS->link = mtemp->sublink;
                    mtemp->sublink = newS;

                    //increase filecount of mtemp
                    mtemp->fileCount++;
                }

            }
        }

        fclose(fp);
        temp = temp->link;
    }
    return SUCCESS;
}