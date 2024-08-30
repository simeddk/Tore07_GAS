#include "CChest.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

ACChest::ACChest()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);

	MaxPitch = 110.f;

	SetReplicates(true);
}

void ACChest::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACChest::Interact_Implementation(APawn* InstigatorPawn)
{
	bLidOpen = !bLidOpen;
}

void ACChest::OnRep_LidOpen()
{
	//Todo. bLidOpen에 따라 열리고 닫고
	LidMesh->SetRelativeRotation(FRotator(MaxPitch, 0, 0));
}

void ACChest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACChest, bLidOpen);
}