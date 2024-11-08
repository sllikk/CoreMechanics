// Fill out your copyright notice in the Description page of Project Settings.

#include "Debug/DebugActor.h"


// Sets default values
ADebugActor::ADebugActor(): pBase_Mesh(nullptr), pCurveFloat(nullptr)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pBase_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base_Mesh"));
	RootComponent = pBase_Mesh;

}

void ADebugActor::BeginPlay()
{
	Super::BeginPlay();

}

void ADebugActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ADebugActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

