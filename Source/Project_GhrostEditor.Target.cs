

using UnrealBuildTool;
using System.Collections.Generic;

public class Project_GhrostEditorTarget : TargetRules
{
	public Project_GhrostEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Project_Ghrost" } );
	}
}
