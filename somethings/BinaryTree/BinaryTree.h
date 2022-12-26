#ifndef __BINARYTREE__H__
#define __BINARYTREE__H__

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef char BinaryType;

typedef struct BinaryTreeNode
{
	BinaryTreeNode(BinaryType key)
		: _left(nullptr)
		, _right(nullptr)
		, _data(key)
	{}	
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;
    BinaryType _data;
}BTNode;

void PrevOrder(BTNode* root)
{
    stack<BTNode*> st;
    BTNode* cur = root;
    while (cur || !st.empty())
    {
        while (cur)
        {
            cout << (char)cur->_data << endl;
            st.push(cur);
            cur = cur->_left;
        }

        BTNode* top = st.top();
        st.pop();
        cur = top->_right;
    }
}

void PostOrder(BTNode* root)
{
    stack<BTNode*> st;
    BTNode* cur = root;
    BTNode* prev = nullptr;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->_left;
        }

        BTNode* top = st.top();
        if (top->_right == nullptr || top->_right == prev)
        {
            st.pop();
            cout << (char)top->_data << endl;
            prev = top;
        }
        else
        {
            cur = top->_right;
        }
    }
}

void InOrder(BTNode* root)
{
    stack<BTNode*> st;

    BTNode* cur = root;
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->_left;
        }
     
        BTNode* top = st.top();
        st.pop();
        cout << (char)top->_data << endl;
        cur = top->_right;
    }
}

void LevelOrder(BTNode* root)
{
    if (root == nullptr)
        return;
    queue<BTNode*> q;
    q.push(root);
    while (!q.empty())
    {
        BTNode* front = q.front();
        q.pop();
        cout << (char)front->_data << endl;
        if (front->_left)
            q.push(front->_left);
        if (front->_right)
            q.push(front->_right);
    }
}

#endif // !__BINARYTREE__H__
