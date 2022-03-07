#include "Processor.h"
#include "SelectType.h"
#include <stdexcept>

AddCommandProcessor::AddCommandProcessor(IDataManager& processor) : processor_{ processor }
{
	;
}

AddCommandProcessor::~AddCommandProcessor()
{
}

DeleteCommandProcessor::DeleteCommandProcessor(IDataManager& processor) 
	: processor_{ processor }, isDetailPrint_{ false }, deleteType_{ SelectType::NONE }, processResult_{ nullptr }
{
}

DeleteCommandProcessor::~DeleteCommandProcessor()
{
}

void DeleteCommandProcessor::setDeleteInformation(bool isDetailPrint, SelectType deleteType)
{
	isDetailPrint_ = isDetailPrint;
	deleteType_ = deleteType;
}

ProcessResult* DeleteCommandProcessor::getProcessResult()
{
	return processResult_;
}

void DeleteCommandProcessor::setProcessResult(ProcessResult* processResult)
{
	processResult_ = processResult;
}




