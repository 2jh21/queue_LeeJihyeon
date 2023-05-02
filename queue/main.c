#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return;
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q) {
	printf("\nQUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d  ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("\nQueue Full!");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("\nQueue Empty!");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


int main() {
	QueueType q;
	int element, choice;
	init_queue(&q);


	while (1) {
		printf("===== Menu ====\n");
		printf("1. Input data and Enqueue\n");
		printf("2. Dequeue and Print data\n");
		printf("3. Print Queue\n");
		printf("4. Exit\n");
		printf("Select number: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("\nInput the data: ");
			scanf_s("%d", &element);
			enqueue(&q, element);
			if (!is_empty(&q)) {
				printf("Enqueue: %d\n", element);
			}
			break;

		case 2:
			if (is_empty(&q)) {
				printf("\nQueue Empty!\n");
			}
			else {
				element = dequeue(&q);
				printf("\nDequeue: %d\n", element);
			}
			break;

		case 3:
			queue_print(&q);
			break;

		case 4:
			return 0;

		default:
			printf("Invalid Choice.\n");
		}
		printf("\n");
	}

}