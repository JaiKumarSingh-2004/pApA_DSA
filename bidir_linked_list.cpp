#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct my_datatype
{
	struct my_datatype *left = NULL;
	int x;
	struct my_datatype *right = NULL;
};
typedef struct my_datatype my_datatype;

my_datatype * head = NULL;
my_datatype * tail = NULL;
my_datatype * temp = NULL;

void create_bidir_linked_list(my_datatype *new_box)
{
	my_datatype * temp = NULL;
	
	if (head==tail)
	{
		head = new_box;
		temp = new_box;
	}
	else
	{
		temp->right = new_box;
		tail = new_box;
		tail->left = temp;
		temp = new_box;
	}
}

void forward_bidir_linked_list()
{
    my_datatype *temp = NULL;
    
    temp = head;
    
    while(temp != NULL)
    {
        printf("%d\t",temp->x);
        temp = temp->right;
    }
}


void backward_bidir_linked_list()
{
	my_datatype *temp = NULL;
	
	temp = tail;
	
	while(temp != NULL)
	{
		printf("%d\t",temp->x);
		temp = temp->left;
	}
}

int main()
{
	int A[10] = {10,12,13,14,15,16,17,18,19,20};
	int divisor;
	my_datatype *new_box = NULL;
	
	for(size_t i=0;1<10;i++)
	{	
		 for(divisor=2;divisor<A[i];divisor++)
        {
            if(A[i] % divisor == 0)
            break;
        }
        if (divisor == A[i])
        {
            new_box = (my_datatype*)calloc(1,sizeof(my_datatype));
            new_box->x = A[i];
            create_bidir_linked_list(new_box);
        }
    }     
    printf("\n\nthe prime nubers are\n\n");

    forward_bidir_linked_list();
    
    printf("\n\nthe printing of linked list in backward direction");
    
    backward_bidir_linked_list();
	                                           
 return 0;
}  
