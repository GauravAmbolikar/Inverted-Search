#include"header.h"

int main(int argc, char *argv[])
{
    Flist *f_head = NULL;

    //initialize hash table
    hash_t ht[27];
    for(int i = 0 ; i < 27 ; i++)
    {
        ht[i].index = i;
        ht[i].link = NULL;
    }

    if(read_and_validate(argc, argv, &f_head) == SUCCESS)
    {
        printf("read and validate input is success\n");

        int choice;

        while (1)
        {
            printf("\n1. Create Database\n2. Display Database\n3. Search Database\n4. Update Database\n5. Save Database\n6. Exit\n");

            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                    //create
                    create_db(f_head, ht);
                    break;
                case 2:
                    //display
                    display_db(ht);
                    break;
                case 3:
                    //search
                    break;
                case 4:
                    //update
                    break;
                case 5:
                    //save
                    break;
                case 6:
                    //Exit
                    return 0;
                default:
                    printf("Invalid Choice\n");    
            }
        
        }
    }
    else
    {
        printf("Failed to validate input files\n");
    }
    return 0;
}