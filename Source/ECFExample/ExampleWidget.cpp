// Copyright (c) 2021 Damian Nowakowski. All rights reserved.

#include "ExampleWidget.h"
#include "EnhancedCodeFlow.h"

void UExampleWidget::DelayTest()
{
	AddToLog_Internal(TEXT("Start Delay Test"));
	UFlow::Delay(this, 2.f, [this]()
	{
		AddToLog_Internal(TEXT("Delay Test Finished"));
		DelayTestFinished();
	});
}

void UExampleWidget::TickerTest()
{
	AddToLog_Internal(TEXT("Start Ticker Test"));

	TickerValue = 0.f;
	SetTickerValue_BP(TickerValue);

	UFlow::AddTicker(this, [this](float DeltaTime, FECFHandle TickerHandle)
	{
		TickerValue += DeltaTime;
		SetTickerValue_BP(TickerValue);

		if (TickerValue >= 2.f)
		{
			AddToLog_Internal(TEXT("Ticker Test Finished"));
			UFlow::StopAction(this, TickerHandle);
			TickerTestFinished();
		}
	});
}

void UExampleWidget::TimelineTest(EECFBlendFunc TimelineFunc, float StartValue, float StopValue)
{
	AddToLog_Internal(TEXT("Start Timeline Test"));

	SetTimelineValue_BP(0.f);

	UFlow::AddTimeline(this, StartValue, StopValue, 2.f, [this](float Value)
	{
		SetTimelineValue_BP(Value);
	}, [this](float Value)
	{
		SetTimelineValue_BP(Value);
		AddToLog_Internal(TEXT("Timeline Test Finished"));
		TimelineTestFinished();
	}, TimelineFunc, 2.f);
}

void UExampleWidget::CustomTimelineTest(UCurveFloat* Curve)
{
	AddToLog_Internal(TEXT("Start Custom Timeline Test"));

	SetCustomTimelineValue_BP(0.f);

	UFlow::AddCustomTimeline(this, Curve, [this](float Value)
	{
		SetCustomTimelineValue_BP(Value);
	}, [this](float Value)
	{
		SetCustomTimelineValue_BP(Value);
		AddToLog_Internal(TEXT("Custom Timeline Test Finished"));
		CustomTimelineTestFinished();
	});
}

void UExampleWidget::AddToLog_Internal(FString Log)
{
	AddToLog(FDateTime::Now().ToString() + TEXT(": ") + Log);
}