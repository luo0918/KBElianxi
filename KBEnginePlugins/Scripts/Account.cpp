#include "Account.h"
#include <KBEnginePlugins/Scripts/LogicEvents.h>

KBEngine::Account::Account():AccountBase()
{
}

KBEngine::Account::~Account()
{
}

void KBEngine::Account::__init__()
{
	if (isPlayer())
	{
		//ע���¼�
		KBENGINE_REGISTER_EVENT_OVERRIDE_FUNC("ESay", "ESay", [this](const UKBEventData* EventData)
			{
				const UKBEventData_ESay* ValueData = Cast<const UKBEventData_ESay>(EventData);
				pCellEntityCall->ESay(ValueData->Msg);

				UE_LOG(LogTemp, Log, TEXT("(UE_LOG-logTemp)    Hello ESay!"));
			});
	
		//������¼�ɹ��¼�
		UKBEventData* EventData = NewObject<UKBEventData>();
		KBENGINE_EVENT_FIRE("onLoginSuccessfully", EventData);
		UE_LOG(LogTemp, Log, TEXT("(UE_LOG-logTemp)    Hello onLoginSuccessfully!"));
	};
}

void KBEngine::Account::onDestroy()
{
	//ע������ע���¼�
	KBENGINE_DEREGISTER_ALL_EVENT();
}

void KBEngine::Account::OnSay(const CHAI_INFO& arg1)
{
	UKBEventData_OnSay* EventData = NewObject<UKBEventData_OnSay>();
	EventData->Name = arg1.Name;
	EventData->Time = arg1.Time;
	EventData->Msg = arg1.Msg;
	KBENGINE_EVENT_FIRE("OnSay", EventData);
	UE_LOG(LogTemp, Log, TEXT("(UE_LOG-logTemp)    Hello world!"));
}
