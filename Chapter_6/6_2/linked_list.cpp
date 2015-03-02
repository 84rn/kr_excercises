#include <cstdlib>
#include <cstring>
#include "linked_list.h"

struct s_listnode * add_list(struct s_listnode *nroot, char *word, unsigned int min)
{
     int cond;
     
     if(strlen(word) >= min)
     {
         if(!nroot)
         {
             nroot = new_lnode();
             nroot->tree = add_tree(nroot->tree, word);             
         
         }
         else if((cond = strncmp(nroot->tree->word, word, min)) == 0)
              nroot->tree = add_tree(nroot->tree, word);    
         else if(cond < 0)
              nroot->next = add_list(nroot->next, word, min);
         else if(cond > 0)
         {
              struct s_listnode *tmp = NULL;
              tmp = add_list(tmp, word, min);
              tmp->next = nroot;
              nroot = tmp;              
         }
     }
     
     return nroot;    
}

struct s_listnode * new_lnode()
{
       struct s_listnode *l = (struct s_listnode *) malloc(sizeof(struct s_listnode));
       
       if(l)
       {
            l->tree = NULL;
            l->next = NULL;
       }
       
       return l; 
}

void free_lnode(struct s_listnode *n)
{     
     if(n)
     {
          if(n->tree)
          {
              free_tnode(n->tree);
              n->tree = NULL;
          }
          if(n->next)
          {
              free_lnode(n->next);
              n->next = NULL;
          }
          
          free(n);
          n = NULL;          
     }
}

void print_list(struct s_listnode *l)
{
     if(l->tree)
     {         
         print_tree(l->tree);
     }
     if(l->next)
     {
         print_list(l->next);
     }
}