#ifndef VERB_H
#define VERB_H
#include <string>
using namespace std;
class verb
{
private:
    string infinitive;
    string past_simple;
    string past_participle;
public:
    verb();
    verb(string infinitive, string past_simple, string past_participle);
    void setData(string infinitive, string past_simple, string past_participle);
    bool comparePS(string ps);
    bool comparePP(string pp);
    ~verb();
    const string &getInfinitive() const;
    void setInfinitive(const string &newInfinitive);
    const string &getPast_simple() const;
    void setPast_simple(const string &newPast_simple);
    const string &getPast_participle() const;
    void setPast_participle(const string &newPast_participle);
};

#endif // VERB_H
