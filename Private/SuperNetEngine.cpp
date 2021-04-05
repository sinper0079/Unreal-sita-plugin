// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperNetEngine.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#define LOCTEXT_NAMESPACE "FSuperNetEngineModule"

void FSuperNetEngineModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("Some warning message") );

}

void FSuperNetEngineModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSuperNetEngineModule, SuperNetEngine)