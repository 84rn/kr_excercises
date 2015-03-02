#ifndef _BIN_TREE_
#define _BIN_TREE_

struct s_treenode 
{
       char *word;
       int count;
       struct s_treenode *left;
       struct s_treenode *right;
};

struct s_treenode * add_tree(struct s_treenode *root, char *word);
struct s_treenode * new_tnode(void);
void free_tnode(struct s_treenode *node);
void print_tree(struct s_treenode *tree);

#endif