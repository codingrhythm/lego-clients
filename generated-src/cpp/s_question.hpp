// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace lego {

struct SQuestion final {
    /** id of the question */
    std::string id;
    /** title of the question */
    std::string title;
    /** response type */
    int32_t response_type;
    /** description of the question */
    std::string question_description;
    /** order of the question */
    int32_t order;

    SQuestion(std::string id_,
              std::string title_,
              int32_t response_type_,
              std::string question_description_,
              int32_t order_)
    : id(std::move(id_))
    , title(std::move(title_))
    , response_type(std::move(response_type_))
    , question_description(std::move(question_description_))
    , order(std::move(order_))
    {}
};

}  // namespace lego