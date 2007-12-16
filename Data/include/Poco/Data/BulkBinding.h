//
// BulkBinding.h
//
// $Id: //poco/Main/Data/include/Poco/Data/BulkBinding.h#6 $
//
// Library: Data
// Package: DataCore
// Module:  BulkBinding
//
// Definition of the BulkBinding class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Data_BulkBinding_INCLUDED
#define Data_BulkBinding_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/Data/AbstractBinding.h"
#include "Poco/Data/DataException.h"
#include "Poco/Data/TypeHandler.h"
#include <vector>
#include <cstddef>


namespace Poco {
namespace Data {


template <class T>
class BulkBinding: public AbstractBinding
	/// A BulkBinding maps a value to a column. 
	/// Bulk binding support is provided only for std::vector.
{
public:
	explicit BulkBinding(const T& val, Poco::UInt32 bulkSize, const std::string& name = "", Direction direction = PD_IN): 
		AbstractBinding(name, direction, bulkSize), 
		_val(val), 
		_bound(false)
		/// Creates the BulkBinding.
	{
		if (0 == _val.size())
			throw InvalidArgumentException("Zero size containers not allowed.");
	}

	~BulkBinding()
		/// Destroys the BulkBinding.
	{
	}

	std::size_t numOfColumnsHandled() const
	{
		return 1;
	}

	std::size_t numOfRowsHandled() const
	{
		return _val.size();
	}

	bool canBind() const
	{
		return !_bound;
	}

	void bind(std::size_t pos)
	{
		poco_assert_dbg(getBinder() != 0);
		TypeHandler<T>::bind(pos, _val, getBinder(), getDirection());
		_bound = true;
	}

	void reset ()
	{
		_bound = false;
		getBinder()->reset();
	}

private:
	const T& _val;
	bool     _bound;
};


typedef void (*BulkFnType)();

template <typename T> 
BulkBinding<std::vector<T> >* use(const std::vector<T>& t, BulkFnType, const std::string& name = "")
	/// Convenience function for a more compact BulkBinding creation.
{
	return new BulkBinding<std::vector<T> >(t, static_cast<Poco::UInt32>(t.size()), name);
}


template <typename T> 
BulkBinding<std::vector<T> >* in(const std::vector<T>& t, BulkFnType, const std::string& name = "")
	/// Convenience function for a more compact BulkBinding creation.
{
	return new BulkBinding<std::vector<T> >(t, static_cast<Poco::UInt32>(t.size()), name);
}


} } // namespace Poco::Data


#endif // Data_BulkBinding_INCLUDED
