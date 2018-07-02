// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_LEGO_LEGO_H_
#define FLATBUFFERS_GENERATED_LEGO_LEGO_H_

#include "flatbuffers/flatbuffers.h"

namespace Lego {

struct QuestionRecord;

struct PageRecord;

struct TemplateRecord;

struct QuestionRecord FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ID = 4,
    VT_TITLE = 6,
    VT_RESPONSE_TYPE = 8,
    VT_QUESTION_DESCRIPTION = 10,
    VT_ORDER = 12
  };
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  const flatbuffers::String *title() const {
    return GetPointer<const flatbuffers::String *>(VT_TITLE);
  }
  int32_t response_type() const {
    return GetField<int32_t>(VT_RESPONSE_TYPE, 0);
  }
  const flatbuffers::String *question_description() const {
    return GetPointer<const flatbuffers::String *>(VT_QUESTION_DESCRIPTION);
  }
  int32_t order() const {
    return GetField<int32_t>(VT_ORDER, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ID) &&
           verifier.Verify(id()) &&
           VerifyOffset(verifier, VT_TITLE) &&
           verifier.Verify(title()) &&
           VerifyField<int32_t>(verifier, VT_RESPONSE_TYPE) &&
           VerifyOffset(verifier, VT_QUESTION_DESCRIPTION) &&
           verifier.Verify(question_description()) &&
           VerifyField<int32_t>(verifier, VT_ORDER) &&
           verifier.EndTable();
  }
};

struct QuestionRecordBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(QuestionRecord::VT_ID, id);
  }
  void add_title(flatbuffers::Offset<flatbuffers::String> title) {
    fbb_.AddOffset(QuestionRecord::VT_TITLE, title);
  }
  void add_response_type(int32_t response_type) {
    fbb_.AddElement<int32_t>(QuestionRecord::VT_RESPONSE_TYPE, response_type, 0);
  }
  void add_question_description(flatbuffers::Offset<flatbuffers::String> question_description) {
    fbb_.AddOffset(QuestionRecord::VT_QUESTION_DESCRIPTION, question_description);
  }
  void add_order(int32_t order) {
    fbb_.AddElement<int32_t>(QuestionRecord::VT_ORDER, order, 0);
  }
  explicit QuestionRecordBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  QuestionRecordBuilder &operator=(const QuestionRecordBuilder &);
  flatbuffers::Offset<QuestionRecord> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<QuestionRecord>(end);
    return o;
  }
};

inline flatbuffers::Offset<QuestionRecord> CreateQuestionRecord(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> id = 0,
    flatbuffers::Offset<flatbuffers::String> title = 0,
    int32_t response_type = 0,
    flatbuffers::Offset<flatbuffers::String> question_description = 0,
    int32_t order = 0) {
  QuestionRecordBuilder builder_(_fbb);
  builder_.add_order(order);
  builder_.add_question_description(question_description);
  builder_.add_response_type(response_type);
  builder_.add_title(title);
  builder_.add_id(id);
  return builder_.Finish();
}

inline flatbuffers::Offset<QuestionRecord> CreateQuestionRecordDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *id = nullptr,
    const char *title = nullptr,
    int32_t response_type = 0,
    const char *question_description = nullptr,
    int32_t order = 0) {
  return Lego::CreateQuestionRecord(
      _fbb,
      id ? _fbb.CreateString(id) : 0,
      title ? _fbb.CreateString(title) : 0,
      response_type,
      question_description ? _fbb.CreateString(question_description) : 0,
      order);
}

struct PageRecord FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ID = 4,
    VT_TITLE = 6,
    VT_ORDER = 8,
    VT_QUESTIONS = 10
  };
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  const flatbuffers::String *title() const {
    return GetPointer<const flatbuffers::String *>(VT_TITLE);
  }
  int32_t order() const {
    return GetField<int32_t>(VT_ORDER, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<QuestionRecord>> *questions() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<QuestionRecord>> *>(VT_QUESTIONS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ID) &&
           verifier.Verify(id()) &&
           VerifyOffset(verifier, VT_TITLE) &&
           verifier.Verify(title()) &&
           VerifyField<int32_t>(verifier, VT_ORDER) &&
           VerifyOffset(verifier, VT_QUESTIONS) &&
           verifier.Verify(questions()) &&
           verifier.VerifyVectorOfTables(questions()) &&
           verifier.EndTable();
  }
};

