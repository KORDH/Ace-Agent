#include "Processor.h"
#include <stdexcept>

AddCommandProcessor::AddCommandProcessor(ICommandProcessor& processor) : processor_{processor}
{
	;
}

AddCommandProcessor::~AddCommandProcessor()
{
}
