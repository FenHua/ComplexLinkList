#ifndef __COMPLEXLINKNODE__
#define __COMPLEXLINKNODE__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct ComplexLinkNode
{
	DataType data;
	ComplexLinkNode *next;
	ComplexLinkNode *random;
}ComplexLinkNode, *pComplexLinkNode;
pComplexLinkNode CreateComplexNode(DataType x);
void CreateComplexList(pComplexLinkNode*phead);
void Print_ComplexLink(pComplexLinkNode head);
void CloneNode(pComplexLinkNode head);
void ConnectRandomNode(pComplexLinkNode head);
pComplexLinkNode SplitLink(pComplexLinkNode head);
void FreeComplexLink(pComplexLinkNode head);

#endif 