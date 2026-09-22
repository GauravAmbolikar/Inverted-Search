#include"header.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Error: No input files provided.\n");
        return 0;
    }
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
        printf("Read and Validate input files is success\n");

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
                    search_db(ht);
                    break;
                case 4:
                    //update
                    update_db(&f_head, ht);
                    break;
                case 5:
                    //save
                    save_db(ht);
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