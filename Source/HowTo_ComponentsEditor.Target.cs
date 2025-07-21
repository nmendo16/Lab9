// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HowTo_ComponentsEditorTarget : TargetRules
{
    public HowTo_ComponentsEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
        ExtraModuleNames.Add("HowTo_Components");
    }
}