struct PageRecordBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(PageRecord::VT_ID, id);
  }
  void add_title(flatbuffers::Offset<flatbuffers::String> title) {
    fbb_.AddOffset(PageRecord::VT_TITLE, title);
  }
  void add_order(int32_t order) {
    fbb_.AddElement<int32_t>(PageRecord::VT_ORDER, order, 0);
  }
  void add_questions(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<QuestionRecord>>> questions) {
    fbb_.AddOffset(PageRecord::VT_QUESTIONS, questions);
  }
  explicit PageRecordBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PageRecordBuilder &operator=(const PageRecordBuilder &);
  flatbuffers::Offset<PageRecord> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PageRecord>(end);
    return o;
  }
};

inline flatbuffers::Offset<PageRecord> CreatePageRecord(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> id = 0,
    flatbuffers::Offset<flatbuffers::String> title = 0,
    int32_t order = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<QuestionRecord>>> questions = 0) {
  PageRecordBuilder builder_(_fbb);
  builder_.add_questions(questions);
  builder_.add_order(order);
  builder_.add_title(title);
  builder_.add_id(id);
  return builder_.Finish();
}

inline flatbuffers::Offset<PageRecord> CreatePageRecordDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *id = nullptr,
    const char *title = nullptr,
    int32_t order = 0,
    const std::vector<flatbuffers::Offset<QuestionRecord>> *questions = nullptr) {
  return Lego::CreatePageRecord(
      _fbb,
      id ? _fbb.CreateString(id) : 0,
      title ? _fbb.CreateString(title) : 0,
      order,
      questions ? _fbb.CreateVector<flatbuffers::Offset<QuestionRecord>>(*questions) : 0);
}

struct TemplateRecord FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ID = 4,
    VT_NAME = 6,
    VT_PAGES = 8
  };
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::Vector<flatbuffers::Offset<PageRecord>> *pages() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<PageRecord>> *>(VT_PAGES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ID) &&
           verifier.Verify(id()) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyOffset(verifier, VT_PAGES) &&
           verifier.Verify(pages()) &&
           verifier.VerifyVectorOfTables(pages()) &&
           verifier.EndTable();
  }
};

struct TemplateRecordBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(TemplateRecord::VT_ID, id);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(TemplateRecord::VT_NAME, name);
  }
  void add_pages(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PageRecord>>> pages) {
    fbb_.AddOffset(TemplateRecord::VT_PAGES, pages);
  }
  explicit TemplateRecordBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TemplateRecordBuilder &operator=(const TemplateRecordBuilder &);
  flatbuffers::Offset<TemplateRecord> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<TemplateRecord>(end);
    return o;
  }
};

inline flatbuffers::Offset<TemplateRecord> CreateTemplateRecord(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> id = 0,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PageRecord>>> pages = 0) {
  TemplateRecordBuilder builder_(_fbb);
  builder_.add_pages(pages);
  builder_.add_name(name);
  builder_.add_id(id);
  return builder_.Finish();
}

inline flatbuffers::Offset<TemplateRecord> CreateTemplateRecordDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *id = nullptr,
    const char *name = nullptr,
    const std::vector<flatbuffers::Offset<PageRecord>> *pages = nullptr) {
  return Lego::CreateTemplateRecord(
      _fbb,
      id ? _fbb.CreateString(id) : 0,
      name ? _fbb.CreateString(name) : 0,
      pages ? _fbb.CreateVector<flatbuffers::Offset<PageRecord>>(*pages) : 0);
}

inline const Lego::TemplateRecord *GetTemplateRecord(const void *buf) {
  return flatbuffers::GetRoot<Lego::TemplateRecord>(buf);
}

inline const Lego::TemplateRecord *GetSizePrefixedTemplateRecord(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Lego::TemplateRecord>(buf);
}

inline bool VerifyTemplateRecordBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Lego::TemplateRecord>(nullptr);
}

inline bool VerifySizePrefixedTemplateRecordBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Lego::TemplateRecord>(nullptr);
}

inline void FinishTemplateRecordBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Lego::TemplateRecord> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTemplateRecordBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Lego::TemplateRecord> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Lego

#endif  // FLATBUFFERS_GENERATED_LEGO_LEGO_H_
