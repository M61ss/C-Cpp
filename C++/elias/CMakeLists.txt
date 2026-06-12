cmake_minimum_required(VERSION 3.23)
project(elias)

add_executable(elias)

target_sources(elias
    PRIVATE
        src/main.cc
        src/encoder/encoder.cc
        src/encoder/bitwriter.cc
        src/decoder/decoder.cc
        src/decoder/bitreader.cc
)