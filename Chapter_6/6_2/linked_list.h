#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include "bin_tree.h"

struct s_listnode 
{
       struct s_treenode *tree;
       struct s_listnode *next;
};

struct s_listnode * add_list(struct s_listnode *, char *word, unsigned int min);
struct s_listnode * new_lnode();
void free_lnode(struct s_listnode *);
void print_list(struct s_listnode *);
#endif