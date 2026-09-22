#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0

//filelist node
typedef struct node{
    char *arr;
    struct node *link;
}Flist;

int read_and_validate(int argc,char *argv[], Flist **head);
int insert_fileName(Flist **head, char *filename);

#endif