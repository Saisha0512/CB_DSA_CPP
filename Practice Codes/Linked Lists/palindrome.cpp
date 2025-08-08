#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};
//complete the function below
//donot modify the main function

bool isPalindrome(ListNode* head) {
    // Empty LL or LL with only one node : 
    if (head == NULL || head -> next == NULL){
        return true;
    }
    // Finding the midpoint of LL : 
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    // Reversing the second half of the LL : 
    ListNode *prev = NULL;
    ListNode *next = slow;
    while (slow != NULL){
        next = slow -> next;
        slow -> next = prev;
        prev = slow;
        slow = next;
    }
    // Checking for Palindrome : 
    ListNode *a = head;
    ListNode *b = prev;
    while (a != NULL && b != NULL){
        if (a -> val != b -> val){
            return false;
        }
        a = a -> next;
        b = b -> next;
    }

    return true;
}


ListNode* createLinkedList(vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    ListNode* head = createLinkedList(values);
    cout << (isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}
