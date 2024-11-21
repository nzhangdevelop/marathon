// 206. Rerverse Linked list.
// 翻转一个链表

// 1. 迭代法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 1.迭代法
        // 声明一个prev指针，指向前一个节点，初始值为null。
        ListNode *prev = nullptr;
        // 声明一个curr指针，游标指针，指向当前操作的节点。
        ListNode *curr = head;
        while (curr)
        {
            // 先将当前节点指向下一个节点的指针保存。
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// 2. 递归法
class Solution
{
public:
    ListNode *reverseList(ListNode *head, ListNode *head_prev = nullptr)
    {
        if (head == nullptr)
        {
            return head_prev;
        }
        ListNode *head_next = head->next;
        head->next = head_prev;
        return reverseList(head_next, head);
    }
};