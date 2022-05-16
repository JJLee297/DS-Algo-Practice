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
        ListNode* ret = new ListNode(); 
        ListNode* ret1 = ret;
        int carry = 0;
        int first = 0;
        int second = 0;
        if (l1 != NULL) {
            first = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            second = l2->val;
            l2 = l2->next;
        }
        cout << "first: " << first << "\nsecond: " << second << "\ncarry: " << carry << endl;
        ret1->val = (first + second + carry) % 10;
        if (first + second + carry > 9)
            carry = 1;
        else
            carry = 0;
        while ((l1 != NULL || l2 != NULL) || carry == 1) {
            ListNode* ret2 = new ListNode();
            ret1->next = ret2;
            ret2->next = NULL;
            ret1 = ret2;
            first = 0;
            second = 0;
            if (l1 != NULL) {
                first = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                second = l2->val;
                l2 = l2->next;
            }
            cout << "first: " << first << "\nsecond: " << second << "\ncarry: " << carry << endl;
            ret2->val = (first + second + carry) % 10;
            if (first + second + carry > 9)
                carry = 1;
            else
                carry = 0;
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
