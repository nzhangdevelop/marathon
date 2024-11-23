/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 24. 两两交换链表中的节点。

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 递归解法。
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // 新的头节点是原头节点的下一个节点。
        ListNode *newHead = head->next;
        // 这里视原头节点head的下一个节点是交换后节点的前一个节点。
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};