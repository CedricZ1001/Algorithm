#include <iostream>
using namespace std;

/*思路与算法

由于输入的两个链表都是逆序存储数字的位数的，因此两个链表中同一位置的数字可以直接相加。

我们同时遍历两个链表，逐位计算它们的和，并与当前位置的进位值相加。具体而言，如果当前两个链表处相应位置的数字为 n1,n2n1,n2n1,n2，进位值为 carry\textit{carry}carry，则它们的和为 n1+n2+carryn1+n2+\textit{carry}n1+n2+carry；其中，答案链表处相应位置的数字为 (n1+n2+carry) mod 10(n1+n2+\textit{carry}) \bmod 10(n1+n2+carry)mod10，而新的进位值为 ⌊n1+n2+carry10⌋\lfloor\frac{n1+n2+\textit{carry}}{10}\rfloor⌊ 
10
n1+n2+carry
​
 ⌋。

如果两个链表的长度不同，则可以认为长度短的链表的后面有若干个 000 。

此外，如果链表遍历结束后，有 carry>0\textit{carry} > 0carry>0，还需要在答案链表的后面附加一个节点，节点的值为 carry\textit{carry}carry。
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0),next(NULL){}
	ListNode(int x) : val(x), next(NULL){}
	ListNode(int x, ListNode *next) : val(x), next(next){}
}; 

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
    
    
};

