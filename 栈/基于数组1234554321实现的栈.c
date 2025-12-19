#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000


/* 基于数组（指针）实现的栈 */
typedef struct {
    int *data;
    int size;
} ArrayStack;

/* 构造函数 */
ArrayStack *newArrayStack() {
    ArrayStack *stack = malloc(sizeof(ArrayStack));
    // 初始化一个大容量，避免扩容
    stack->data = malloc(sizeof(int) * MAX_SIZE);
    stack->size = 0;
    return stack;
}

/* 析构（分解）函数 */
void delArrayStack(ArrayStack *stack) {
    free(stack->data);
    free(stack);
}

/* 获取栈的长度 */
int size(ArrayStack *stack) {
    return stack->size;
}

/* 判断栈是否为空 */
bool isEmpty(ArrayStack *stack) {
    return stack->size == 0;
}

/* 入栈 （巧妙，列表自动进位）*/
void push(ArrayStack *stack, int num) {
    if (stack->size == MAX_SIZE) {
        printf("栈已满\n");
        return;
    }
    stack->data[stack->size] = num;
    stack->size++;
}

/* 访问栈顶元素 */
//以列表末尾作为栈顶的原因是因为列表末尾方便添加和删除元素
int peek(ArrayStack *stack) {
    if (stack->size == 0) {
        printf("栈为空\n");
        return INT_MAX;
    }
    return stack->data[stack->size - 1];
}

/* 出栈 */
int pop(ArrayStack *stack) {
    int val = peek(stack);
    stack->size--;
    return val;
}

/* 测试栈的实现 */
int main() {
    //DIY
}
