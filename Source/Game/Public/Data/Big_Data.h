#pragma once
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Big_Data.generated.h"


USTRUCT(BlueprintType)
struct FBig_Data : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="Mesh")
	TSoftObjectPtr<UStaticMesh> StaticMeshRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="Material")
	TSoftObjectPtr<UMaterialInterface> MaterialInterfaceRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="Material")
	TSoftObjectPtr<UNiagaraSystem> NiagaraSystemRef;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="Material")
	TSoftObjectPtr<USoundBase> SoundBaseRef;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="Material")
	int32 Health;

		
	
};
