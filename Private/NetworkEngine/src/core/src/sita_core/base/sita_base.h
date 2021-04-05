#pragma once

#include "../detect_platform/sita_detect_platform.h"

#if SITA_OS_WINDOWS
	#ifdef NOMINMAX
	#undef NOMINMAX
	#define NOMINMAX 1  
	#endif
	//#define NOMINMAX 1

	#include <WinSock2.h> // WinSock2.h must include before windows.h to avoid winsock1 define
	#include <ws2tcpip.h> // struct sockaddr_in6
	#pragma comment(lib, "Ws2_32.lib")

	#include <Windows.h>
	#undef min
	#undef max
	//#undef TEXT
#else
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netdb.h>
	#include <netinet/in.h> // struct sockaddr_in
#endif

#include <cassert>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <string.h>
#include <string_view>
#include "chrono"
#include "sita_macro.h"



namespace sita {

template<class T> inline constexpr typename std::underlying_type<T>::type         enumInt   (      T  value) { return       static_cast<      typename std::underlying_type<T>::type >( value); }
template<class T> inline constexpr typename std::underlying_type<T>::type       & enumIntRef(      T& value) { return *reinterpret_cast<      typename std::underlying_type<T>::type*>(&value); }
template<class T> inline constexpr typename std::underlying_type<T>::type const & enumIntRef(const T& value) { return *reinterpret_cast<const typename std::underlying_type<T>::type*>(&value); }

template<class T> inline bool constexpr enumHas		(const T& a, const T& b) { return static_cast<T>(enumInt(a) & enumInt(b)) != static_cast<T>(0); }

template<class T> SITA_INLINE T* constCast(const T* v) { return const_cast<T*>(v); }
template<class T> SITA_INLINE T& constCast(const T& v) { return const_cast<T&>(v); }

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

// using f16 = half;
using f32 = float;
using f64 = double;
using f128 = long double;

template<class T> using UPtr = std::unique_ptr<T>;
template<class T> using SPtr = std::shared_ptr<T>;
template<class T> using WPtr = std::weak_ptr<T>;

//template<class T> using Span   = std::span<T>;


template<class T> using Vector = std::vector<T>;

template<class T> using StrViewT = std::basic_string_view<T>;
using StrView = StrViewT<char>;



using String = std::string;


//! Source Location
class SrcLoc {
public:
	SrcLoc() = default;
	SrcLoc(const char* file_, int line_, const char* func_) 
		: file(file_)
		, func(func_)
		, line(line_)
	{}

	const char* file = "";
	const char* func;
	int line = 0;
};

class NonCopyable {
public:
	NonCopyable() = default;

private:
	NonCopyable(NonCopyable &&) {}

	NonCopyable(const NonCopyable&) = delete;
	void operator=(const NonCopyable&) = delete;
};

} // namespace
