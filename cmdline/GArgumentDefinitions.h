

#pragma once

#include <memory>
#include <deque>
using std::deque;

#include <functional>

class GArgument;

template <typename T>
class GCommandLineArgument;


using arg_ptr = std::shared_ptr<GArgument>;
using arg_deque      =  deque < arg_ptr >;
using arg_deque_ptr  =  std::shared_ptr < arg_deque >;
using callback_t = std::function< bool(const string cmd, const string args_s, const vector<string> sub, const	vector<string> par) >;

using vector_arg =  GCommandLineArgument < vector< string > >;
using void_arg  =  GCommandLineArgument <void>;
using bool_arg =  GCommandLineArgument <bool>;

using vector_arg_ptr = std::shared_ptr<GCommandLineArgument < vector< string > >>;
using void_arg_ptr =   std::shared_ptr<GCommandLineArgument <void> >;
using bool_arg_ptr =  std::shared_ptr<GCommandLineArgument <bool> >;

#define MAX_ARGS 200


/** What strategy to use if the user tries to add
duplicate command line arguments*/
enum class eDUP_STRATEGY
{
	REPLACE_DUPLICATE, /// The new argument replaces the existing one
	IGNORE_DUPLICATE,  /// The argument is ignored, and the original argument kept
	THROW_EXEPTION /// Throw an exception on encountering a duplicate argument
};

