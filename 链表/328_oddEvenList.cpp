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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        // 仔细审题。这个题目有些歧义。
        // 注意：不是要判断节点value的奇偶性。
        // 这题容易被理解成，将链表中节点value为奇数的节点找出来，形成奇数链表。
        // 然后把节点为偶数的链表找出来，形成偶数链表。
        // 合并两个链表为一个链表。
        if (!head)
        {
            return head;
        }
        ListNode *evenHead = head->next; // odd
        ListNode *odd = head;            // even
        ListNode *even = evenHead;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};