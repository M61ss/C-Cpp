#ifndef ELIAS_DECODER_BITREADER_H_
#define ELIAS_DECODER_BITREADER_H_

#include <fstream>

namespace bit_reader {
    class Bitreader {
    public:
        Bitreader(std::istream& is);
        virtual ~Bitreader() = default;
        virtual uint8_t readBit() = 0;
        virtual size_t readSequence(const size_t& length) = 0;
        virtual void flush();

    protected:
        std::istream& is_;
        uint8_t buffer_;
        size_t n_;
    };

    class BigEndian : public Bitreader {
    public:
        BigEndian(std::istream& is);
        uint8_t readBit() override;
        size_t readSequence(const size_t& length) override;
    };

    class LittleEndian : public Bitreader {
    public:
        LittleEndian(std::istream& is);
        uint8_t readBit() override;
        size_t readSequence(const size_t& length) override;
    };
}

#endif // ELIAS_DECODER_BITREADER_H_