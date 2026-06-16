#ifndef ELIAS_ENCODER_BITWRITER_H_
#define ELIAS_ENCODER_BITWRITER_H_

#include <fstream>

namespace bit_writer {
	class BigEndian {
	public:
		BigEndian(std::ostream& os);
		void writeBit(const uint8_t& bit);
		void writeSequence(const size_t& val, const size_t& length);
		void flush(const uint8_t& bit = 0);

	private:
		std::ostream& os_;
		uint8_t buffer_;
		size_t n_;
	};
}

#endif // ELIAS_ENCODER_BITWRITER_H_