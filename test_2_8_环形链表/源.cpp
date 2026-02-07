#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
	//这题必须掌握的是环的判断，即用快慢指针是否相遇来判断
	//其他的知识则是数学技巧方面的知识
	//这题拓宽了我解题的思路
	//图中附带了数学方面的解析
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	do {
		if (fast == NULL || fast->next == NULL)
		{
			return NULL;
		}
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
	} while (slow != fast);
	fast = head;
	while (fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}