#pragma once

#include <iostream>
#include <list>
#include <exception>

template<class T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};


template<class T>
class PriorityQueue {
   
public:
	void push(const T& t); 
	T poll();

private:
	std::list<T>  m_queue;
};

template<class T>
inline void PriorityQueue<T>::push(const T& t)
{
	auto it = m_queue.begin();
	while (it != m_queue.end() && MyComparator<T>{}(*it, t) < 0) {
		++it;
	}
	m_queue.insert(it, t);
}

template<class T>
inline T PriorityQueue<T>::poll()
{
		if (m_queue.empty())
			throw std::runtime_error("PriorityQueue empty !");
		T value = m_queue.front();
		m_queue.pop_front();
		return value;	
}
