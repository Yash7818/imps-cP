#include<stdio.h>
#include<stdlib.h>
struct stack{
	int *a;
	int top;
	int size;
};
void push(struct stack*);
int pop(struct stack*);
void peek(struct stack*);
void display(struct stack*);
void check(struct stack*,struct stack*);
int main()
{
	struct stack st;
	struct stack io;
	printf("enter the size of stack : ");
	scanf("%d",&st.size);
	st.a=(int*)malloc(st.size*sizeof(int));
	io.a=(int*)malloc(st.size*sizeof(int));
	st.top=-1;
	int d;
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.PEEK\n");
	printf("4.DISPLAY\n");
	printf("5.CHECK PALINDROME\n");
	printf("6.EXIT\n");
	while(1)
	{
		printf("enter the case : ");
		scanf("%d",&d);
		switch(d)
		{
			case 1:
				push(&st);
				break;
			case 2:
				printf("%d is poped from the stack\n",pop(&st));
				break;
			case 3:
				peek(&st);
				break;
			case 4:
				display(&st);
				break;
		    case 5:
		        check(&st,&io);
		        break;
			case 6:
				exit(0);
				break;
			default:
				printf("invalid case");
				break;
		}
	}
}
void push(struct stack* st)
{
	int x;
    if(st->top==st->size-1)
    {
    	printf("OVERFLOW\n");
	}
	else
	{
		printf("enter the value to be enter: ");
		scanf("%d",&x);
		st->top++;
		st->a[st->top]=x;
	}
}
int pop(struct stack* st)
{
	if(st->top==-1)
	printf("UNDERFLOW\n");
	else
	{
		return  st->a[st->top--];

	}
}
void peek(struct stack* st)
{
	if(st->top==-1)
	printf("stack is empty\n");
	else
	printf("%d",st->a[st->top]);
}
void display(struct stack* st)
{
	int i;
	for(i=0;i<=st->top;i++)
	{
		printf("%d->",st->a[i]);
	}
}
void check(struct stack* st,struct stack* io){
    io->top=-1;
    int i;
    while(st->top>=0){                  
        io->top++;                     
        io->a[io->top] = pop(st);
    }
    int c=0;
    for( i=0;i<=io->top;i++){
        if(st->a[i]!=io->a[i])
        {                              
            c++;
        }
    }
    if(c==0){
        printf("THE GIVEN STACK IS PALINDROMIC!!\n");
    } else
        printf("THE GIVEN STACK IS NON-PALINDROMIC\n");
    while(io->top>=0){
        st->top++;                          
        st->a[st->top] = pop(io);
    }

}
