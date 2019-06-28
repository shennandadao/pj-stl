#ifndef _STACK_H
#define _STACK_H

#include"deque.h"

template<class _Ty, class _C = deque<_Ty> >
class stack 
{
public:
	typedef _C::allocator_type allocator_type;
	typedef _C::value_type value_type;
	typedef _C::size_type size_type;

	explicit stack(const allocator_type& _Al = allocator_type())
		: c(_Al) 
	{}
	allocator_type get_allocator() const
	{return (c.get_allocator()); }
	bool empty() const
	{return (c.empty()); }
	size_type size() const
	{return (c.size()); }
	value_type& top()
	{return (c.back()); }
	const value_type& top() const
	{return (c.back()); }
	void push(const value_type& _X)
	{c.push_back(_X); }
	void pop()
	{c.pop_back(); }
	bool operator==(const stack<_Ty, _C>& _X) const
	{return (c == _X.c); }
	bool operator!=(const stack<_Ty, _C>& _X) const
	{return (!(*this == _X)); }
	bool operator<(const stack<_Ty, _C>& _X) const
	{return (c < _X.c); }
	bool operator>(const stack<_Ty, _C>& _X) const
	{return (_X < *this); }
	bool operator<=(const stack<_Ty, _C>& _X) const
	{return (!(_X < *this)); }
	bool operator>=(const stack<_Ty, _C>& _X) const
	{return (!(*this < _X)); }
protected:
	_C c;
};

#endif