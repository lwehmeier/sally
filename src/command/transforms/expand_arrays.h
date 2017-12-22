#pragma once

#include "system/context.h"
#include "system/state_type.h"
#include "system/state_formula.h"
#include "system/transition_formula.h"

#include "transform.h"

#include <string>

namespace sally {
namespace cmd {
namespace transforms {
  
/** 
    Expand arrays from transition systems and state formulas.  The
    expansion consists of removing quantifiers, array lambda terms and
    array variables involved in equalities. As a result of this
    expansion, all array variables should appear only as arguments of
    array read and write terms.  The expansion is only possible if the
    array size is statically known.

    Note: an array is not expanded if it appears as an argument to a
    function application term.
**/
  
class expand_arrays: public transform {
public:

  expand_arrays(system::context *ctx, std::string id);

  /* Create a new transition system with the given id (to be managed
     by the context) */  
  system::transition_system* apply (const system::transition_system *ts);
  
  /* Create a new state formula with the given id (to be managed by
     the context) */
  system::state_formula* apply(const system::state_formula *sf);

  std::string get_name() const {
    return "Expand arrays";
  }
  
private:
  
  system::context *d_ctx;
  std::string d_id;
};
  
}
}
}