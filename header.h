#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define SUCCESS 1
#define FAILURE 0

//filelist node
typedef struct node{
    char *arr;
    struct node *link;
}Flist;

typedef struct sub_node{
    int wordcount;
    char *fileName;
    struct sub_node *link;
}Slist;

typedef struct main_node{
    int fileCount;
    char *word;
    struct main_node *link;
    Slist *sublink;
}Mlist;

typedef struct hash_table{
    int index;
    Mlist *link;
}hash_t;

int read_and_validate(int argc,char *argv[], Flist **head);
int insert_fileName(Flist **head, char *filename);
int create_db(Flist *f_head, hash_t *ht);
int display_db(hash_t *ht);

#endif