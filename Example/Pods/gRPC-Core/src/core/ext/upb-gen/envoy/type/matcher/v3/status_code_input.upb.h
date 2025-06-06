/* This file was generated by upb_generator from the input file:
 *
 *     envoy/type/matcher/v3/status_code_input.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated.
 * NO CHECKED-IN PROTOBUF GENCODE */

#ifndef ENVOY_TYPE_MATCHER_V3_STATUS_CODE_INPUT_PROTO_UPB_H__UPB_H_
#define ENVOY_TYPE_MATCHER_V3_STATUS_CODE_INPUT_PROTO_UPB_H__UPB_H_

#include "upb/generated_code_support.h"

#include "envoy/type/matcher/v3/status_code_input.upb_minitable.h"

#include "udpa/annotations/status.upb_minitable.h"

// Must be last.
#include "upb/port/def.inc"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput { upb_Message UPB_PRIVATE(base); } envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput;
typedef struct envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput { upb_Message UPB_PRIVATE(base); } envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput;



/* envoy.type.matcher.v3.HttpResponseStatusCodeMatchInput */

UPB_INLINE envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput* envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput_new(upb_Arena* arena) {
  return (envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput*)_upb_Message_New(&envoy__type__matcher__v3__HttpResponseStatusCodeMatchInput_msg_init, arena);
}
UPB_INLINE envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput* envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput_parse(const char* buf, size_t size, upb_Arena* arena) {
  envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput* ret = envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, UPB_UPCAST(ret), &envoy__type__matcher__v3__HttpResponseStatusCodeMatchInput_msg_init, NULL, 0, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput* envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput* ret = envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, UPB_UPCAST(ret), &envoy__type__matcher__v3__HttpResponseStatusCodeMatchInput_msg_init, extreg, options,
                 arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput_serialize(const envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput* msg, upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(UPB_UPCAST(msg), &envoy__type__matcher__v3__HttpResponseStatusCodeMatchInput_msg_init, 0, arena, &ptr, len);
  return ptr;
}
UPB_INLINE char* envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput_serialize_ex(const envoy_type_matcher_v3_HttpResponseStatusCodeMatchInput* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(UPB_UPCAST(msg), &envoy__type__matcher__v3__HttpResponseStatusCodeMatchInput_msg_init, options, arena, &ptr, len);
  return ptr;
}


/* envoy.type.matcher.v3.HttpResponseStatusCodeClassMatchInput */

UPB_INLINE envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput* envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput_new(upb_Arena* arena) {
  return (envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput*)_upb_Message_New(&envoy__type__matcher__v3__HttpResponseStatusCodeClassMatchInput_msg_init, arena);
}
UPB_INLINE envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput* envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput_parse(const char* buf, size_t size, upb_Arena* arena) {
  envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput* ret = envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, UPB_UPCAST(ret), &envoy__type__matcher__v3__HttpResponseStatusCodeClassMatchInput_msg_init, NULL, 0, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput* envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput* ret = envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, UPB_UPCAST(ret), &envoy__type__matcher__v3__HttpResponseStatusCodeClassMatchInput_msg_init, extreg, options,
                 arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput_serialize(const envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput* msg, upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(UPB_UPCAST(msg), &envoy__type__matcher__v3__HttpResponseStatusCodeClassMatchInput_msg_init, 0, arena, &ptr, len);
  return ptr;
}
UPB_INLINE char* envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput_serialize_ex(const envoy_type_matcher_v3_HttpResponseStatusCodeClassMatchInput* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(UPB_UPCAST(msg), &envoy__type__matcher__v3__HttpResponseStatusCodeClassMatchInput_msg_init, options, arena, &ptr, len);
  return ptr;
}


#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif  /* ENVOY_TYPE_MATCHER_V3_STATUS_CODE_INPUT_PROTO_UPB_H__UPB_H_ */
