// Fill out your copyright notice in the Description page of Project Settings.

#include "Debug/DebugActor.h"

#include "NiagaraComponent.h"
#include "Data/FDT_Skin.h"

// Sets default values
ADebugActor::ADebugActor(): pBase_Mesh(nullptr), pCurveFloat(nullptr)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pBase_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base_Mesh"));
	RootComponent = pBase_Mesh;

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Niagara"));
	
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_Find(TEXT("/Game/Blueprint/Data/NewDataTable"));
	if (DT_Find.Succeeded())
	{
		DT_Skin = DT_Find.Object; 			
	}

}
	

// Called when the game starts or when spawned
void ADebugActor::BeginPlay()
{
	Super::BeginPlay();

	GetData();
}

void ADebugActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	
}

// Called every frame
void ADebugActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ADebugActor::GetData()
{
	if (DT_Skin.IsValid())
	{
		static const FString ContextString = FString("Material");
		FDT_Skin* Data_Skin = DT_Skin->FindRow<FDT_Skin>(FName(TEXT("M_Attack")), ContextString, true);
		if (Data_Skin != nullptr)
		{
			MaterialInterface = Data_Skin->MaterialSoftObjectPtr;
			UE_LOG(LogClass, Warning, TEXT("name: %s"), *MaterialInterface.ToSoftObjectPath().ToString())

			StreamableManager.RequestAsyncLoad(MaterialInterface.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ADebugActor::DataAssetDeferent));
		}
	}
	
}

void ADebugActor::DataAssetDeferent() const
{
	UMaterialInterface* p_MI = Cast<UMaterialInterface>(MaterialInterface.Get());
	if (p_MI != nullptr)
	{
		pBase_Mesh->GetStaticMesh()->SetMaterial(0, p_MI);
	}	
}




