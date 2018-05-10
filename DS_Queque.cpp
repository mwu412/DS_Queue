template <class T>
class Queue {
private:
	int front, rear, capacity;
	T* arr;
	void DoubleCapacity() {
		capacity *= 2;
		T* newarr = new T[capacity];
		for (int i = 0; i < capacity / 2; i++) {
			newarr[i] = arr[i];
		}
		delete[]arr;
		arr = newarr;
	}
public:
	Queue() {
		capacity = 1;
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
		if ((front + 1) % capacity == rear) return;
		front = (front + 1) % capacity;
	}
	T Front() {	//front is always empty
		if (!Empty()) return arr[front + 1]; //front+1 is the real first one
	}
	T Rear() {
		if (!Empty()) return arr[rear];
	}
};
