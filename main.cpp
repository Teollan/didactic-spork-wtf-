#include <iostream>
#include "structs.h"


int main()
{
    blacklist * bl = new blacklist;
    bl->first = nullptr;
    bl->size = 0;
    node * nd1 = new node;
    nd1->text = "Node 1";
    node * nd2 = new node;
    nd2->text = "Node 2";
    node * nd3 = new node;
    nd3->text = "Node 3";

    for (int i = 0; i <5; i++){
    push_back (nd3,bl);
    push_front (nd1,bl);
    push_after_front(nd2,bl);
    push_after_front(nd1,bl);
    insert_after_each(nd3,nd1,bl);
    insert_after_each(nd2,nd3,bl);
    insert_after_each(nd1,nd3,bl);
    push_back(nd1,bl);
    push_back(nd2,bl);}

    print_all(bl);
    clear(bl);
    delete bl;
    delete nd1;
    delete nd2;
    delete nd3;
    return 0;
}
