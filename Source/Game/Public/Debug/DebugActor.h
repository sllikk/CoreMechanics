// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StreamableManager.h"
#include "GameFramework/Actor.h"
#include "DebugActor.generated.h"

class UStaticMeshComponent;
class UNiagaraComponent;
class UMaterialInterface;
class UDataTable;
class UCurveFloat;
class UNiagaraSystem;
class UStaticMesh;

UCLASS()
class GAME_API ADebugActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh", meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* pBase_Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Niagara", meta=(AllowPrivateAccess = "true"))
	UNiagaraComponent* NiagaraComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="", meta=(AllowPrivateAccess = "true"))
	UCurveFloat* pCurveFloat;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="DataTable", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UDataTable> DT_Skin;

public:	
	// Sets default values for this actor's properties
	ADebugActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaTime) override;

	
public:	

	FStreamableManager StreamableManager;
	FTimerHandle TimerHandle;

};
