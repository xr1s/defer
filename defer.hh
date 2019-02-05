#ifndef DEFER_HH_
#define DEFER_HH_ 1

#include <functional>
#include <utility>

namespace defer_ {

class Defer_ {
 public:
  template <typename Fn> Defer_(Fn &&);
  Defer_(Defer_ &&);
  ~Defer_();
 private:
  std::function<void()> callback_;
};

template <typename Fn>
Defer_::Defer_(Fn &&fn)
  : callback_{static_cast<std::function<void()>>(std::forward<Fn>(fn))} {
}

Defer_::Defer_(Defer_ &&that)
    : callback_{std::move(that.callback_)} {
}

Defer_::~Defer_() {
  this->callback_();
}

}  // defer_

#define DEFER_CONCAT_IMPL_(LHS, RHS) LHS##RHS

#define DEFER_CONCAT_(LHS, RHS) DEFER_CONCAT_IMPL_(LHS, RHS)

#define defer \
  if (false);  /* Ensure deferred in a scope. */ \
  defer_::Defer_ DEFER_CONCAT_(_defer_, __LINE__) = 

#endif  // DEFER_HH_
