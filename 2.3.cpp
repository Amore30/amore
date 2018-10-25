#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode *next;
}Polynode, *Polylist;

Polylist Polycreat();
void printPoly(Polylist poly);
void PolyAdd(Polylist polya,Polylist polyb);
void PolyCount(Polylist poly);

int main()
{
	Polylist polya = Polycreat();
	Polylist polyb = Polycreat();
	//printPoly(polya);
	//PolyAdd(polya,polyb);
	//PolyCount(polya);
}


Polylist Polycreat()
{
	Polynode *head, *rear, *s;
	int c,e;
	head = (Polynode *)malloc(sizeof(Polynode));
	rear = head;
	printf("Enter c and e , enter 0 end\n");
	scanf("%d %d",&c,&e);
	while(c != 0)
	{
		s=(Polynode *)malloc(sizeof(Polynode));
		s->coef = c;
		s->exp = e;
		rear->next = s;
		rear = s;
		scanf("%d %d\n",&c,&e);
		//printf("%d,%d",c,e);
	}
	rear->next = NULL;
	return(head);
}

void printPoly(Polylist poly)
{
	Polynode *s;
	s = poly->next;
	while( s!= NULL)
	{
		if(s->exp != 0)
		{
			if(s->coef > 0)
			{
				printf("%d",s->coef);
				printf("x ^");
				printf("%d",s->exp);
				printf("+");
			}
		}
		else
			printf("%d",s->coef);
		s = s->next;
	}
}

void PolyAdd(Polylist polya,Polylist polyb)
{
	Polynode *p,*q,*tail,*temp;
	int sum;
	p = polya->next;
	q = polyb->next;
	tail = polya;
	while(p != NULL && q != NULL)
	{
		if(p->exp < q->exp)
		{
			tail->next = p;  tail = p;  p = p->next;
		}
		else if(p->exp == q->exp)
		{
			sum = p->coef + q->coef;
			if(sum != 0)
			{
				p->coef = sum;
				tail->next = p;
				tail = p;
				p = p->next;
				temp = q;
				q = q->next;
				free(temp);
			}
			else
			{
				temp = p;  p = p->next;  free(temp);
				temp = q;  q = q->next;  free(temp);
			}
		}
		else
		{
			tail->next = q;  tail = q;  q = q->next;
		}
	}
	if(p != NULL)
		tail->next = p;
	else
		tail->next = q;
}

void PolyCount(Polylist poly)
{
	Polynode *p;
	p = poly->next ;
	double x , result = 0;
	printf("Enter x");
	scanf("%lf",&x);
	while(p != NULL)
	{
		result = result + p->coef * pow(x,p->exp);
		p = p->next ; 
	}
	printf("when x = %lf , the result is %lf", x , result);
}
