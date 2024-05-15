#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "DataStructure.hpp"

template <typename T>
class DynmicArray
{
private:
	T* array;
	int size;
	int capacity;

	void resize();
	
public:
	DynamicArray();
	~DynamicArray();

	void addFront(const T& value);
	void addBack(const T& value);
	void add(const int& index,const T& value);	
	
	void removeFront();
	void removeBack();
	void remove(const int& index);
	
	void loadFromFile(const std::string& fileName);
	int find(const T& value) const override;

};

template <typename T>
void DynmicArray<T>::resize()
{
	capacity *= 2;
	T* newArray = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}

template <typename T>
DynmicArray<T>::DynamicArray()
{
	size = 0;
	capacity = 10;
	array = new T[capacity];
}

template <typename T>
DynmicArray<T>::~DynamicArray()
{
	delete[] array;
}

template <typename T>
void DynmicArray<T>::addFront(const T& value)
{
	if (size == capacity)
	{
		resize();
	}
	for (int i = size; i > 0; i--)
	{
		array[i] = array[i - 1];
	}
	array[0] = value;
	size++;
}

template <typename T>
void DynmicArray<T>::addBack(const T& value)
{
	if (size == capacity)
	{
		resize();
	}
	array[size] = value;
	size++;
}

template <typename T>
void DynmicArray<T>::add(const int& index, const T& value)
{
	if (size == capacity)
	{
		resize();
	}
	for (int i = size; i > index; i--)
	{
		array[i] = array[i - 1];
	}
	array[index] = value;
	size++;
}

template <typename T>
void DynmicArray<T>::removeFront()
{
	if (size == 0) return;
	for (int i = 0; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	size--;
}

template <typename T>
void DynmicArray<T>::removeBack()
{
	if (size>0)
		size--;
}

template <typename T>
void DynmicArray<T>::remove(const int& index)
{
	if (index < 0 || index >= size)
	{
		std::cerr << "error: index out of range\n";
		return;
	}
	for (int i = index; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
}

template <typename T>
void DynmicArray<T>::loadFromFile(const std::string& fileName)
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			if (ss>>value)
							{
				addBack(value);
			}
			else {
				std::cerr << "error: invalid value\n";
			}
		}
		file.close();
	}
}

template <typename T>
int DynmicArray<T>::find(const T& value) const
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

#endif // !DYNAMICARRAY_HPP
