#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

class Context;


/* For definition of each status. for example status A , status B instance are generated.  */
class State {

 /* access only internal and heritance */
 protected:
  Context *context_;

 public:
  virtual ~State() {
  }

  void set_context(Context *context) {
    this->context_ = context;
  }

  virtual void Handle1() = 0;
  virtual void Handle2() = 0;
};

/* for Transition to Other Status */
/* Save 1 Concrete State from multi states */
/* State Class has Context Class  */
class Context {

 private:
  State *state_;

 public:

  /* Set Initial State */
  Context(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }

  ~Context() {
    delete state_;
  }

  void TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
  }

  void Request1() {
    this->state_->Handle1();
  }
  void Request2() {
    this->state_->Handle2();
  }
};

#endif // STATE_H
