template <class T>
class Queue {
private:
	int front, rear, capacity;
	T* arr;
	void DoubleCapacity() {
		capacity *= 2;
		T* newarr = new T[capacity];
		for (int i = 0; i < capacity / 2; i++) {
			if (i <= rear) newarr[i] = arr[i];
			if (i > rear) newarr[i + capacity / 2] = arr[i];
		}
		delete[]arr;
		arr = newarr;
		if (front > rear) front = front + capacity / 2;
	}
public:
	Queue() {
		capacity = 2;
		front = rear = 0;
		arr = new T[capacity];
	}
	bool Empty() {
		return front == rear;
	}
	void Push(T value) {
		if ((rear + 1) % capacity == front) DoubleCapacity();
		rear = (rear + 1) % capacity;
		arr[rear] = value;
	}
	void Pop() {
		if (Empty()) return;
		front = (front + 1) % capacity;
	}
	T Front() {	//front is always empty
		if (!Empty()) return arr[(front + 1) % capacity]; //front+1 is the real first one
	}
	T Rear() {
		if (!Empty()) return arr[rear];
	}
};
