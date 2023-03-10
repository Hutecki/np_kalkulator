#include <functional>

// number type used throughout the program
using Number = double;

// function prototype used by every arithmetic functions
using NumberOperation = std::function<Number(Number, Number)>;
