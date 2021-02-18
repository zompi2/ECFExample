// Copyright (c) 2021 Damian Nowakowski. All rights reserved.

#include "ExampleWidget.h"
#include "EnhancedCodeFlow.h"

void UExampleWidget::DelayTest()
{
	AddToLog_Internal(TEXT("Start Delay Test"));
	UFlow::Delay(this, 2.f, [this]()
	{
		AddToLog_Internal(TEXT("Delay Test Finished"));
	});
}

void UExampleWidget::AddToLog_Internal(FString Log)
{
	AddToLog(FDateTime::Now().ToString() + TEXT(": ") + Log);
}