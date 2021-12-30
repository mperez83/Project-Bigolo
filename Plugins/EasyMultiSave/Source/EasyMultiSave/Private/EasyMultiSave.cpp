//Easy Multi Save - Copyright (C) 2021 by Michael Hegemann.  

#include "EasyMultiSave.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"
#include "EMSPluginSettings.h"
#include "Developer/Settings/Public/ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FEasyMultiSaveModule"

void FEasyMultiSaveModule::StartupModule()
{
	RegisterSettings();
}

void FEasyMultiSaveModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}

void FEasyMultiSaveModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		UEMSPluginSettings* PluginSettings = GetMutableDefault<UEMSPluginSettings>();
		
		SettingsModule->RegisterSettings("Project", "Plugins", "Easy Multi Save",
			LOCTEXT("RuntimeSettingsName", "Easy Multi Save"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the Easy Multi Save plugin"),
			PluginSettings
		);
	
		//Register Default Save-Object Classes

		if (PluginSettings->PersistentSaveGameClass.IsNull())
		{
			PluginSettings->PersistentSaveGameClass = FSoftClassPath(TEXT("/Script/EasyMultiSave.EMSPersistentSaveGame"));
		}
		
		if (PluginSettings->SlotInfoSaveGameClass.IsNull())
		{
			PluginSettings->SlotInfoSaveGameClass = FSoftClassPath(TEXT("/Script/EasyMultiSave.EMSInfoSaveGame"));
		}

		if (PluginSettings->ProfileSaveGameClass.IsNull())
		{
			PluginSettings->ProfileSaveGameClass = FSoftClassPath(TEXT("/Script/EasyMultiSave.EMSProfileSaveGame"));		
		}

		PluginSettings->PersistentSaveGameClass.TryLoad();
		PluginSettings->SlotInfoSaveGameClass.TryLoad();
		PluginSettings->ProfileSaveGameClass.TryLoad();
	}
}

void FEasyMultiSaveModule::UnregisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Easy Multi Save");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEasyMultiSaveModule, EasyMultiSave)