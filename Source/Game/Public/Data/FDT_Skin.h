#pragma once

#include "FDT_Skin.generated.h"

USTRUCT(BlueprintType)
struct FDT_Skin : public FTableRowBase
{
	GENERATED_BODY()

	FDT_Skin() : ID_Material(0) { } 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ID")
	int32 ID_Material;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DESCRIPTION")
	FString Material_Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MATERIAL")
	TSoftObjectPtr<UMaterialInterface> MaterialSoftObjectPtr;

	UPROPERTY(EditAnywhere, Category="Mesh")
	TSoftObjectPtr<UStaticMesh> StaticMeshF;
	
};
