//  Brute force approach 
 if(head == NULL )return head;
        ListNode*temp= head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        if(len==n){
            head = head->next;
            return head;
        }
        if(n>len){
            return head;
        }
        int diff = len - n;         
        ListNode* prev= NULL;      
        ListNode* curr = head;        
        for(int i = 0;i < diff;i++){
            prev = curr;           
            curr = curr->next;     
        }
        prev->next = curr->next;
        return head;

// time complexity = O(2n)
// Optimse approach
  ListNode*dummy = new ListNode();
        dummy->next = head;
        ListNode*fast = dummy;
        ListNode*slow = dummy;
        for(int i=1;i<=n;i++){
            fast = fast->next;
        }
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;

