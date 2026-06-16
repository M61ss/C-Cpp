#ifndef ELIAS_DECODER_DECODER_H_
#define ELIAS_DECODER_DECODER_H_

#include <fstream>

#include "bitreader.hpp"

namespace elias_decoder {
	class Decoder {
	public:
		Decoder(std::istream& is, bit_reader::Bitreader& br);

	private:
		std::istream& is_;
		bit_reader::Bitreader& br_;
	};
}

#endif // ELIAS_DECODER_DECODER_H_