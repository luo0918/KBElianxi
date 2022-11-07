// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class yyyys : ModuleRules
{
	public yyyys(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "KBEnginePlugins" });
	}
}
