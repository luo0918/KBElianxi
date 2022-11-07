// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "KBEnginePlugins/Engine/KBECommon.h"
#include <KBEnginePlugins/Engine/AccountBase.h>
#include <KBEnginePlugins/Engine/KBEngine.h>
#include <KBEnginePlugins/Engine/KBEvent.h>



namespace KBEngine
{ 
	class  Account : public AccountBase
	{

	public:
		Account();
		virtual ~Account();

	public:
		virtual void __init__() override;

		virtual void onDestroy() override;

		virtual void OnSay(const CHAI_INFO& arg1) override;



	};
}
