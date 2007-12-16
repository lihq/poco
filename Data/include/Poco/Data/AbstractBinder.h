//
// AbstractBinder.h
//
// $Id: //poco/Main/Data/include/Poco/Data/AbstractBinder.h#12 $
//
// Library: Data
// Package: DataCore
// Module:  AbstractBinder
//
// Definition of the AbstractBinder class.
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


#ifndef Data_AbstractBinder_INCLUDED
#define Data_AbstractBinder_INCLUDED


#include "Poco/Data/Data.h"
#include <vector>
#include <cstddef>


namespace Poco {


class DateTime;
class Any;
class DynamicAny;


namespace Data {


class Date;
class Time;
class BLOB;


enum NullData
{
	NULL_GENERIC = 0
};


static const NullData null = NULL_GENERIC;


class Data_API AbstractBinder
	/// Interface for Binding data types to placeholders.
{
public:
	enum Direction
		/// Binding direction for a parameter.
	{
		PD_IN,
		PD_OUT,
		PD_IN_OUT
	};

	AbstractBinder();
		/// Creates the AbstractBinder.

	virtual ~AbstractBinder();
		/// Destroys the AbstractBinder.

	virtual void bind(std::size_t pos, const Poco::Int8& val, Direction dir = PD_IN) = 0;
		/// Binds an Int8.

	virtual void bind(std::size_t pos, const std::vector<Poco::Int8>& val, Direction dir = PD_IN);
		/// Binds an Int8 vector.

	virtual void bind(std::size_t pos, const Poco::UInt8& val, Direction dir = PD_IN) = 0;
		/// Binds an UInt8.

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt8>& val, Direction dir = PD_IN);
		/// Binds an UInt8 vector.

	virtual void bind(std::size_t pos, const Poco::Int16& val, Direction dir = PD_IN) = 0;
		/// Binds an Int16.

	virtual void bind(std::size_t pos, const std::vector<Poco::Int16>& val, Direction dir = PD_IN);
		/// Binds an Int16 vector.

	virtual void bind(std::size_t pos, const Poco::UInt16& val, Direction dir = PD_IN) = 0;
		/// Binds an UInt16.

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt16>& val, Direction dir = PD_IN);
		/// Binds an UInt16 vector.

	virtual void bind(std::size_t pos, const Poco::Int32& val, Direction dir = PD_IN) = 0;
		/// Binds an Int32.

	virtual void bind(std::size_t pos, const std::vector<Poco::Int32>& val, Direction dir = PD_IN);
		/// Binds an Int32 vector.

	virtual void bind(std::size_t pos, const Poco::UInt32& val, Direction dir = PD_IN) = 0;
		/// Binds an UInt32.

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt32>& val, Direction dir = PD_IN);
		/// Binds an UInt32 vector.
		
	virtual void bind(std::size_t pos, const Poco::Int64& val, Direction dir = PD_IN) = 0;
		/// Binds an Int64.

	virtual void bind(std::size_t pos, const std::vector<Poco::Int64>& val, Direction dir = PD_IN);
		/// Binds an Int64 vector.

	virtual void bind(std::size_t pos, const Poco::UInt64& val, Direction dir = PD_IN) = 0;
		/// Binds an UInt64.

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt64>& val, Direction dir = PD_IN);
		/// Binds an UInt64 vector.

#ifndef POCO_LONG_IS_64_BIT
	virtual void bind(std::size_t pos, const long& val, Direction dir = PD_IN) = 0;
		/// Binds a long.

	virtual void bind(std::size_t pos, const std::vector<long>& val, Direction dir = PD_IN);
		/// Binds a long vector.
#endif

	virtual void bind(std::size_t pos, const bool& val, Direction dir = PD_IN) = 0;
		/// Binds a boolean.

	virtual void bind(std::size_t pos, const std::vector<bool>& val, Direction dir = PD_IN);
		/// Binds a boolean vector.

	virtual void bind(std::size_t pos, const float& val, Direction dir = PD_IN) = 0;
		/// Binds a float.

	virtual void bind(std::size_t pos, const std::vector<float>& val, Direction dir = PD_IN);
		/// Binds a float vector.

	virtual void bind(std::size_t pos, const double& val, Direction dir = PD_IN) = 0;
		/// Binds a double.

	virtual void bind(std::size_t pos, const std::vector<double>& val, Direction dir = PD_IN);
		/// Binds a double vector.

	virtual void bind(std::size_t pos, const char& val, Direction dir = PD_IN) = 0;
		/// Binds a single character.

	virtual void bind(std::size_t pos, const std::vector<char>& val, Direction dir = PD_IN);
		/// Binds a character vector.

	virtual void bind(std::size_t pos, const char* const& pVal, Direction dir = PD_IN) = 0;
		/// Binds a const char ptr.

	virtual void bind(std::size_t pos, const std::string& val, Direction dir = PD_IN) = 0;
		/// Binds a string.

	virtual void bind(std::size_t pos, const std::vector<std::string>& val, Direction dir = PD_IN);
		/// Binds a string vector.

	virtual void bind(std::size_t pos, const BLOB& val, Direction dir = PD_IN) = 0;
		/// Binds a BLOB.

	virtual void bind(std::size_t pos, const std::vector<BLOB>& val, Direction dir = PD_IN);
		/// Binds a BLOB vector.

	virtual void bind(std::size_t pos, const DateTime& val, Direction dir = PD_IN) = 0;
		/// Binds a DateTime.

	virtual void bind(std::size_t pos, const std::vector<DateTime>& val, Direction dir = PD_IN);
		/// Binds a DateTime vector.

	virtual void bind(std::size_t pos, const Date& val, Direction dir = PD_IN) = 0;
		/// Binds a Date.

	virtual void bind(std::size_t pos, const std::vector<Date>& val, Direction dir = PD_IN);
		/// Binds a Date vector.

	virtual void bind(std::size_t pos, const Time& val, Direction dir = PD_IN) = 0;
		/// Binds a Time.

	virtual void bind(std::size_t pos, const std::vector<Time>& val, Direction dir = PD_IN);
		/// Binds a Time vector.

	virtual void bind(std::size_t pos, const NullData& val, Direction dir = PD_IN) = 0;
		/// Binds a null.

	virtual void bind(std::size_t pos, const std::vector<NullData>& val, Direction dir = PD_IN);
		/// Binds a null vector.

	void bind(std::size_t pos, const Any& val, Direction dir = PD_IN);
		/// Binds an Any.
	
	void bind(std::size_t pos, const DynamicAny& val, Direction dir = PD_IN);
		/// Binds a DynamicAny.

	virtual void reset();
		/// Resets a binder. No-op by default. Implement for binders that cache data.

	static bool isOutBound(Direction dir);
		/// Returns true if direction is out bound;

	static bool isInBound(Direction dir);
		/// Returns true if direction is in bound;
};


//
// inlines
//
inline void AbstractBinder::reset()
{
	//no-op
}


inline bool AbstractBinder::isOutBound(Direction dir)
{
	return PD_OUT == dir || PD_IN_OUT == dir;
}


inline bool AbstractBinder::isInBound(Direction dir)
{
	return PD_IN == dir || PD_IN_OUT == dir;
}


} } // namespace Poco::Data


#endif // Data_AbstractBinder_INCLUDED
