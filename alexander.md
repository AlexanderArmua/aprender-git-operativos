# Linked List
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    int retVal = -1;
    node_t * current = *head;
    node_t * previous = NULL;
        
    while (current->val != val) {
        if (current->next == NULL) {
            return -1;
        }
        
        if (current->val != val) {
        	previous = current;
        }
   		
        current = current->next;
    }
    
    previous->next = current->next;
    retVal = current->val;
    
    free(current);
    
    return retVal;
}

int main() {

    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
}
```

# Funciones en un array
```c
    #include <stdio.h>

    void f1(int var) {
            printf("this is f1 and var is: %d\n", var);
    }

    void f2(int var)
    {
            printf("this is f2 and var is: %d\n", var);
    }

    void f3(int var)
    {
            printf("this is f3 and var is: %d\n", var);
    }

    int main()
    {
        /* define an array full of function pointers 
           to the above functions, that take an `int` as 
           their only argument */
        
        void (*functions[3])(int);
        
        functions[0] = &f1;
        functions[1] = &f2;
        functions[2] = &f3;


		int c = 0;
		while(c < 3)
		{
           /* call the functions using the function pointers
           of the array at index `c` with `c` as an argument */
            (functions[c])(c);

			++c;
		}

	  return 0;
    }
```

