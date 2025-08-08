# include <iostream>
# include <vector>
# include <queue>
using namespace std;

class Node {
public : 
    int val;
    Node *next;

    Node (int x){
        val = x;
        next = NULL;
    }
};

Node* buildLL(int n){
    Node *head = NULL;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        Node *node = new Node(x);
        if (head == NULL){
            head = node;
        }
        else {
            Node *temp = head;
            while (temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = node;
        }
    }
    return head;
}

typedef pair<int, pair<Node*, Node*>> QueueElement;

Node* mergeKSortedLLs(vector<Node*> arr){
    Node *root = NULL, *tail = NULL;
    priority_queue<QueueElement, vector<QueueElement>, greater<QueueElement>> pq;
    // Pushing all the 0th elements in the heap
    for (int i = 0; i < arr.size(); i ++){
        pq.push({arr[i] -> val, {arr[i], arr[i] -> next}});
    }

    while (!pq.empty()){
        QueueElement curr = pq.top();
        pq.pop();
        Node *element = curr.second.first;
        Node *nextnode = curr.second.second;
        if (root == NULL){
            root = element;
            tail = element;
        }
        else {
            tail -> next = element;
            tail = tail -> next;
        }

        if (nextnode != NULL){
            pq.push({nextnode -> val, {nextnode, nextnode -> next}});
        }
    }
    return root;
}

void printLL(Node* root){
    while (root != NULL){
        cout << root -> val << " ";
        root = root -> next;
    }
}

int main(){
    int k, n;
    cin >> k >> n;
    vector<Node*> arr(k);
    for (int i = 0; i < k; i ++){
        arr[i] = buildLL(n);
    }
    Node *head = mergeKSortedLLs(arr);
    printLL(head);
    return 0;
}