#pragma once

#include "../string/String.h"

#define SITA_ERROR(...) Error(SITA_SRC_LOC,"error")

namespace sita {

class IError : public std::exception {
public:

};

class Error : public IError {
public:
//	Error() = default;
	Error(const SrcLoc& loc, StrView msg);

private:
	SrcLoc _loc;
	String _msg;
};


} // namespace