// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/BaseGameMode.h"

ABaseGameMode::ABaseGameMode()
{
	static ConstructorHelpers::FClassFinder<APlayerController> ControllerFind(TEXT("/Game/Blueprint/Player/BP_Debug_Player_Controller"));
	if (ControllerFind.Succeeded())
	{
		PlayerControllerClass = ControllerFind.Class;
	}
	
}
