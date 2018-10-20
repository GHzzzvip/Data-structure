#include<bits/stdc++.h>
using namespace std;

typedef struct ListNode{
    struct ListNode *Lchild, *Rchild;
    string str;
    ListNode():Lchild(nullptr), Rchild(nullptr){}
}ListNode;

ListNode* create()
{
    ListNode *q = nullptr;
    string str;
    cin >> str;
    if(str[0]!='#') {
        q = new ListNode;
        q->str += str;
        q->Lchild = create();
        q->Rchild = create();
    }
    return q;
}
void preOrder(ListNode *node) {
    if(node) {
        cout <<" " <<node->str;
        preOrder(node->Lchild);
        preOrder(node->Rchild);
    }
}

void preOrderInStack(ListNode * node) {
    if(node) {
        stack<ListNode *> stk;
        stk.push(node);
        while(stk.size()) {
            ListNode *tmp = stk.top();
            cout << " " << tmp->str;
            stk.pop();
            if(tmp -> Rchild != nullptr) stk.push(tmp -> Rchild);
            if(tmp -> Lchild != nullptr) stk.push(tmp -> Lchild);
        }
    }
}

void inOrder(ListNode *node) {
    if(node) {
        inOrder(node->Lchild);
        cout << " " << node->str;
        inOrder(node->Rchild);
    }
}
void inOrderInStack(ListNode *node) {
    if(node != nullptr) {
        stack<ListNode *> stk;
        stk.push(node);
        while(stk.size()) {
            while((stk.top())->Lchild != nullptr) stk.push((stk.top())->Lchild);

            while(stk.size()) {
                ListNode *tmp = stk.top();
                cout << " " << tmp -> str;
                stk.pop();
                if(tmp -> Rchild != nullptr) {
                    stk.push(tmp->Rchild);
                    break;
                }
            }
        }
    }
}

void lastOrder(ListNode *node) {
    if(node) {
        lastOrder(node->Lchild);
        lastOrder(node->Rchild);
        cout << " " << node->str;
    }
}

void lastOrderInStack(ListNode *node) {
    if(node != nullptr) {
        stack<ListNode *> stk;
        stk.push(node);
        ListNode *lastpop = nullptr;
        while(stk.size()) {
            while((stk.top())->Lchild != nullptr) stk.push((stk.top())->Lchild);
            while(stk.size()) {
                ListNode *tmp = stk.top();
                if(tmp->Rchild != nullptr &&tmp->Rchild != lastpop) {
                    stk.push(tmp->Rchild);
                    break;
                } else {
                    lastpop = tmp;
                    cout << " " << tmp->str;
                    stk.pop();
                }
            }
        }
    }
}
void SeqOrder(ListNode *node) {
    if(node) {
        queue <ListNode *> q;
        q.push(node);
        while(q.size()) {
            ListNode *tmp = q.front();
            q.pop();
            cout << " " << tmp->str;
            if(tmp->Lchild != nullptr) q.push(tmp -> Lchild);
            if(tmp->Rchild != nullptr) q.push(tmp -> Rchild);
        }
    }
}

int main() {
    ListNode *p = NULL;
    cout << "先序输入一个二叉树结构，每个字符串为一个节点，#代表空节点" << endl;
    p = create();
    cout <<"preOrder        : ";
    preOrder(p);
    cout << endl;
    cout <<"preOrderInStack : ";
    preOrderInStack(p);
    cout << endl;

    cout << "inOrder         : ";
    inOrder(p);
    cout << endl;
    cout << "inOrderInStack  : ";
    inOrderInStack(p);
    cout << endl;

    cout << "lastOrder       : ";
    lastOrder(p);
    cout << endl;
    cout << "lastOrderInStack: ";
    lastOrderInStack(p);
    cout << endl;
    cout << "SeqOrder: ";
    SeqOrder(p);
    cout << endl;
    return 0;
}
//a b d h # # i # # e j # # k # # c f l # # m # # g n # # o # #
