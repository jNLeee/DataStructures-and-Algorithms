#include <iostream>

/* Link list node */
struct list
{
    int data;
    struct list *next;
};

void push(struct list **head_ref, int new_data);

struct list* sortedListIntersection(struct list* a, struct list* b)  
{    
	struct list temp;    
	struct list* tail = &temp;    
	temp.next = nullptr;        
	while (a != nullptr && b != nullptr)    
	{      
		if (a->data == b->data)      
		{         
			push((&tail->next), a->data);         
			tail = tail->next;         
			a = a->next;         
			b = b->next;      
		}      
		else if (a->data < b->data) // check the smaller list   
		{           
			a = a->next;      
		}
		else
		{       
			b = b->next;    
		}
	}    
	return(temp.next);  
} 

void push(struct list **head_ref, int new_data)
{
    struct list *new_node = (struct list *)malloc(sizeof(struct list));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void print(struct list *node)
{
    while (node != nullptr)
    {
        std::cout << " " << node->data;
        node = node->next;
    }
}

int main()
{
    struct list *a = nullptr;
    struct list *b = nullptr;
    struct list *intersect = nullptr;

    /* a's sorted linked list will be 3->4->5->6->7->8 */
    push(&a, 8);
    push(&a, 7);
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    /* b's sorted linked list will be 2->4->6->8 */
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
    std::cout << "\n a's list: \n ";
    print(a);
    std::cout << "\n b's list: \n ";
    print(b);
    /* Find the intersection two linked lists */
    intersect = sortedListIntersection(a, b);
    std::cout << "\n Intersecting nodes of a & b: \n ";
    print(intersect);
}
