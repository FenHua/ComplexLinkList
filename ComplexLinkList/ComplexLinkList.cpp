// ComplexLinkList.cpp : �������̨Ӧ�ó������ڵ㡣
#include"ComplexLinkNode.h"
pComplexLinkNode CreateComplexNode(DataType x)
{
	pComplexLinkNode newNode = (pComplexLinkNode)malloc(sizeof(ComplexLinkNode));
	if (NULL == newNode)
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;
}
void CreateComplexList(pComplexLinkNode *phead)
{
	pComplexLinkNode n1 = CreateComplexNode(2);
	pComplexLinkNode n2 = CreateComplexNode(4);
	pComplexLinkNode n3 = CreateComplexNode(6);
	pComplexLinkNode n4 = CreateComplexNode(8);
	pComplexLinkNode n5 = CreateComplexNode(0); 
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n1->random = n5;
	n2->random = n3;
	n3->random = n2;
	n4->random = n1;
	n5->random = n4;
	*phead = n1;
}
void Print_ComplexLink(pComplexLinkNode head)
{
	//�Դ˷�ʽ���random�򲻿���Ϊ��
	pComplexLinkNode cur = head;
	while (cur)
	{
		printf("cur:%d cur->random->data:%d\n", cur->data, cur->random->data);
		cur = cur->next;
	}
}
void CloneNode(pComplexLinkNode head)
{
	//�������нڵ㣬�����ƺ�Ľڵ����ӵ���Ӧ�ڵ�ĺ���
	pComplexLinkNode newNode = NULL;
	pComplexLinkNode cur = head;
	while (cur)
	{
		newNode = CreateComplexNode(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
}
void ConnectRandomNode(pComplexLinkNode head)
{
	//���ƽ������ָ����
	pComplexLinkNode pclone = NULL;
	pComplexLinkNode cur = head;
	while (cur)
	{
		pclone = cur->next;
		if (cur->random != NULL)
		{
			pclone->random = cur->random->next;
		}
		cur = pclone->next;
	}
}
pComplexLinkNode SplitLink(pComplexLinkNode head)
{
	//�����Ƶ����еĽ�������������ɸ��ƺ������
	pComplexLinkNode cur = head;
	pComplexLinkNode Node = NULL;
	pComplexLinkNode head2 = NULL;
	if (cur)
	{
		Node = head2 = cur->next;
		cur->next = Node->next;
		cur = cur->next;
	}
	while (cur)
	{
		//�ҳ�ż��λ�õĽ�����ӹ��ɸ��ƺ������
		Node->next = cur->next;
		Node = cur->next;
		cur->next = Node->next;
		cur = cur->next;
	}
	return head2;
}
void FreeComplexLink(pComplexLinkNode head)
{
	pComplexLinkNode del = NULL;
	pComplexLinkNode cur = head;
	if (cur == NULL)
	{
		//������
		return;
	}
	else
	{
		while (cur)
		{
			del = cur;
			cur = cur->next;
			free(del);
			del = NULL;
		}
	}
}

void test()
{
	pComplexLinkNode ret;
	pComplexLinkNode head;
	CreateComplexList(&head);
	printf("ԭʼ�ĸ�������Ϊ��\n");
	Print_ComplexLink(head);
	//��������������
	CloneNode(head);
	ConnectRandomNode(head);
	ret = SplitLink(head);
	printf("���ƺ�ĸ�������Ϊ��\n");
	Print_ComplexLink(ret);
	FreeComplexLink(ret);
}
int main()
{
	test();
	system("pause");
	return 0;
}