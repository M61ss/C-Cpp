cmake_minimum_required (VERSION 3.23)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("elias")

add_executable (elias)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET elias PROPERTY CXX_STANDARD 20)
endif()

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