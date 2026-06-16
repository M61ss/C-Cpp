#include "decoder.hpp"

elias_decoder::Decoder::Decoder(std::istream& is, bit_reader::Bitreader& br) : is_(is), br_(br) {}