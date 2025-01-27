#pragma once

template<typename T>
struct Node
{
	// Things in a struct are always public
public:
	Node<T>();
	Node<T>(T value);
	~Node<T>() = default; // This sets it as the default destructor


public:
	T value;
	Node<T>* next;
	Node<T>* previous;
};

template<typename T>
inline Node<T>::Node() : next(nullptr), previous(nullptr)
{
}

template<typename T>
inline Node<T>::Node(T value) : next(nullptr), previous(nullptr), value(value)
{
}