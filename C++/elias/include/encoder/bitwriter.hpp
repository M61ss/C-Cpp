#ifndef ELIAS_ENCODER_BITWRITER_H_
#define ELIAS_ENCODER_BITWRITER_H_

#include <fstream>

namespace bit_writer {
	class BitWriter {
	public:
		BitWriter(std::ostream& os);
		virtual ~BitWriter() = default;
		virtual void writeBit(const uint8_t& bit) = 0;
		virtual void writeSequence(const size_t& val, const size_t& length) = 0;
		virtual void flush(const uint8_t& bit) = 0;

	protected:
		std::ostream& os_;
		uint8_t buffer_;
		size_t n_;
	};

	class BigEndian : public BitWriter {
	public:
		BigEndian(std::ostream& os);
		void writeBit(const uint8_t& bit) override;
		void writeSequence(const size_t& val, const size_t& length) override;
		void flush(const uint8_t& bit) override;
	};
}

#endif // ELIAS_ENCODER_BITWRITER_H_