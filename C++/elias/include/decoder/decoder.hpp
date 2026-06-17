#ifndef ELIAS_DECODER_DECODER_H_
#define ELIAS_DECODER_DECODER_H_

#include <fstream>
#include <vector>

#include "bitreader.hpp"

namespace elias_decoder {
	class Decoder {
	public:
		Decoder(bit_reader::Bitreader& br);
		size_t decodeOne();
		std::vector<size_t> decodeN(const size_t& n);
		std::vector<size_t> decodeFile();

	private:
		bit_reader::Bitreader& br_;
	};
}

#endif // ELIAS_DECODER_DECODER_H_