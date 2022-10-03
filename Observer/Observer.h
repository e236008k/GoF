#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

/* Declaration for Build */
class Observer;
class Subject;

/* Observer Class is Update */
class Observer
{

public:
    Observer() {}
    virtual void Update(Subject *s) = 0;
public:

    /* Define Default Special Func(Constructor and Destructor) */
    virtual ~Observer()                   = default;

    /* Copy Constructor */
    Observer(const Observer &)            = default;
    Observer &operator=(const Observer &) = default;
    Observer(Observer &&)                 = default;
    Observer &operator=(Observer &&)      = default;
};

/* Subject Class is Event Generator */
class Subject
{

private:

    std::vector<Observer *> obsrv_;

public:

    Subject(){}

    void Attach(Observer *obs)
    {
        /* add Observer Type Instance to List End Element */
        obsrv_.emplace_back(obs);
    }

    void Detach(Observer *obs)
    {
        /* add Observer Type Instance to List End Element */
        obsrv_.erase(std::remove(obsrv_.begin(),obsrv_.end(),obs));
    }

    /* Notify : Key Function of Observer Pattern */
    void Notify()
    {

        /* 範囲ベースfor loop -> for(変数 : 範囲(配列、コンテナオブジェクト)) C++11から実装の機能  */
        /* vectorの要素を自動的にcに代入する */
        /* auto : Estimate Var Type function from C++11 */
        for(const auto &o : obsrv_)
        {
            o->Update(this);
        }
    }

    virtual ~Subject()                  = default;
    Subject(const Subject &)            = default;
    Subject &operator=(const Subject &) = default;
    Subject(Subject &&)                 = default;
    Subject &operator=(Subject &&)      = default;
};

#endif // OBSERVER_H
