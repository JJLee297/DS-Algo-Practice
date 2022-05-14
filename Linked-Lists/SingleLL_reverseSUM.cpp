/*
The input is two linked lists, for example, 3->9->7 and 7->5
The output is the reversed sum of the reversed lists, as a singly linked list (793 + 57 = 850)
Output: 0->5->8
Conditions: integer bounds, operations cant exceed INT_MAX. 
Algorithm: Straightforward, simple un-reversing and re-reversing with regular integer addition. Not very clever. 
*/
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
public:
    int val;
    ListNode *next;  
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0;
        int num2 = 0;
        int counter = 0;
        while (l1 != NULL) {
            num1 += (l1->val * pow(10, counter));
            l1 = l1->next;
            ++counter;
        }
        counter = 0;
        while (l2 != NULL) {
            num2 += (l2->val * pow(10, counter));
            l2 = l2->next;
            ++counter;
        }
        int tot = num1 + num2;
        ListNode* ret1 = new ListNode();
        ret1->next = NULL;
        ret1->val = tot % 10;
        ListNode* ret = ret1; 
        tot /= 10;
        int tot2 = tot;
        int k = 0;
        while (tot2 >= 1) {
            k++;
            tot2 /= 10;
        }
        cout << k << endl;
        for (int i = 0; i < k; i++) {
            ListNode* ret2 = new ListNode(); 
            int s = tot % 10;
            tot /= 10;
            ret2->val = s;
            ret2->next = NULL;
            ret1->next = ret2;
            ret1 = ret2; 
        }
        return ret;
    }
};


int main() {
    Solution A;
    ListNode* out1 = NULL;
    ListNode* out2 = NULL;
    ListNode* out3 = NULL;
    ListNode* bout1 = NULL;
    ListNode* bout2 = NULL;
    ListNode* n = NULL;
    n = new ListNode();
    out1 = new ListNode();
    out2 = new ListNode();
    out3 = new ListNode();
    bout1 = new ListNode();
    bout2 = new ListNode();
    out1->val = 3;
    out1->next = out2;
    out2->val = 9;
    out2->next = out3;
    out3->val = 7;
    out3->next = NULL;
    bout1->val = 7;
    bout1->next = bout2;
    bout2->val = 5;
    bout2->next = NULL;
    n = A.addTwoNumbers(out1, bout1);
    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;
    }
}
