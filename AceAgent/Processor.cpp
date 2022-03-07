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
	: processor_{ processor }, isDetailPrint_{ false }, deleteType_{ SelectType::NONE }, processResult_{  }
{
	printer_ = new Printer("DEL");
}

DeleteCommandProcessor::~DeleteCommandProcessor()
{
	delete(printer_);
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

SearchCommandProcessor::SearchCommandProcessor(IDataManager& processor)
	: processor_{ processor }, isDetailPrint_{ false }, searchType_{ SelectType::NONE }, processResult_{  }
{
	printer_ = new Printer("SCH");
}

SearchCommandProcessor::~SearchCommandProcessor()
{
	delete(printer_);
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

ModifyCommandProcessor::ModifyCommandProcessor(IDataManager& processor)
	: processor_{ processor }, isDetailPrint_{ false }, searchType_{ SelectType::NONE }, processResult_{  }, modifyInformation_{ nullptr }
{
	printer_ = new Printer("MOD");
}

ModifyCommandProcessor::~ModifyCommandProcessor()
{
	delete(printer_);
}

void ModifyCommandProcessor::setModifyInformation(bool isDetailPrint, SelectType searchType, SelectType modfiyType, EmployeeInformation* modifyInformation)
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



