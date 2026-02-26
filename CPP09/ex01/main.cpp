#include "eader.h"
#include "RPN.hpp"

int main(int argc, char	*argv[])
{
	
}

// function main(argc, argv):
//     if argc != 2 or argv[1] empty:
//         print_error()
//         exit(1)
//     result = evaluate(argv[1])
//     if result.failed:
//         print_error()
//         exit(1)
//     print result.value newline
//     exit(0)

// function evaluate(expr) -> { bool failed; long value; }:
//     Stack stack  // std::deque<long> oppure std::stack<long, std::deque<long>>

//     tokens = split expr by spaces, ignoring empty tokens
//     for token in tokens:
//         if token consists only of digits:
//             stack.push_back(to_long(token))
//             continue

//         if token is one of "+", "-", "*", "/":
//             if stack.size() < 2:
//                 return {true,0}
//             b = stack.back(); stack.pop_back()
//             a = stack.back(); stack.pop_back()
//             if token == "/" and b == 0:
//                 return {true,0}
//             c = apply(a, b, token)   // switch-case operator
//             stack.push_back(c)
//             continue

//         // otherwise token invalid
//         return {true,0}

//     if stack.size() != 1:
//         return {true,0}

//     return {false, stack.back()}

// function apply(a, b, op) -> long:
//     switch op:
//         case "+": return a + b
//         case "-": return a - b
//         case "*": return a * b
//         case "/": return a / b   // integer division