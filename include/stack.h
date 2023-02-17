#pragma once

template <class T>
class Stack {
private:
	T* data;
	size_t size;
	int index = -1;
public:
	Stack(size_t sz = 1) : size(sz)
	{
		if (sz <= 0)
			throw std::exception("Uncorrectly length");
		data = new T[size]();
	}

	Stack(const Stack<T>& a)
	{
		index = a.index;
		size = a.size;
		data = new T[size]();
		for (size_t i = 0; i <= a.index; i++)
			data[i] = a.data[i];
	}

	bool isFull() noexcept
	{
		return index == size - 1;
	}

	bool isEmpty() noexcept
	{
		return index == -1;
	}

	void push(T Elem)
	{
		if (isFull())
		{
			Stack<T> tmp(*this);
			delete[] data;
			size *= 2;
			data = new T[size]();
			for (size_t i = 0; i <= index; i++)
				data[i] = tmp.data[i];
		}
		data[++index] = Elem;
	}

	T& pop()
	{
		if (this->isEmpty())
			throw std::exception("isEmpty: stack_is_empty");
		return data[index--];
	}

	T& view_top()
	{
		if (this->isEmpty())
			throw std::exception("view_top: stack_is_empty");
		return data[index];
	}

	size_t GetLength()
	{
		return index + 1;
	}

	void Clear()
	{
		index = -1;
	}

	~Stack() { delete[] data; }
};