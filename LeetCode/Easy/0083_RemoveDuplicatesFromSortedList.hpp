namespace LeetCode::Easy
{
    struct ListNode
    {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr)
        {
        }
        ListNode(int x) : val(x), next(nullptr)
        {
        }
        ListNode(int x, ListNode *next) : val(x), next(next)
        {
        }
    };

    auto DeleteDuplicates(ListNode *head) -> ListNode *
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *slowWalker = head;
        for (ListNode *fastWalker = slowWalker->next; fastWalker != nullptr; fastWalker = fastWalker->next)
        {
            if (slowWalker->val != fastWalker->val)
            {
                slowWalker = slowWalker->next;
                slowWalker->val = fastWalker->val;
            }
        }

        slowWalker->next = nullptr;
        return head;
    }
} // namespace LeetCode::Easy