#ifndef INDEPENDENT_EVENT_H
#define INDEPENDENT_EVENT_H

class IndependentEvent
{
public:

    /**
     * @brief Construct a new Independent Event object.
     *  Negative numbers will be set to 0.0.
     *  Numbers over 1.0 will be set to 1.0.
     *  Negative Infinity and NaN map to 0.0.
     *  Positive Infinity maps to 1.0.
     * 
     * @param likelihood Ranges from 0.0 (never) to 1.0 (certain)
     */
    IndependentEvent(double likelihood);

    /**
     * @brief Creates an IndependentEvent describing the probability of both events occurring
     * 
     * @param event 
     * @return IndependentEvent 
     */
    IndependentEvent operator&(const IndependentEvent &event) const;

    /**
     * @brief Creates an IndependentEvent describing the probability of either event occurring
     * 
     * @param event 
     * @return IndependentEvent 
     */
    IndependentEvent operator|(const IndependentEvent &event) const;

    /**
     * @brief Creates an independent event describing the probability of either A or B but not both occurring
     * 
     * @param event 
     * @return IndependentEvent 
     */
    IndependentEvent operator^(const IndependentEvent &event) const;

    /**
     * @brief Creates an independent event describing the probability of A but not B occurring
     * 
     * @param event 
     * @return IndependentEvent 
     */
    IndependentEvent operator-(const IndependentEvent &event) const;

    /**
     * @brief Creates an independent event describing the probability of A not occuring
     * 
     * @return IndependentEvent 
     */
    IndependentEvent operator~() const;

    /**
     * @brief Set the Likelihood. Enforces 0.0 -- 1.0 range constraint.
     * 
     * @param likelihood 
     */
    void setLikelihood(const double likelihood);
    
    /**
     * @brief Get the Likelihood
     * 
     * @return double 
     */
    double getLikelihood() const { return this->likelihood; };

private:
    double likelihood;
};

#endif