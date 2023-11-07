#pragma once

template<class T, class TPri = int>
struct Node
{
	T value;
	Node* next;
	TPri priority;

	Node(const T& value) : value(value), next(nullptr) {}
	Node(const T& value, const TPri& priority) : value(value), priority(priority), next(nullptr) {}

};
