

#pragma once

#include <memory>
#include <deque>
using std::deque;

class GArgument;

using arg_deque      =  deque  < std::shared_ptr<GArgument> >;
using arg_deque_ptr  =  std::shared_ptr < arg_deque >;