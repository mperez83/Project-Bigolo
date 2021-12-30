//Easy Multi Save - Copyright (C) 2021 by Michael Hegemann.  

#include "EMSAsyncWait.h"
#include "EMSObject.h"

UEMSAsyncWait* UEMSAsyncWait::AsyncWaitForOperation(UObject* WorldContextObject)
{
	if (UEMSObject* EMSObject = UEMSObject::Get(WorldContextObject))
	{
		UEMSAsyncWait* WaitTask = NewObject<UEMSAsyncWait>(GetTransientPackage());
		WaitTask->WorldContextObject = WorldContextObject;
		WaitTask->EMS = EMSObject;
		WaitTask->bSaveOrLoadTaskWasActive = false;

		return WaitTask;
	}

	return nullptr;
}

void UEMSAsyncWait::Activate()
{
	StartWaitTask();
}

void UEMSAsyncWait::StartWaitTask()
{
	if (EMS)
	{
		//Wait as long as the current async operation is completed.
		if (EMS->IsAsyncSaveOrLoadTaskActive(ESaveGameMode::MODE_All, false))
		{
			EMS->GetTimerManager().SetTimerForNextTick(this, &UEMSAsyncWait::StartWaitTask);

			bSaveOrLoadTaskWasActive = true;
		}
		else
		{
			if (bSaveOrLoadTaskWasActive)
			{
				EMS->GetTimerManager().SetTimerForNextTick(this, &UEMSAsyncWait::CompleteWaitTask);
			}
			else
			{
				EMS->GetTimerManager().SetTimerForNextTick(this, &UEMSAsyncWait::StartWaitTask);
			}
		}
	}
}

void UEMSAsyncWait::CompleteWaitTask()
{
	OnCompleted.Broadcast();
	SetReadyToDestroy();
}
