#pragma once

#include "../base/sita_base.h"


namespace sita {

class StringUtil {
public:
	static void binToHex(String& result, const u8* data, size_t dataSize) {
		result.clear();
		appendBinToHex(result, data, dataSize);
	}

	static void appendBinToHex(String& result, const u8* data, size_t dataSize);
};

} // namespace

inline
std::ostream& operator<<(std::ostream& s, const sita::StrView& v) {
	s.write(v.data(), v.size());
	return s;
}

