#include "bitreader.hpp"

bit_reader::BigEndian::BigEndian(std::istream& is) : is_(is), buffer_(0), n_(0) {}

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

bit_reader::LittleEndian::LittleEndian(std::istream& is) : is_(is), buffer_(0), n_(0) {}

uint8_t bit_reader::LittleEndian::readBit() {
	if (n_ == 0) {
		is_.read(reinterpret_cast<char*>(&buffer_), 1);
		n_ = 8;
	}
	--n_;
	uint8_t bit = buffer_ & 1;
	buffer_ >>= 1;
	return bit;
}

size_t bit_reader::LittleEndian::readSequence(const size_t& length) {
	size_t val = 0;
	for (size_t i = 0; i < length; i++) {
		size_t bit = readBit();
		val |= bit << i;
	}
	return val;
}

void bit_reader::LittleEndian::flush() {
	buffer_ = 0;
	n_ = 0;
}