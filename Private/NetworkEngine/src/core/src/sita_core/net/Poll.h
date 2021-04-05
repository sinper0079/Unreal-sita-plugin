#pragma once

#include "../base/sita_base.h"

namespace sita {

enum class PollFlags : i16 {
	None	= 0,
	In		= POLLIN,
	Out		= POLLOUT,
	InOut	= POLLIN | POLLOUT,
	Error	= POLLERR,
	PRI		= POLLPRI,
	Hup		= POLLHUP,
	Invalid = POLLNVAL,
};

SITA_ENUM_BITWISE_OPERATOR(PollFlags)

#if SITA_OS_WINDOWS
	using PollFd = ::WSAPOLLFD;
	inline int Poll(PollFd* fds, size_t fds_size, int timeoutMilliseconds) {
		int ret = ::WSAPoll(fds, fds_size, timeoutMilliseconds);
		return ret;
	}
#else
	using PollFd = ::pollfd;
	inline int Poll(Span<PollFd> fdArray, int timeoutMilliseconds) {
		int ret = ::poll(fds.data(), fds.size(), timeoutMilliseconds);
		return ret;
	}
#endif


} // namespace
