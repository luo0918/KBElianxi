// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include <KBEnginePlugins/Engine/KBEngine.h>
#include <KBEnginePlugins/Engine/KBECommon.h>
#include "KBEnginePlugins/Scripts/Account.h"
#include <KBEnginePlugins/Scripts/LogicEvents.h>
#include "MyGameMode.generated.h"

/**
 * 
 */

UCLASS(Blueprintable, BlueprintType)
class YYYYS_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
		void onLoginSuccessfully(const UKBEventData* EventData);
	UFUNCTION(BlueprintImplementableEvent)
		void onLoginFailed(const UKBEventData* EventData);
	UFUNCTION(BlueprintImplementableEvent)
		void onCreateAccountResult(const UKBEventData* EventData);
	UFUNCTION(BlueprintImplementableEvent)
		void OnSay(const UKBEventData* EventData);
	UFUNCTION(BlueprintCallable)
		void ESay(FString Msg);
	
	
};
