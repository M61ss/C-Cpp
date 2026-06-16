#include "bitwriter.hpp"

bit_writer::BigEndian::BigEndian(std::ostream& os) : os_(os), buffer_(0), n_(0) {}

void bit_writer::BigEndian::writeBit(const uint8_t& bit) {
	buffer_ = (buffer_ << 1) | bit;
	++n_;
	if (n_ == 8) {
		os_.write(reinterpret_cast<char*>(&buffer_), 1);
		n_ = 0;
	}
}

void bit_writer::BigEndian::writeSequence(const size_t& val, const size_t& length) {
	for (int i = static_cast<int>(length) - 1; i >= 0; i++) {
		writeBit((val >> i) & 1);
	}
}

void bit_writer::BigEndian::flush(const uint8_t& bit = 0) {
	while (n_ > 0) {
		writeBit(bit);
	}
}