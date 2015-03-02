#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "bin_tree.h"

struct s_treenode * add_tree(struct s_treenode *root, char *word)
{
       if(!root)
       {    
		    root = new_tnode();
            root->word = (char *)malloc(strlen(word) + 1);
            if(word)
            {
                strcpy(root->word, word);
                root->count = 1;
            }
       }
       else
       {
           int cond;
           if((cond = strcmp(root->word, word)) == 0)
               root->count++;
           else if(cond > 0)
               root->left = add_tree(root->left, word);
           else if(cond < 0)
               root->right = add_tree(root->right, word);                 
       }
       
       return root;
}

struct s_treenode * new_tnode(void)
{
       struct s_treenode *t = (struct s_treenode *)malloc(sizeof(struct s_treenode));
       
       if(t)
       {
            t->word = NULL;
            t->count = 0;
            t->left = t->right = NULL;
       }
       
       return t; 
}

void free_tnode(struct s_treenode *node)
{
     if(node)
     {
             if(node->left)
             {
                 free_tnode(node->left);
                 node->left = NULL;
             }
             if(node->right)
             {
                 free_tnode(node->right);
                 node->right = NULL;
             }
             
             if(node->word)
             {
                 free(node->word);
                 node->word = NULL;
             }
            
             free(node);
             node = NULL;
     }     
}        

void print_tree(struct s_treenode *tree)
{
     if(tree)
     {
             print_tree(tree->left);
             printf("%s\n", tree->word);
             print_tree(tree->right);
     }     
}
             