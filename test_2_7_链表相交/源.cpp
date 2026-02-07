#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
	struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
		、
			//这是一个灵活运用的链表双指针题型
			//这题的主要思路就是无论是否相交的链表
			//A+B不相交(当AB不相交，这个部分为B全体)=B+A不相交部分
			//下面有一个我自己的易错点
			struct ListNode* A = headA;
		struct ListNode* B = headB;
		if (A == NULL || B == NULL)
		{
			return NULL;
		}
		while (A || B)
		{

			if (A == B)
			{
				return A;
			}
			if (A == NULL)
			{
				A = headB;
			}
			else
			{
				A = A->next;
			}
			if (B == NULL)
			{
				B = headA;
			}
			else
			{
				B = B->next;
			}
			//A=A->next;
			//B=B->next;
			//这个地方是我的易错点，因为如果这样写就会导致
			//例如：B移动到headA之后继续B=B->next移动两次
			//这会导致例如：A=2，3  B=3在3相交的时候，找不到相交点
			//模拟A：2-3   -NULL-NULL   
			//    B：3-NULL-3   -NULL
		}
		return NULL;
	}
	struct ListNode* A = headA;
	struct ListNode* B = headB;
	if (A == NULL || B == NULL)
	{
		return NULL;
	}
	while (A || B)
	{

		if (A == B)
		{
			return A;
		}
		if (A == NULL)
		{
			A = headB;
		}
		else
		{
			A = A->next;
		}
		if (B == NULL)
		{
			B = headA;
		}
		else
		{
			B = B->next;
		}
		//A=A->next;
		//B=B->next;
	}
	return NULL;
}