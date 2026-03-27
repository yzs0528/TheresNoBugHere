using UnrealBuildTool;

public class TheresNoBugHereEditor : ModuleRules
{
    public TheresNoBugHereEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "AnimGraphRuntime",
                "BlueprintGraph",
                "DeveloperSettings",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "TheresNoBugHere",
                "UnrealEd",
                "GraphEditor",
                "AnimGraph",
                "ToolMenus",
            }
        );
    }
}