// Fill out your copyright notice in the Description page of Project Settings.

using System;
using System.IO;
using UnrealBuildTool;

public class L2DCubismEd : ModuleRules
{
	public L2DCubismEd(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;
        //        bUseRTTI = true;
        //        bEnableExceptions = true;

#if UE_4_24_OR_LATER
        DefaultBuildSettings = BuildSettingsVersion.V1;
#endif
        
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",

            "InputCore",
            "BlueprintGraph",
            "SlateCore",

            "RHI",
            "RenderCore",
            "Renderer",

            "L2DCubism",

        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",

            "InputCore",
            "BlueprintGraph",
            "SlateCore",

            "RHI",
            "RenderCore",
            "Renderer",

            "L2DCubism",

        });

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../L2DCubism/Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "../L2DCubism/Private"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "../L2DCubism/Private/Render"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../L2DCubism/SDK/Framework/src"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "../ThirdParty/SDK/Core/include"));
        //PublicIncludePaths.AddRange(new string[]{
        //    Path.Combine(ModuleDirectory, "Public"),
        //});

        //PrivateIncludePaths.AddRange(new string[]
        //{
        //    Path.Combine(ModuleDirectory, "../L2DCubism/Public"),
        //    Path.Combine(ModuleDirectory, "../L2DCubism/Private"),
        //    Path.Combine(ModuleDirectory, "../L2DCubism/Private/Render"),
        //    Path.Combine(ModuleDirectory, "../L2DCubism/SDK/Framework/src"),
        //    Path.Combine(ModuleDirectory, "../ThirdParty/SDK/Core/include")
        //});


    }
}
