#pragma once
#include <inttypes.h>
#include <vector>
#include "plog\Log.h"
//probably will define standard constants and things like that here... stuff that needs to be accessed from everywhere

typedef uint64_t RenderingCommand;
typedef std::vector<RenderingCommand> CommandList;