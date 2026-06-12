cmake_minimum_required(VERSION 3.23)
project(elias)

add_executable(elias)

target_sources(elias
    PRIVATE
        src/main.cc
)

add_library(encoder)

target_sources(encoder
    PRIVATE
        src/encoder/encoder.cc
        src/encoder/bitwriter.cc

    PUBLIC
        FILE_SET encoderHeaders
        TYPE HEADERS
        BASE_DIRS
            include/encoder
        FILES
            include/encoder/encoder.hpp
            include/encoder/bitwriter.hpp
)

add_library(decoder)

target_sources(decoder
    PRIVATE
        src/decoder/decoder.cc
        src/decoder/bitreader.cc

    PUBLIC
        FILE_SET decoderHeaders
        TYPE HEADERS
        BASE_DIRS
            include/decoder
        FILES
            include/decoder/decoder.hpp
            include/decoder/bitreader.hpp
)

target_link_libraries(elias
    PRIVATE
        encoder
        decoder
)