

using UnrealBuildTool;
using System.Collections.Generic;

public class Project_GhrostTarget : TargetRules
{
	public Project_GhrostTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Project_Ghrost" } );
	}
}
