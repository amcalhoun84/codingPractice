#include <iostream>
#include <cstdlib>

using namespace std;

struct queue
{
	int *items;
	int maxsize;
	int front;
	int rear;
	int size;
};

struct queue* newQueue(int size)
{
	struct queue *pt = NULL;
	pt = (struct queue*)malloc(sizeof(struct queue));

	pt->items = (int*)malloc(size * sizeof(int));
	pt->maxsize = size;
	pt->front = 0;
	pt->rear = -1;
	pt->size = 0;

	return pt;
};

int getSize(struct queue *pt)
{
	return pt->size;
}

bool isEmpty(struct queue *pt)
{
	return !getSize(pt);
}

int front(struct queue *pt)
{
	if(isEmpty(pt))
	{
		cout << "Underflow... terminating program" << endl;
		exit(-1);
	}

	return pt->items[pt->front];
}


void enqueue(struct queue *pt, int x) 
{
	if(getSize(pt) == pt->maxsize) {
		cout << "Overflow... terminating program" << endl;
		exit(-1);
	}

	cout << "Inserting item: " << x << endl;

	pt->rear = (pt->rear + 1) % pt->maxsize;
	pt->items[pt->rear] = x;
	pt->size++;

	cout << "Front is: " << pt->front << ". Rear is: " << pt->rear << ".\n";
}

void dequeue(struct queue *pt)
{
	if(isEmpty(pt)) // front == rear
	{
		cout << "Underflow... terminating program." << endl;
		exit(-1);
	}

	cout << "Removing " << front(pt) << " from the queue." << endl;
	
	pt->front = (pt->front + 1) % pt->maxsize;
	pt->size--;

	cout << "Front is: " << pt->front << ". Rear is: " << pt->rear << ".\n";

}

//main

int main()
{
	struct queue *pt = newQueue(5);

    enqueue(pt, 1);
    enqueue(pt, 2);
    enqueue(pt, 3);
    enqueue(pt, 4);
    
    dequeue(pt);
    dequeue(pt);
    dequeue(pt);
    dequeue(pt);
  
    enqueue(pt, 5);
    enqueue(pt, 6);
    
    cout << "Size is : " << getSize(pt) << endl;
    
    if(isEmpty(pt)) cout << "Queue is empty." << endl;
    else cout << "Queue is not empty." << endl;
    
    return 0;

}
