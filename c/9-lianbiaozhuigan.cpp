#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//链表追赶问题,求链表倒数第k个点
struct listnode
{
	int data;
	listnode *next;
};
//链表创建
listnode* listcreate(int n)
{
	int i;
	listnode *p;

	listnode *head,*top;
	head = (listnode *)malloc(sizeof(listnode));
	top = head;
	head->data = 0;
	for(int i = 0;i<n;i++)
	{
		p = (listnode *)malloc(sizeof(listnode));
		head->data = i;
		head->next = p;
		head = p;
	}
	head->next = NULL;
	return top;
}

listnode *fun(listnode *head,int k)
{
	listnode *i,*j;
	i = head; 
	j = head;
	for(int m = 0;m<k;m++)
	{
		j = j->next;
	}
	while(j->next!=NULL)
	{
		i = i->next;
		j = j->next;
	}

	return i;
}


//两条链表相交问题
struct Node
{
	int value;
	Node * next;
};

//1.先判断带不带环
//判断是否有环，返回bool，如果有环，返回环里的节点
//思路：用两个指针，一个指针步长为1，一个指针步长为2，判断链表是否有环
bool isCircle(Node * head, Node *& circleNode, Node *& lastNode)
{
	Node * fast = head->next;
	Node * slow = head;
	while(fast != slow && fast && slow)
	{
		if(fast->next != NULL)
			fast = fast->next;
		
		if(fast->next == NULL)
			lastNode = fast;
		if(slow->next == NULL)
			lastNode = slow;
		
		fast = fast->next;
		slow = slow->next;
		
	}
	if(fast == slow && fast && slow)
	{
		circleNode = fast;
		return true;
	}
	else
		return false;
}
//判断带环不带环时链表是否相交
//2.如果都不带环，就判断尾节点是否相等
//3.如果都带环，判断一链表上俩指针相遇的那个节点，在不在另一条链表上。
bool detect(Node * head1, Node * head2)
{
	Node * circleNode1;
	Node * circleNode2;
	Node * lastNode1;
	Node * lastNode2;
	
	bool isCircle1 = isCircle(head1,circleNode1, lastNode1);
	bool isCircle2 = isCircle(head2,circleNode2, lastNode2);
	
	//一个有环，一个无环
	if(isCircle1 != isCircle2)
		return false;
	//两个都无环，判断最后一个节点是否相等
	else if(!isCircle1 && !isCircle2)
	{
		return lastNode1 == lastNode2;
	}
	//两个都有环，判断环里的节点是否能到达另一个链表环里的节点
	else
	{
		Node * temp = circleNode1->next;  //updated，多谢苍狼 and hyy。
		while(temp != circleNode1)  
		{
			if(temp == circleNode2)
				return true;
			temp = temp->next;
		}
		return false;
	}
	
	return false;
}

int main()
{
	listnode *p,*pm,*q;
	pm = listcreate(10);
	q = pm ;
	for(int i = 0;i<10;i++)
	{
		printf("%d\n",pm->data);
		pm = pm->next;
	}
	p = fun(q,3);
	printf("%d\n",p->data);
	return 0;
}