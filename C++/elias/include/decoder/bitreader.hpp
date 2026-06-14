#ifndef ELIAS_DECODER_BITREADER_H_
#define ELIAS_DECODER_BITREADER_H_

#include <fstream>

namespace bit_reader {
    class BitReader {
    public:

    private:
        std::istream& is_;
        uint8_t buffer_;
        size_t n_;
    };
}

#endif // ELIAS_DECODER_BITREADER_H_