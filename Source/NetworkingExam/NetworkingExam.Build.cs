// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NetworkingExam : ModuleRules
{
	public NetworkingExam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"NetCore",
			"Networking",
			"Sockets"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NetworkingExam",
			"NetworkingExam/Variant_Platforming",
			"NetworkingExam/Variant_Platforming/Animation",
			"NetworkingExam/Variant_Combat",
			"NetworkingExam/Variant_Combat/AI",
			"NetworkingExam/Variant_Combat/Animation",
			"NetworkingExam/Variant_Combat/Gameplay",
			"NetworkingExam/Variant_Combat/Interfaces",
			"NetworkingExam/Variant_Combat/UI",
			"NetworkingExam/Variant_SideScrolling",
			"NetworkingExam/Variant_SideScrolling/AI",
			"NetworkingExam/Variant_SideScrolling/Gameplay",
			"NetworkingExam/Variant_SideScrolling/Interfaces",
			"NetworkingExam/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
