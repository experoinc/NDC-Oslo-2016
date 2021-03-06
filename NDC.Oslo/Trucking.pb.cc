// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Trucking.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Trucking.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* Point_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Point_reflection_ = NULL;
const ::google::protobuf::Descriptor* Response_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Response_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Trucking_2eproto() {
  protobuf_AddDesc_Trucking_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Trucking.proto");
  GOOGLE_CHECK(file != NULL);
  Point_descriptor_ = file->message_type(0);
  static const int Point_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Point, latitude_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Point, longitude_),
  };
  Point_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Point_descriptor_,
      Point::default_instance_,
      Point_offsets_,
      -1,
      -1,
      -1,
      sizeof(Point),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Point, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Point, _is_default_instance_));
  Response_descriptor_ = file->message_type(1);
  static const int Response_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, status_),
  };
  Response_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Response_descriptor_,
      Response::default_instance_,
      Response_offsets_,
      -1,
      -1,
      -1,
      sizeof(Response),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Trucking_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Point_descriptor_, &Point::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Response_descriptor_, &Response::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Trucking_2eproto() {
  delete Point::default_instance_;
  delete Point_reflection_;
  delete Response::default_instance_;
  delete Response_reflection_;
}

void protobuf_AddDesc_Trucking_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016Trucking.proto\",\n\005Point\022\020\n\010latitude\030\001 "
    "\001(\002\022\021\n\tlongitude\030\002 \001(\002\"\032\n\010Response\022\016\n\006st"
    "atus\030\001 \001(\00523\n\010Trucking\022\'\n\016RecordLocation"
    "\022\006.Point\032\t.Response(\0010\001b\006proto3", 151);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Trucking.proto", &protobuf_RegisterTypes);
  Point::default_instance_ = new Point();
  Response::default_instance_ = new Response();
  Point::default_instance_->InitAsDefaultInstance();
  Response::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Trucking_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Trucking_2eproto {
  StaticDescriptorInitializer_Trucking_2eproto() {
    protobuf_AddDesc_Trucking_2eproto();
  }
} static_descriptor_initializer_Trucking_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Point::kLatitudeFieldNumber;
const int Point::kLongitudeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Point::Point()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Point)
}

void Point::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Point::Point(const Point& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Point)
}

void Point::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  latitude_ = 0;
  longitude_ = 0;
}

Point::~Point() {
  // @@protoc_insertion_point(destructor:Point)
  SharedDtor();
}

void Point::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Point::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Point::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Point_descriptor_;
}

const Point& Point::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Trucking_2eproto();
  return *default_instance_;
}

Point* Point::default_instance_ = NULL;

Point* Point::New(::google::protobuf::Arena* arena) const {
  Point* n = new Point;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Point::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<Point*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(latitude_, longitude_);

#undef ZR_HELPER_
#undef ZR_

}

bool Point::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Point)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional float latitude = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &latitude_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_longitude;
        break;
      }

      // optional float longitude = 2;
      case 2: {
        if (tag == 21) {
         parse_longitude:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &longitude_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Point)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Point)
  return false;
#undef DO_
}

void Point::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Point)
  // optional float latitude = 1;
  if (this->latitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(1, this->latitude(), output);
  }

  // optional float longitude = 2;
  if (this->longitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->longitude(), output);
  }

  // @@protoc_insertion_point(serialize_end:Point)
}

::google::protobuf::uint8* Point::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Point)
  // optional float latitude = 1;
  if (this->latitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(1, this->latitude(), target);
  }

  // optional float longitude = 2;
  if (this->longitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->longitude(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Point)
  return target;
}

int Point::ByteSize() const {
  int total_size = 0;

  // optional float latitude = 1;
  if (this->latitude() != 0) {
    total_size += 1 + 4;
  }

  // optional float longitude = 2;
  if (this->longitude() != 0) {
    total_size += 1 + 4;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Point::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Point* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Point>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Point::MergeFrom(const Point& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.latitude() != 0) {
    set_latitude(from.latitude());
  }
  if (from.longitude() != 0) {
    set_longitude(from.longitude());
  }
}

void Point::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Point::CopyFrom(const Point& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Point::IsInitialized() const {

  return true;
}

void Point::Swap(Point* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Point::InternalSwap(Point* other) {
  std::swap(latitude_, other->latitude_);
  std::swap(longitude_, other->longitude_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Point::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Point_descriptor_;
  metadata.reflection = Point_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Point

// optional float latitude = 1;
void Point::clear_latitude() {
  latitude_ = 0;
}
 float Point::latitude() const {
  // @@protoc_insertion_point(field_get:Point.latitude)
  return latitude_;
}
 void Point::set_latitude(float value) {
  
  latitude_ = value;
  // @@protoc_insertion_point(field_set:Point.latitude)
}

// optional float longitude = 2;
void Point::clear_longitude() {
  longitude_ = 0;
}
 float Point::longitude() const {
  // @@protoc_insertion_point(field_get:Point.longitude)
  return longitude_;
}
 void Point::set_longitude(float value) {
  
  longitude_ = value;
  // @@protoc_insertion_point(field_set:Point.longitude)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Response::kStatusFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Response::Response()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Response)
}

void Response::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Response::Response(const Response& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Response)
}

void Response::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  status_ = 0;
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:Response)
  SharedDtor();
}

void Response::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Response::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Response::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Response_descriptor_;
}

const Response& Response::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Trucking_2eproto();
  return *default_instance_;
}

Response* Response::default_instance_ = NULL;

Response* Response::New(::google::protobuf::Arena* arena) const {
  Response* n = new Response;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Response::Clear() {
  status_ = 0;
}

bool Response::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Response)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 status = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &status_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Response)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Response)
  return false;
#undef DO_
}

void Response::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Response)
  // optional int32 status = 1;
  if (this->status() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->status(), output);
  }

  // @@protoc_insertion_point(serialize_end:Response)
}

::google::protobuf::uint8* Response::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Response)
  // optional int32 status = 1;
  if (this->status() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->status(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Response)
  return target;
}

int Response::ByteSize() const {
  int total_size = 0;

  // optional int32 status = 1;
  if (this->status() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->status());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Response::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Response* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Response>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Response::MergeFrom(const Response& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.status() != 0) {
    set_status(from.status());
  }
}

void Response::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Response::CopyFrom(const Response& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {

  return true;
}

void Response::Swap(Response* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Response::InternalSwap(Response* other) {
  std::swap(status_, other->status_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Response::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Response_descriptor_;
  metadata.reflection = Response_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Response

// optional int32 status = 1;
void Response::clear_status() {
  status_ = 0;
}
 ::google::protobuf::int32 Response::status() const {
  // @@protoc_insertion_point(field_get:Response.status)
  return status_;
}
 void Response::set_status(::google::protobuf::int32 value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:Response.status)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
