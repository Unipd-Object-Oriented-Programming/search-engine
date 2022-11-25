#include "ScoreVisitor.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

#include "../Item/AbstractProduct.h"

namespace Engine {

ScoreVisitor::ScoreVisitor(const Query& query)
    : query(query), string_filter(), score(0.0)
{
}

const Query& ScoreVisitor::getQuery() const {
    return query;
}

double ScoreVisitor::getScore() const {
    return score;
}

void ScoreVisitor::visit(const Item::WebPage& web_page) {
    score = computeScore(query.getText(), web_page.getName())
        + computeScore(query.getText(), web_page.getDescription())
    ;
}

void ScoreVisitor::visit(const Item::Simple& simple) {
    score = computeScore(query.getText(), simple.getName())
        + computeScore(query.getText(), simple.getDescription())
        + computeScore(query.getText(), simple.getSku())
    ;
}

void ScoreVisitor::visit(const Item::Virtual& virtual_item) {
    score = computeScore(query.getText(), virtual_item.getName())
        + computeScore(query.getText(), virtual_item.getDescription())
        + computeScore(query.getText(), virtual_item.getSku())
    ;
}

void ScoreVisitor::visit(const Item::Bundle& bundle) {
    double local_score = computeScore(query.getText(), bundle.getName())
        + computeScore(query.getText(), bundle.getDescription())
        + computeScore(query.getText(), bundle.getSku())
    ;
    std::vector<const Item::AbstractProduct*> products = bundle.getProducts();
    for (
        std::vector<const Item::AbstractProduct*>::const_iterator it = products.begin();
        it != products.end();
        it++
    ) {
        (*it)->accept(*this);
        local_score += score;
    }
    score = local_score;
}

double ScoreVisitor::computeScore(const std::string& query, const std::string& text) const {
    std::string q(string_filter.lowercase(query));
    std::vector<std::string> q_words(string_filter.split(q));
    std::string t(string_filter.lowercase(text));
    std::vector<std::string> t_words(string_filter.split(t));
    unsigned int occurrences = 0;
    for (
        std::vector<std::string>::const_iterator it = q_words.begin();
        it != q_words.end();
        it++
    ) {
        for (
            std::vector<std::string>::const_iterator jt = t_words.begin();
            jt != t_words.end();
            jt++
        ) {
            occurrences += jt->find(*it) != std::string::npos ? 1 : 0;
        }
    }
    const unsigned int size = std::max(t_words.size(), q_words.size());
    const double score = size > 0
        ? (double) occurrences / size
        : 0.0
    ;
    return score;
}

}