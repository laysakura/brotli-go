#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct BrotliParams {

  enum Mode {
    // Default compression mode. The compressor does not know anything in
    // advance about the properties of the input.
    MODE_GENERIC = 0,
    // Compression mode for UTF-8 format text input.
    MODE_TEXT = 1,
    // Compression mode used in WOFF 2.0.
    MODE_FONT = 2,
  } mode;

  // Controls the compression-speed vs compression-density tradeoffs. The higher
  // the quality, the slower the compression. Range is 0 to 11.
  int quality;
  // Base 2 logarithm of the sliding window size. Range is 10 to 24.
  int lgwin;
  // Base 2 logarithm of the maximum input block size. Range is 16 to 24.
  // If set to 0, the value will be set based on the quality.
  int lgblock;

  // These settings are deprecated and will be ignored.
  // All speed vs. size compromises are controlled by the quality param.
  bool enable_dictionary;
  bool enable_transforms;
  bool greedy_block_split;
  bool enable_context_modeling;
} BrotliParams;

// Compresses the data in input_buffer into encoded_buffer, and sets
// *encoded_size to the compressed length.
// Returns 0 if there was an error and 1 otherwise.
int BrotliCompressBuffer(BrotliParams params,
                         size_t input_size,
                         const uint8_t* input_buffer,
                         size_t* encoded_size,
                         uint8_t* encoded_buffer);
