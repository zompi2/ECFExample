// Copyright (c) 2021 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExampleWidget.generated.h"

UCLASS()
class ECFEXAMPLE_API UExampleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void DelayTest();

	void AddToLog_Internal(FString Log);

	UFUNCTION(BlueprintImplementableEvent)
	void AddToLog(const FString& Log);
};
