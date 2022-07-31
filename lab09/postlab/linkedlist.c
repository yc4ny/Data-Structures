#include <stdio.h>
#include <stdlib.h>
struct list_item {
  struct list_item *prev, *next;
  void *datum;
};

struct list{
  struct list_item *head;                                                    
  int size;
};
int main(){
  //Read in an integer,n
  int n=0;
  printf("Enter an integer: ");
  scanf("%d",&n);
/*Read in n more inputs, and put into linked list (must be dynamically 
  allocated)*/
  int i;
  int num;
  struct list_item *node;
  struct list *list = (struct list *) malloc(sizeof(struct list));
  list->head = NULL;
  list->size = 0;
  for(i=0;i<n;i++){
    scanf("%d",&num);
    node =(struct list_item *) malloc(sizeof(struct list_item));
    node->datum = num;
    if (!list->head) {
      node->next = NULL;
      list->head = node;
    }
    else {
      node->next = list->head;
      list->head = node;
    }
    list->size++;
  }
/*Print out linked list (any order)*/
  int loop = 0;
  struct list_item *s=list->head;
  while(loop<list->size){
    printf("%d\n",s->datum);
    s = s->next;
    loop++;
  }
/*Properly deallocate linked list*/
  free(node);
  free(list);
  return 0;
}
