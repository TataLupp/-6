#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>

class StackEmptyException : public std::exception
{
public:
	StackEmptyException() :
		exception("Stack is already empty")
	{}
};

template <class T>
class Vector
{
public:
	Vector()
	{
		this->size_ = 0;
		this->array_ = new T[this->size_];
	}

	~Vector()
	{
		delete[] array_;
		size_ = 0;
	}

	T operator [](int index)
	{
		return this->array_[index];
	}

	int size()
	{
		return this->size_;
	}

	void push(const T& data)
	{
		T* _result = new T[++this->size_];

		for (int i = 0; i < this->size_; i++)
		{
			if (i != this->size_ - 1)
			{
				_result[i] = this->array_[i];
			}
			else
			{
				_result[i] = data;
				break;
			}
		}
		delete[] this->array_;
		this->array_ = _result;
	}
	void showVector()
	{
		for (int i = 0; i < this->size_; i++)
			std::cout << array_[i] << "\n";
	}
	
	T pop()
	{
		if (size_ != 0)
		{
			return this->popIndex(this->size_ - 1);
		}
		else
		{
			throw StackEmptyException();
		}
	}

	T popIndex(int index)
	{
		T* _result = new T[--this->size_];

		T resItem;

		int resIndex = 0;

		for (int i = 0; i < this->size_ + 1; i++)
		{
			T item = this->array_[i];

			if (index == i)
			{
				resItem = item;
				continue;
			}
			_result[resIndex++] = this->array_[i];
		}
		delete[] this->array_;
		this->array_ = _result;
		return resItem;
	}
	Vector& operator=(const Vector& a)
	{
		delete this->array_;
		this->size_ = a.size_;

		this->array_ = new T[this->size_];
		for (int i = 0; i < this->size_; i++)
			this->array_[i] = a.array_[i];
		return *this;
	}
	void swap(const int& ind1, const int& ind2) {
		T temp1 = array_[ind1];
		T temp2 = array_[ind2];
		array_[ind1] = temp2;
		array_[ind2] = temp1;

	}
	
private:
	T* array_;
	int size_;
};