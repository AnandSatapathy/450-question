class Solution
{
public:
    ListNode *th = NULL;
    ListNode *tt = NULL;

    // length of the link list // tc = O(N)
    int length(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    // using the concept of addfirst leetcode 94p
    void addfirstNode(ListNode *node)
    {
        if (th == NULL)
        {
            th = node;
            tt = node;
        }
        else
        {
            node->next = th;
            th = node;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    { // tc= O(N) sc = O(1)
        ListNode *oh = NULL;
        ListNode *ot = NULL;
        if (head == NULL || head->next == NULL)
            return head;
        int len = length(head);
        ListNode *curr = head;
        while (len >= k)
        {
            int temp = k;
            while (temp--)
            {
                ListNode *forw = curr->next;
                curr->next = NULL;
                addfirstNode(curr);
                curr = forw;
            }
            if (oh == NULL)
            {
                oh = th;
                ot = tt;
            }
            else
            {
                ot->next = th;
                ot = tt;
            }
            th = NULL;
            tt = NULL;
            len -= k;
        }
        ot->next = curr;
        return oh;
    }