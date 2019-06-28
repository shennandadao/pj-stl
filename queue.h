#ifndef _QUEUE_H
#define _QUEUE_H

#include"deque.h"

template<class _Ty, class _C = deque<_Ty> >
class queue 
{
public:
	typedef _C::allocator_type allocator_type;
	typedef _C::value_type value_type;
	typedef _C::size_type size_type;
	explicit queue(const allocator_type& _Al = allocator_type())
		: c(_Al) {}
	allocator_type get_allocator() const
	{return (c.get_allocator()); }
	bool empty() const
	{return (c.empty()); }
	size_type size() const
	{return (c.size()); }
	value_type& front()
	{return (c.front()); }
	const value_type& front() const
	{return (c.front()); }
	value_type& back()
	{return (c.back()); }
	const value_type& back() const
	{return (c.back()); }
	void push(const value_type& _X)
	{c.push_back(_X); }
	void pop()
	{c.pop_front(); }
	bool operator==(const queue<_Ty, _C>& _X) const
	{return (c == _X.c); }
	bool operator!=(const queue<_Ty, _C>& _X) const
	{return (!(*this == _X)); }
	bool operator<(const queue<_Ty, _C>& _X) const
	{return (c < _X.c); }
	bool operator>(const queue<_Ty, _C>& _X) const
	{return (_X < *this); }
	bool operator<=(const queue<_Ty, _C>& _X) const
	{return (!(_X < *this)); }
	bool operator>=(const queue<_Ty, _C>& _X) const
	{return (!(*this < _X)); }
protected:
	_C c;
};

#endif