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

SearchCommandProcessor::SearchCommandProcessor(IDataManager& processor)
	: processor_{ processor }, isDetailPrint_{ false }, searchType_{ SelectType::NONE }, processResult_{ nullptr }
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

ProcessResult* SearchCommandProcessor::getProcessResult()
{
	return processResult_;
}

void SearchCommandProcessor::setProcessResult(ProcessResult* processResult)
{
	processResult_ = processResult;
}

ModifyCommandProcessor::ModifyCommandProcessor(IDataManager& processor)
	: processor_{ processor }, isDetailPrint_{ false }, searchType_{ SelectType::NONE }, processResult_{ nullptr }, modifyInfomation_{ nullptr }
{
}

ModifyCommandProcessor::~ModifyCommandProcessor()
{
}

void ModifyCommandProcessor::setModifyInformation(bool isDetailPrint, SelectType searchType, SelectType modfiyType, EmployeeInfomation* modifyInfomation)
{
	isDetailPrint_ = isDetailPrint;
	searchType_ = searchType;
	modifyType_ = modfiyType;
	modifyInfomation_ = modifyInfomation;
}

ProcessResult* ModifyCommandProcessor::getProcessResult()
{
	return processResult_;
}

void ModifyCommandProcessor::setProcessResult(ProcessResult* processResult)
{
	processResult_ = processResult;
}



