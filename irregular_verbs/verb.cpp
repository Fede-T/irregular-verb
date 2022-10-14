#include "verb.h"
#include <algorithm>
verb::verb()
{

}

verb::verb(string infinitive, string past_simple, string past_participle)
{
    this->infinitive = infinitive;
    transform(this->infinitive.begin(), this->infinitive.end(), this->infinitive.begin(), ::tolower);
    this->past_simple = past_simple;
    transform(this->past_simple.begin(), this->past_simple.end(), this->past_simple.begin(), ::tolower);
    this->past_participle = past_participle;
    transform(this->past_participle.begin(), this->past_participle.end(), this->past_participle.begin(), ::tolower);

    for(int i = 0; i < this->past_simple.size(); i++) if(this->past_simple[i] == '_') this->past_simple[i] = ' ';
    for(int i = 0; i < this->past_participle.size(); i++) if(this->past_participle[i] == '_') this->past_participle[i] = ' ';
}

void verb::setData(string infinitive, string past_simple, string past_participle)
{
    this->infinitive = infinitive;
    transform(this->infinitive.begin(), this->infinitive.end(), this->infinitive.begin(), ::tolower);
    this->past_simple = past_simple;
    transform(this->past_simple.begin(), this->past_simple.end(), this->past_simple.begin(), ::tolower);
    this->past_participle = past_participle;
    transform(this->past_participle.begin(), this->past_participle.end(), this->past_participle.begin(), ::tolower);
    for(int i = 0; i < this->past_simple.size(); i++) if(this->past_simple[i] == '_') this->past_simple[i] = ' ';
    for(int i = 0; i < this->past_participle.size(); i++) if(this->past_participle[i] == '_') this->past_participle[i] = ' ';
}

bool verb::comparePS(string ps)
{
    transform(ps.begin(), ps.end(), ps.begin(), ::tolower);
    if(this->past_simple == ps)
        return true;
    else
        return false;
}

bool verb::comparePP(string pp)
{
    transform(pp.begin(), pp.end(), pp.begin(), ::tolower);
    if(this->past_participle == pp)
        return true;
    else
        return false;
}

verb::~verb()
{

}

const string &verb::getInfinitive() const
{
    return infinitive;
}

void verb::setInfinitive(const string &newInfinitive)
{
    infinitive = newInfinitive;
    transform(this->infinitive.begin(), this->infinitive.end(), this->infinitive.begin(), ::tolower);
}

const string &verb::getPast_simple() const
{
    return past_simple;
}

void verb::setPast_simple(const string &newPast_simple)
{
    past_simple = newPast_simple;
    transform(this->past_simple.begin(), this->past_simple.end(), this->past_simple.begin(), ::tolower);
    for(int i = 0; i < this->past_simple.size(); i++) if(this->past_simple[i] == '_') this->past_simple[i] = ' ';
}

const string &verb::getPast_participle() const
{
    return past_participle;
}

void verb::setPast_participle(const string &newPast_participle)
{
    past_participle = newPast_participle;
    transform(this->past_participle.begin(), this->past_participle.end(), this->past_participle.begin(), ::tolower);
    for(int i = 0; i < this->past_participle.size(); i++) if(this->past_participle[i] == '_') this->past_participle[i] = ' ';
}
