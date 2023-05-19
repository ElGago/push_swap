#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* s) {
    s->top = NULL;
}

void destroyStack(Stack* s) {
    Node* temp;
    while (s->top != NULL) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int isStackEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int element) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    Node* temp;
    int data = s->top->data;
    temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

void swap(Stack* s) {
    int temp;
    if (s->top != NULL && s->top->next != NULL) {
        temp = s->top->data;
        s->top->data = s->top->next->data;
        s->top->next->data = temp;
    }
}

void rotate(Stack* s) {
    if (s->top != NULL && s->top->next != NULL) {
        Node* temp = s->top;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = s->top;
        s->top = s->top->next;
        temp->next->next = NULL;
    }
}

void reverseRotate(Stack* s) {
    if (s->top != NULL && s->top->next != NULL) {
        Node* temp = s->top;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next->next = s->top;
        s->top = temp->next;
        temp->next = NULL;
    }
}

void pushToStackB(Stack* a, Stack* b, int count) {
    for (int i = 0; i < count; i++) {
        push(b, pop(a));
        printf("pb\n");
    }
}

void pushToStackA(Stack* a, Stack* b, int count) {
    for (int i = 0; i < count; i++) {
        push(a, pop(b));
        printf("pa\n");
    }
}

void sort(Stack* a, Stack* b, int size) {
    if (size == 2) {
        if (a->top->data > a->top->next->data) {
            swap(a);
            printf("sa\n");
        }
    } else if (size == 3) {
        int first = a->top->data;
        int second = a->top->next->data;
        int third = a->top->next->next->data;

        if (first > second && first > third && second < third) {
            swap(a);
            printf("sa\n");
        } else if (first < second && first > third && second > third) {
            reverseRotate(a);
            printf("rra\n");
        } else if (first > second && first < third && second > third) {
            rotate(a);
            printf("ra\n");
        } else if (first > second && first > third && second > third) {
            swap(a);
            printf("sa\n");
            reverseRotate(a);
            printf("rra\n");
        } else if (first < second && first < third && second > third) {
            rotate(a);
            printf("ra\n");
        }
        if (b->top->data > b->top->next->data) {
            swap(b);
            printf("sb\n");
        }
        pushToStackA(a, b, 2);
        if (a->top->data > a->top->next->data) {
            swap(a);
            printf("sa\n");
        }
    } else {
        int count = 0;
        int pivot = a->top->data;

        for (Node* current = a->top; current != NULL; current = current->next) {
            if (current->data < pivot) {
                count++;
            }
        }

        pushToStackB(a, b, count);

        sort(a, b, count);

        pushToStackA(a, b, count);

        while (a->top->data != pivot) {
            rotate(a);
            printf("ra\n");
        }

        sort(a, b, size - count);

        while (!isStackEmpty(b)) {
            push(a, pop(b));
            printf("pa\n");
    }
    }
}


int main(int argc, char* argv[]) {
    Stack a, b;
    initializeStack(&a);
    initializeStack(&b);

    for (int i = 1; i < argc; i++) {
        push(&a, atoi(argv[i]));
    }

    sort(&a, &b, argc - 1);
    while (!isStackEmpty(&a))
        printf("%d, ", pop(&a));
        printf("\n");
    destroyStack(&a);
    destroyStack(&b);

    return 0;
}
