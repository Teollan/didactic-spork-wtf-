#pragma once

struct node{
    char * text;
    node * next;
};

struct blacklist{
    node * first;
    int size;
};

void push_back(node*, blacklist*);
void push_front(node *, blacklist *);
void push_after_front(node *, blacklist *);
void insert_after_each(node *, node *, blacklist *);
void print_in_file(blacklist *);
bool empty(blacklist *);

void print_all (blacklist *);
node * make_copy(node *);
void pop_front(blacklist *);
void clear(blacklist*);
bool wanna_try();
