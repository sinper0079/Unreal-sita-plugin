// Copyright Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class SuperNetEngine : ModuleRules
{
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "Private/NetworkEngine")); }
	}

	public SuperNetEngine(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
	
			}
			);
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				Path.Combine(ThirdPartyPath, "src/net/common/src/sita_net_common/engine"),
                Path.Combine(ThirdPartyPath, "src/core/src")
				// "../externals/vcpkg/installed/x64-windows/include",
				//"../externals/vcpkg/installed/x64-windows/include/Common"
				//Path.Combine(ThirdPartyPath, "externals/vcpkg/installed/x64-windows/include/fmt")

			}
			);
		PublicAdditionalLibraries.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...



			}
			);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Sockets",
				"Networking"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
