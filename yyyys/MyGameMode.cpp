// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"



void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();

	KBENGINE_REGISTER_EVENT("onLoginSuccessfully", onLoginSuccessfully);
	KBENGINE_REGISTER_EVENT("onLoginFailed", onLoginFailed);
	KBENGINE_REGISTER_EVENT("onCreateAccountResult", onCreateAccountResult);
	KBENGINE_REGISTER_EVENT("OnSay", OnSay);

}

void AMyGameMode::ESay(FString Msg)
{
	UKBEventData_ESay* EventData = NewObject<UKBEventData_ESay>();
	EventData->Msg = Msg;
	KBENGINE_EVENT_FIRE("ESay", EventData);
}

