
#include "cbor.h"
#include "parson.h"

CborError decode_json(const uint8_t *json_string, CborEncoder *encoder);