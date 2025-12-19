#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/* 基于链表实现的队列 */
typedef struct {
    ListNode *front, *rear;
    int queSize;
} LinkedListQueue;

/* 构造函数 */
LinkedListQueue *newLinkedListQueue() {
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

/* 析构函数 */
void delLinkedListQueue(LinkedListQueue *queue) {
    // 释放所有节点
    while (queue->front != NULL) {
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    // 释放 queue 结构体
    free(queue);
}

/* 获取队列的长度 */
int size(LinkedListQueue *queue) {
    return queue->queSize;
}

/* 判断队列是否为空 */
bool empty(LinkedListQueue *queue) {
    return (size(queue) == 0);
}

/* 入队 */
void push(LinkedListQueue *queue, int num) {
    // 尾节点处添加 node
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = num;
    node->next = NULL;
    // 如果队列为空，则令头、尾节点都指向该节点
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    }
    // 如果队列不为空，则将该节点添加到尾节点后
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queSize++;
}

/* 访问队首元素 */
int peek(LinkedListQueue *queue) {
    assert(size(queue) && queue->front);
    return queue->front->val;
}

/* 出队 */
int pop(LinkedListQueue *queue) {
    int num = peek(queue);
    ListNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->queSize--;
    return num;
}

/* 打印队列 */
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
}
    
void printLinkedListQueue(LinkedListQueue *queue) {
    int *arr = malloc(sizeof(int) * queue->queSize);
    // 拷贝链表中的数据到数组
    int i;
    ListNode *node;
    for (i = 0, node = queue->front; i < queue->queSize; i++) {
        arr[i] = node->val;
        node = node->next;
    }
    printArray(arr, queue->queSize);
    free(arr);
}

int main(){

}