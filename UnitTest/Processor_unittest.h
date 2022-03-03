#pragma once

#include "pch.h"
#include "MockAddCommandProcessor.h"
#include "../AceAgent/Processor.cpp"

class FixtureAddCommandProcessor : public ::testing::Test {
public:
	testing::NiceMock<MockAddCommandProcessor> mockProcessor_;
};