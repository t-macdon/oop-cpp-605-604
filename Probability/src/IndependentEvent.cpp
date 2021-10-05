/**
 * @file IndependentEvent.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation of the IndependentEvent class
 * @version 0.1
 * @date 2021-10-04
 */


#include <cmath>

#include "IndependentEvent.h"

IndependentEvent::IndependentEvent(double likelihood)
{
    setLikelihood(likelihood);
}

IndependentEvent IndependentEvent::operator&(const IndependentEvent& event) const
{
    double newLikelihood = this->getLikelihood() * event.getLikelihood();
    return IndependentEvent(newLikelihood);
}

IndependentEvent IndependentEvent::operator|(const IndependentEvent& event) const
{
    double newLikelihood = this->getLikelihood() + event.getLikelihood();
    return IndependentEvent(newLikelihood);
}

IndependentEvent IndependentEvent::operator^(const IndependentEvent& event) const
{
    double newLikelihood = this->getLikelihood() + event.getLikelihood() - (this->getLikelihood() * event.getLikelihood());
    return IndependentEvent(newLikelihood);
}

IndependentEvent IndependentEvent::operator-(const IndependentEvent& event) const
{
    double newLikelihood = this->getLikelihood() - this->getLikelihood() * event.getLikelihood();
    return IndependentEvent(newLikelihood);
}

IndependentEvent IndependentEvent::operator~() const
{
    double newLikelihood = std::abs(1.0 - this->getLikelihood());
    return IndependentEvent(newLikelihood);
}

void IndependentEvent::setLikelihood(const double likelihood)
{
    if (likelihood < 0.0)
    {
        this->likelihood = 0.0;
    } else if (likelihood > 1.0)
    {
        this->likelihood = 1.0;
    } else
    {
        this->likelihood = likelihood;
    }
}