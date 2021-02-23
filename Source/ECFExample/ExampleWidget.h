// Copyright (c) 2021 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ECFTypes.h"
#include "ExampleWidget.generated.h"

UCLASS()
class ECFEXAMPLE_API UExampleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

	UFUNCTION(BlueprintCallable)
	void DelayTest();

	UFUNCTION(BlueprintImplementableEvent)
	void DelayTestFinished();

	/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

	UFUNCTION(BlueprintCallable)
	void TickerTest();

	UFUNCTION(BlueprintImplementableEvent)
	void TickerTestFinished();

	float TickerValue;

	/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


	UFUNCTION(BlueprintCallable)
	void TimelineTest(EECFBlendFunc TimelineFunc, float StartValue, float StopValue);

	UFUNCTION(BlueprintImplementableEvent)
	void TimelineTestFinished();



	UFUNCTION(BlueprintCallable)
	void CustomTimelineTest(UCurveFloat* Curve);

	UFUNCTION(BlueprintImplementableEvent)
	void CustomTimelineTestFinished();



	UFUNCTION(BlueprintCallable)
	void WaitAndExecuteTest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bWaitAndExecuteConditional = false;


	UFUNCTION(BlueprintImplementableEvent)
	void WaitAndExecuteTestFinished();


	UFUNCTION(BlueprintCallable)
	void WhileTrueExecuteTest();

	UFUNCTION(BlueprintImplementableEvent)
	void WhileTrueExecuteTestFinished();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bWhileTrueExecuteConditional = true;

	float WhileTrueExecuteTickerValue;

	void AddToLog_Internal(FString Log);

	UFUNCTION(BlueprintImplementableEvent)
	void AddToLog(const FString& Log);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTickerValue_BP(float NewValue);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTimelineValue_BP(float NewValue, float NewTime);

	UFUNCTION(BlueprintImplementableEvent)
	void SetCustomTimelineValue_BP(float NewValue, float NewTime);

	UFUNCTION(BlueprintImplementableEvent)
	void SetWhileTrueExecuteTickerValue_BP(float NewValue);
};
