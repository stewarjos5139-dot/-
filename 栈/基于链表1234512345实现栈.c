#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

#define INT_MAX 2147483647

/* 基于链表实现的栈 */
typedef struct {
    ListNode *top; // 将头节点作为栈顶（原因：链表的头节点方便操作）
    int size;      // 栈的长度
} LinkedListStack;

/* 构造函数 */
LinkedListStack *newLinkedListStack() {
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

/* 析构函数 （粉碎栈）*/
void delLinkedListStack(LinkedListStack *s) {
    while (s->top) {
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}

/* 获取栈的长度 */
int size(LinkedListStack *s) {
    return s->size;
}

/* 判断栈是否为空 */
bool isEmpty(LinkedListStack *s) {
    return size(s) == 0;
}

/* 入栈 */
void push(LinkedListStack *s, int num) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->next = s->top; // 更新新加节点指针域
    node->val = num;     // 更新新加节点数据域
    s->top = node;       // 更新栈顶
    s->size++;           // 更新栈大小
}

/* 访问栈顶元素 */
int peek(LinkedListStack *s) {
    if (s->size == 0) {
        printf("栈为空\n");
        return INT_MAX;
    }
    return s->top->val;
}

/* 出栈 */
int pop(LinkedListStack *s) {
    int val = peek(s);
    //tmp用于临时存储栈顶节点
    ListNode *tmp = s->top;
    s->top = s->top->next;
    // 释放内存
    free(tmp);
    s->size--;
    return val;
}
//打印整个栈
void printStack(LinkedListStack *s) {
    ListNode *current = s->top;
    printf("栈内容（从栈顶到栈底）：");
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

//实践操作
int main(){
    //DIY do it yourself!
    int i = 0;
    LinkedListStack *stack = newLinkedListStack();
    while (i<2000)
    {
        push(stack, i);
        i++;
    }
    printStack(stack);
}