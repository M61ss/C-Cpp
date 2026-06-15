#include "bitreader.hpp"

uint8_t bit_reader::BigEndian::readBit() {
	if (n_ == 0) {
		is_.read(reinterpret_cast<char*>(&buffer_), 1);
		n_ = 8;
	}
	--n_;
	return (buffer_ >> n_) & 1;
}

size_t bit_reader::BigEndian::readSequence(const size_t& length) {
	size_t val = 0;
	for (size_t i = 0; i < length; i++) {
		val = (val << 1) | readBit();
	}
	return val;
}

void bit_reader::BigEndian::flush() {
	buffer_ = 0;
	n_ = 0;
}