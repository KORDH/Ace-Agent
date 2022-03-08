#include "CommandProcessor.h"
#include "SelectType.h"
#include <stdexcept>

AddCommandProcessor::AddCommandProcessor(IOperator& processor) : processor_{ processor }
{
	;
}

AddCommandProcessor::~AddCommandProcessor()
{
}

DeleteCommandProcessor::DeleteCommandProcessor(IOperator& processor)
	: processor_{ processor }, isDetailPrint_{ false }, deleteType_{ SelectType::NONE }, processResult_{  }
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

ProcessResult DeleteCommandProcessor::getProcessResult()
{
	return processResult_;
}

void DeleteCommandProcessor::setProcessResult(ProcessResult processResult)
{
	processResult_ = processResult;
}

SearchCommandProcessor::SearchCommandProcessor(IOperator& processor)
	: processor_{ processor }, isDetailPrint_{ false }, searchType_{ SelectType::NONE }, processResult_{  }
{
}

SearchCommandProcessor::~SearchCommandProcessor()
{
}

void SearchCommandProcessor::setSearchInformation(bool isDetailPrint, SelectType searchType)
{
	isDetailPrint_ = isDetailPrint;
	searchType_ = searchType;
}

ProcessResult SearchCommandProcessor::getProcessResult()
{
	return processResult_;
}

void SearchCommandProcessor::setProcessResult(ProcessResult processResult)
{
	processResult_ = processResult;
}

ModifyCommandProcessor::ModifyCommandProcessor(IOperator& processor)
	: processor_{ processor }, isDetailPrint_{ false }, searchType_{ SelectType::NONE }, processResult_{  }, modifyInformation_{ }
{
}

ModifyCommandProcessor::~ModifyCommandProcessor()
{
}

void ModifyCommandProcessor::setModifyInformation(bool isDetailPrint, SelectType searchType, SelectType modfiyType, EmployeeInformation modifyInformation)
{
	isDetailPrint_ = isDetailPrint;
	searchType_ = searchType;
	modifyType_ = modfiyType;
	modifyInformation_ = modifyInformation;
}

ProcessResult ModifyCommandProcessor::getProcessResult()
{
	return processResult_;
}

void ModifyCommandProcessor::setProcessResult(ProcessResult processResult)
{
	processResult_ = processResult;
}



