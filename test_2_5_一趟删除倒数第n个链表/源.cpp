#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	//经典的双指针链表问题
	//简单来说思路就是先让fast指针先走n次，然后遍历链表，当fast指向空指针的时候，slow指针即是倒数第n个
	struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));//虚拟头指针方便删除的操作
	L->next = head;
	struct ListNode* slow = L;
	struct ListNode* fast = slow;
	while (n)
	{
		fast = fast->next;
		n--;
	}
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	struct ListNode* temp = slow->next;
	slow->next = temp->next;
	//return head; 不能返回head，因为当链表中只有一个元素的时候，本来你需要返回NULL，但是返回head就返回了原来的那个元素
	return L->next;
}