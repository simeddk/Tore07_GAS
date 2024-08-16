#include "CBot.h"
#include "Perception/PawnSensingComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

ACBot::ACBot()
{
	PawnSesningComp = CreateDefaultSubobject<UPawnSensingComponent>("PawnSesningComp");
}

void ACBot::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	PawnSesningComp->OnSeePawn.AddDynamic(this, &ACBot::OnSeePawn);
}

void ACBot::OnSeePawn(APawn* Pawn)
{
	AAIController* AIC = GetController<AAIController>();
	if (ensure(AIC))
	{
		UBlackboardComponent* BBComp = AIC->GetBlackboardComponent();
		BBComp->SetValueAsObject("TargetActor", Pawn);

		DrawDebugString(GetWorld(), GetActorLocation(), "I found you!!", nullptr, FColor::White, 3.f, true);
	}
}
