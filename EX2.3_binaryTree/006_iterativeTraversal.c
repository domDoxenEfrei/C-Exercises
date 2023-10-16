/*

You have at your disposal a void _log(int data) function, allowing you to log values in a precise order.

In this exercise, you'll need to use stacks. You have access to the structures and functions required to use stacks:

typedef struct Element {
Node* data;
struct Element* next;
} Element;
typedef struct Stack {
Element* stack_data;
} Stack;
Stack* create_stack();
void push(Stack* s, Node* val);
Node* pop(Stack* s);
int is_empty(Stack* s)
Code a void log_tree_preorder(Node* tree) function taking as input the root of a binary tree that will log the tree's values in prefixed order 
(left nodes being evaluated before right nodes) via an ITERATIVEALGORITHM, using stacks.
*/