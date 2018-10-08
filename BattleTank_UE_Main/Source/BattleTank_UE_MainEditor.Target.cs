// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BattleTank_UE_MainEditorTarget : TargetRules
{
	public BattleTank_UE_MainEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "BattleTank_UE_Main" } );
	}
}
