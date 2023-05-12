

#pragma once

#include <memory>
#include <deque>
using std::deque;

class GArgument;

using arg_deque      =  deque  < std::shared_ptr<GArgument> >;
using arg_deque_ptr  =  std::shared_ptr < arg_deque >;

/** What strategy to use if the user tries to add
duplicate command line arguments*/
enum class eDUPLICATE_STRATEGY
{
	REPLACE_DUPLICATE, /// The new argument replaces the existing one
	IGNORE_DUPLICATE,  /// The argument is ignored, and the original argument kept
	THROW_EXEPTION /// Throw an exception on encountering a duplicate argument
};

