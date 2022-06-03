#pragma once

struct _element {
    char word[100];
    int count;
    struct _element * next;
};

typedef struct _element element;

struct _list {
    int count;
    struct _element * head;
};

typedef struct _list list;

list *l_init();
void l_insert(list *lst, char *word);
void l_delete(list *lst, char *word);
void l_print(list *lst);
element *l_find(list *lst, char *word);
int readFile(list *list, char *filename);
void frequencyCount(list *list, int *frequencies);
int letterCount(list *list);
int wordCount(list *list);
void deleteWords(list *list, int frequency);
