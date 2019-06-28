#ifndef _VECTOR_H
#define _VECTOR_H

template<class _Ty,  class _A=allocator<_Ty> >
class vector
{
public:
	//ÝÍÈ¡
	typedef  _A::size_type           size_type;
	typedef  _A::difference_type     difference_type;
	typedef  _A::pointer             pointer;
	typedef  _A::const_pointer       const_pointer;
	typedef  _A::reference           reference;
	typedef  _A::const_reference     const_reference;
	typedef  _A::value_type          value_type;
	typedef  _A allocator_type;

	//typedef pointer iterator;
	typedef _Ty* iterator;
	typedef const _Ty* const_iterator;

	typedef iterator _It;
public:
	explicit vector(const _A &_A1=_A()) : allocator(_A1), _First(0),_Last(0),_End(0)
	{}
	explicit vector(size_type _N, const _Ty &_V=_Ty(), const _A &_A1=_A())
		:allocator(_A1)
	{
		_First = allocator.allocate(_N, (void*)0);
		_Ufill(_First, _N, _V);
		_Last = _First + _N;
		_End = _Last;
	}
	~vector()
	{
		_Destroy(_First, _Last);
		allocator.deallocate(_First, _End-_First);
		_First = _Last = _End = 0;
	}
public:
	iterator begin()
	{return _First;}
	iterator end()
	{return _Last;}
	size_type size()const
	{return _Last-_First;}
	size_type capacity()const
	{return _First==0 ? 0 : _End - _First;}
	bool empty()const
	{return size() == 0;}
	reference at(size_type _P)
	{
		if(_P >= size())
			_Xran();
		return *(begin() + _P);
	}
	reference operator[](size_type _P)
	{
		if(_P >= size())
			_Xran();
		return *(begin() + _P);
	}
	reference front()
	{return *begin();}
	reference back()
	{return *(end()-1);}
	void push_back(const _Ty &_X)
	{insert(end(), _X);}
	void pop_back()
	{erase(end()-1);}
	void assign(_It _F, _It _L);
	void assign(size_type _N, const _Ty &_X=_Ty())
	{
		erase(begin(), end());
		insert(begin(), _N, _X);
	}
	void clear()
	{
		erase(begin(), end());
	}
	void resize(size_type _N, const _Ty &_X=_Ty())
	{
		if(_N > size())
			insert(end(), _N-size(), _X);
		else if(_N < size())
			erase(begin()+_N, end());
	}
	void reserve(size_type _N)
	{
		if(_N > capacity())
		{
			iterator _S = allocator.allocate(_N, (void*)0);
			_Ucopy(_First, _Last, _S);
			_Destroy(_First, _Last);
			allocator.deallocate(_First, _End-_First);
			_End = _S + _N;
			_Last = _S + size();
			_First = _S;
		}
	}

public:
	iterator insert(iterator _P, const _Ty &_X=_Ty())
	{
		size_type _O = _P - begin();
		insert(_P, 1, _X);
		return begin() + _O;
	}
	void insert(iterator _P, size_type _M, const _Ty &_X)
	{
		if(_M > _End - _Last) //¿Õ¼ä²»×ã
		{
			size_type _N = size() + (_M<size() ? size() : _M); //
			iterator _S = allocator.allocate(_N, (void *)0);
			iterator _Q = _Ucopy(_First, _P, _S);
			_Ufill(_Q, _M, _X);
			_Ucopy(_P, _Last, _Q+_M);
			_Destroy(_First, _Last);
			allocator.deallocate(_First, _End-_First);
			_End = _S+_N;
			_Last = _S + size() +_M;
			_First = _S;
		}

		else if(_M > _Last - _P)
		{
			_Ucopy(_P, _Last, _P + _M);
			_Ufill(_Last, _M - (_Last - _P), _X);
			fill(_P, _Last, _X);
			_Last += _M;
		}
		else if(_M > 0)
		{
			_Ucopy(_Last - _M, _Last, _Last);
			copy_backward(_P, _Last - _M, _Last);
			fill(_P, _P + _M, _X);
			_Last += _M; 
		}
	}
	void insert(iterator _P, _It _F, _It _L);

	iterator erase(iterator _P)
	{
		copy(_P+1, end(), _P);
		_Destroy(_Last-1, _Last);
		--_Last;
		return _P;
	}
	iterator erase(iterator _F, iterator _L)
	{
		iterator _S = copy(_L, end(), _F);
		_Destroy(_S, end());
		_Last = _S;
		return _F;
	}

protected:
	void _Destroy(iterator _F, iterator _L)
	{
		for(; _F!=_L; ++_F)
			allocator.destroy(_F);
	}
	iterator _Ucopy(const_iterator _F, const_iterator _L, iterator _P)
	{
		for(; _F!=_L; ++_P, ++_F)
			allocator.construct(_P, *_F);
		return _P;
	}
	void _Ufill(iterator _F, size_type _N, const _Ty &_X)
	{
		for(; 0<_N; --_N, ++_F)
			allocator.construct(_F, _X);
	}
	void _Xran() const
	{
		_THROW(out_of_range, "invalid vector<bool> subscript"); 
	}
private:
	_A allocator;
	iterator _First, _Last, _End;
};

#endif